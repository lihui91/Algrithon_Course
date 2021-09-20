#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec;//存储文件中的数据
	ifstream infile;
	infile.open("data.txt");
	if (!infile.is_open())
	{
		cout << "file open failed!" << endl;
		exit(1);
	}
	int num;
	while (!infile.eof())
	{
		infile >> num;
		vec.push_back(num);
	}
	infile.close();
	ofstream outfile;
	outfile.open("output.txt");//将结果输出

	int  a[1000];
	a[0] = a[1] = 1;
	for (int j = 0; j < vec.size(); j++)
	{
		for (int i = 2; i <= vec[j]; i++)
		{
			if (i % 2 == 0)
				a[i] = a[i - 1] + a[i / 2];
			else
				a[i] = a[i - 1];
		}
		outfile << a[vec[j]]<<"  ";
	}
	outfile.close();
	return 0;
}