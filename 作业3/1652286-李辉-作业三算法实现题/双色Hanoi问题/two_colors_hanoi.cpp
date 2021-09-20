#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ofstream outfile("output.txt");//写入方式打开output.txt,全局变量
void two_colors_hanoi(int n,char a,char c,char b)//将n个盘由a移到b，c作为过渡柱
{
	
	if (n == 1)
		outfile << n << ' ' << a << ' '<<b << endl;//将最后一个由a移到b
	else
	{
		two_colors_hanoi(n - 1, a, b, c);
		outfile << n << ' ' << a << ' ' << b << endl;
		two_colors_hanoi(n - 1, c, a, b);
	}
}
int main()
{
	vector<int> vec;
	ifstream infile;
	infile.open("input.txt");//打开测试数据文件
	if (!infile.is_open())
	{
		cout << "file open failed!" << endl;//打开失败退出
		exit(1);
	}
	int n;
	while (!infile.eof())
	{
		infile >> n;
		vec.push_back(n);
	}
	infile.close();
	
	for (int i = 0; i < vec.size(); i++)//迭代
	{
		outfile << "n=" << vec[i] << ':' << endl;
		two_colors_hanoi(vec[i], 'A', 'C', 'B');//递归
		outfile << endl << endl << endl;
	}
	outfile.close();
	return 0;
}