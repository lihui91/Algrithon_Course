#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
/*
1����������
2����̬�滮
*/
void MaxSum(int n, vector<int>a)//��̬�滮���
{
	int sum = 0;//����Ӷκ�
	int b = 0;//�ֲ��Ӷκ�
	int begin=0;//����Ӷ���ʼ��
	int end=0;//����Ӷ���ֹ��
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
	cout << "����Ӷκ�Ϊ��" << sum << endl;
	cout << "����ֶ�Ϊ��[";
	for (int i = begin; i < end; i++)
	{
		cout << a[i] << ',';
	}
	cout << a[end] << ']' << endl;
}

vector<int> preStep() {//Ԥ����
	ifstream infile;
	infile.open("input.txt");//�����ļ�
	if (!infile.is_open())
	{
		cout << "file opend failed!" << endl;
		exit(-1);
	}

	
	vector<int>num;//�洢�ļ��е�����
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