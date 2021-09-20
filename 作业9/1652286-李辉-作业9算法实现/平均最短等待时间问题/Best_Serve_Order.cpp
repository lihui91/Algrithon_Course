#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;


//ƽ����С�ȴ�ʱ��
double min_avg(vector<int>client, int num)//�ͻ���Ϣ����������Ŀ
{
	vector<int>service(num+1, 0);       //���񴰿�ÿһ���˿͵ȴ���ʱ��
	vector<int>sum(num+1, 0);          //���񴰿ڹ˿͵ȴ���ʱ���ܺ�
	int n = client.size();

	sort(client.begin(), client.end());
	int i = 0, j = 0;
	while (i < n)
	{
		service[j] += client[i];

		sum[j] += service[j];
		i++;
		j++;
		if (j == num) j = 0;         //ע�⣬j==num������num-1����Ϊj++�ں�
	}
	double t = 0;
	for (i = 0; i < num; i++)//�������д���ʱ������ܺ�
		t += sum[i];
	return t / n;

}

int main()
{
	ifstream infile;
	infile.open("input.txt");
	int client_num, district_num;//�ͻ�������������Ŀ
	infile >> client_num >> district_num;
	vector<int>client;
	int service_time;
	for (int i = 0; i < client_num; i++)
	{
		infile >> service_time;
		client.push_back(service_time);
	}
	infile.close();
	ofstream outfile;
	outfile.open("output.txt");

	cout << "ƽ����С�ȴ�ʱ�䣺" << endl;
	outfile << min_avg(client, district_num) << endl;
	cout<< min_avg(client, district_num) << endl;
	return 0;
}	