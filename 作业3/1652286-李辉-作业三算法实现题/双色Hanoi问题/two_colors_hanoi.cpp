#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
ofstream outfile("output.txt");//д�뷽ʽ��output.txt,ȫ�ֱ���
void two_colors_hanoi(int n,char a,char c,char b)//��n������a�Ƶ�b��c��Ϊ������
{
	
	if (n == 1)
		outfile << n << ' ' << a << ' '<<b << endl;//�����һ����a�Ƶ�b
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
	infile.open("input.txt");//�򿪲��������ļ�
	if (!infile.is_open())
	{
		cout << "file open failed!" << endl;//��ʧ���˳�
		exit(1);
	}
	int n;
	while (!infile.eof())
	{
		infile >> n;
		vec.push_back(n);
	}
	infile.close();
	
	for (int i = 0; i < vec.size(); i++)//����
	{
		outfile << "n=" << vec[i] << ':' << endl;
		two_colors_hanoi(vec[i], 'A', 'C', 'B');//�ݹ�
		outfile << endl << endl << endl;
	}
	outfile.close();
	return 0;
}