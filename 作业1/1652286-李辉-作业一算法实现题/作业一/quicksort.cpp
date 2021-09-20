#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

//øÏÀŸ≈≈–Ú
int Paritition1(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot) {
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int A[], int low, int high) //øÏ≈≈ƒ∏∫Ø ˝
{
	if (low < high) {
		int pivot = Paritition1(A, low, high);
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot + 1, high);
	}
}

//πÈ≤¢≈≈–Ú

void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = new int[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

//√∞≈›≈≈–Ú

void bubble_sort(int arr[], int len) {
        int i, j;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (arr[j] > arr[j + 1])
                                swap(arr[j], arr[j + 1]);
}

int main()
{
	int i = 0;
	char h;
	int array[10000];
	ifstream infile;
	infile.open("1.txt");
	if (!infile.is_open())
	{
		cout << "file open failed!" << endl;
		exit(1);
	}
	while (infile >> array[i] >> h)
	{
		i = i + 1;
	}
	infile.close();
	
	double start,finish;
	start=(double)clock();
	
	/*QuickSort(array, 0, 9999);*/
	
	/*merge_sort(array,10000);*/
	
	bubble_sort(array,10000);
	finish=(double)clock();
	
	for (int j = 0; j < 10000; j++)
		cout << array[j] << ' ';
	cout << endl;
	cout<<endl;
	printf("1.txt--√∞≈›≈≈–Ú ±º‰Œ™£∫%.4fms\n", (finish - start));
	return 0;
}
