#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
/*
1、导入数据
2、动态规划
*/
void MaxSum(int n, vector<int>a)//动态规划求解
{
	int sum = 0;//最大子段和
	int b = 0;//局部子段和
	int begin=0;//最大子段起始处
	int end=0;//最大子段终止处
	for (int i = 0; i < n; i++)
	{
		if (b > 0) {
			b += a[i];
		}
		else {
			b = a[i];
			begin = i;
		}
		if (b > sum) {
			sum = b;
			end = i;
		}
	}
	cout << "最大子段和为：" << sum << endl;
	cout << "最大字段为：[";
	for (int i = begin; i < end; i++)
	{
		cout << a[i] << ',';
	}
	cout << a[end] << ']' << endl;
}

vector<int> preStep() {//预处理
	ifstream infile;
	infile.open("input.txt");//导入文件
	if (!infile.is_open())
	{
		cout << "file opend failed!" << endl;
		exit(-1);
	}

	
	vector<int>num;//存储文件中的数据
	char h;
	int arr[255];
	int j = 0;
	while (infile >> h >> arr[j])
	{
		j = j + 1;
	}
	for (int i = 0; i < j; i++)
	{
		num.push_back(arr[i]);
	}
	cout << '[';
	for (int i = 0; i < num.size() - 1; i++)
	{
		cout << num[i] << ',';
	}
	cout << num[num.size() - 1] << ']' << endl;
	cout << endl;
	return num;
}

int main()
{
	vector<int>Num;
	Num = preStep();
	MaxSum(Num.size(), Num);
	return 0;
}