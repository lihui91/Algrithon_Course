/*1652286 李辉*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define MAX 2000

/*备忘录准备*/
int B[MAX][MAX] = { 0 };//保存矩阵链相乘最小结果
int S[MAX][MAX] = { 0 };//记录最小代价B[i,j]对应的分割点

/*计算n元矩阵p的最优代价，动态规划的每一步结果储存到B和S中*/
void MatrixOrder(vector<int>p, int n) {
	for(int l=2;l<=n;l++)//矩阵链长度从2到n
		for (int i = 1; i <= n - l + 1; i++)//讨论长度为l的矩阵链A[i...j]
		{
			int j = i + l - 1;
			B[i][j] = INT_MAX;
			for (int temp, d = i; d < j; d++) {//d为分割点
				temp = B[i][d] + B[d + 1][j] + p[i - 1] * p[d] * p[j];
				if (temp < B[i][j])//记录矩阵A[i...j]最小的情况
				{
					B[i][j] = temp;
					S[i][j] = d;
				}
			}
		}
}

void PrintOrder(int i, int j) {//打印函数
	if (i == j)
		cout << 'A' << i;
	else {
		int d = S[i][j];
		cout << '(';
		PrintOrder(i, d);
		PrintOrder(d + 1, j);
		cout << ')';
	}
}

int main() {
	int n;
	vector<int>p;
	ifstream infile;
	infile.open("input.txt");
	while (!infile.is_open())
	{
		cout << "file open failed!" << endl;
		exit(1);
	}
	while (!infile.eof()) {
		cout << "INPUT:" << endl;
		infile >> n;
		cout << n << endl;
		int *arr = new int[2*n];
		for (int i = 0; i < 2 * n; i++)
		{
			infile >> arr[i];
		}
		for (int i = 0; i < 2 * n-1; i=i+2)
		{
			cout << arr[i] <<' ' << arr[i + 1] << endl;
		}
		p.push_back(arr[0]);
		for (int i = 1; i < 2 * n; i++)
		{
			if (arr[i] != arr[i - 1])
				p.push_back(arr[i]);
		}
		MatrixOrder(p, n);
		cout << "OUTPUT:" << endl;
		PrintOrder(1, n);
		cout << endl;
		cout << endl;
	}
	infile.close();
	return 0;
}