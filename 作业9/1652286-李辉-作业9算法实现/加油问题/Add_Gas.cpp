#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int n, k;                  //n代表汽车加满油可行驶n千米，k代表有几个加油站 

	ifstream infile;
	infile.open("input.txt");
	infile >> n >> k;
	int *p = new int[k + 1];
	int *stop = new int[k + 1];       //p数组代表各加油站之间距离，s数组代表在哪一站加油 
	int i, s = 0, num = 0;          //num代表加油次数 
	for (i = 0; i < k + 1; i++) {       //各加油站之间的距离 
		infile >> p[i];
		stop[i] = 0;
	}
	infile.close();
	for (i = 0; i < k + 1; i++) {       //尽量加一次油，多行驶几个站，如果油不够，则停下加油 
		s += p[i];
		if (s <= n) {
			continue;
		}
		else {
			num++;
			s = 0;
			stop[i] = 1;//第i个加油站加了油
			i--;
		}
	}
	/*cout << "输入：" << endl;
	cout << n << "  " << k << endl;
	for (i = 0; i < k + 1; i++)
	{
		cout << p[i] << "	";
	}
	cout << endl << endl;*/

	ofstream outfile;
	outfile.open("output.txt");
	outfile << num << endl;
	outfile.close();
	/*cout << "加了" << num << "次油" << endl;
	cout << "加油的站点为：" << endl;
	for (i = 0; i < k + 1; i++) {
		if (stop[i] == 1) {
			cout << i << "	";
		}
	}
	cout << endl;*/

	return 0;
}