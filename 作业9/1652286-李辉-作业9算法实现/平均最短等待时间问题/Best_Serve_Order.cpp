#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;


//平均最小等待时间
double min_avg(vector<int>client, int num)//客户信息，服务场所数目
{
	vector<int>service(num+1, 0);       //服务窗口每一个顾客等待的时间
	vector<int>sum(num+1, 0);          //服务窗口顾客等待的时间总和
	int n = client.size();

	sort(client.begin(), client.end());
	int i = 0, j = 0;
	while (i < n)
	{
		service[j] += client[i];

		sum[j] += service[j];
		i++;
		j++;
		if (j == num) j = 0;         //注意，j==num，不是num-1，因为j++在后
	}
	double t = 0;
	for (i = 0; i < num; i++)//计算所有窗口时间服务总和
		t += sum[i];
	return t / n;

}

int main()
{
	ifstream infile;
	infile.open("input.txt");
	int client_num, district_num;//客户数，服务区数目
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

	cout << "平均最小等待时间：" << endl;
	outfile << min_avg(client, district_num) << endl;
	cout<< min_avg(client, district_num) << endl;
	return 0;
}	