#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int n, k;                  //n�������������Ϳ���ʻnǧ�ף�k�����м�������վ 

	ifstream infile;
	infile.open("input.txt");
	infile >> n >> k;
	int *p = new int[k + 1];
	int *stop = new int[k + 1];       //p������������վ֮����룬s�����������һվ���� 
	int i, s = 0, num = 0;          //num������ʹ��� 
	for (i = 0; i < k + 1; i++) {       //������վ֮��ľ��� 
		infile >> p[i];
		stop[i] = 0;
	}
	infile.close();
	for (i = 0; i < k + 1; i++) {       //������һ���ͣ�����ʻ����վ������Ͳ�������ͣ�¼��� 
		s += p[i];
		if (s <= n) {
			continue;
		}
		else {
			num++;
			s = 0;
			stop[i] = 1;//��i������վ������
			i--;
		}
	}
	/*cout << "���룺" << endl;
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
	/*cout << "����" << num << "����" << endl;
	cout << "���͵�վ��Ϊ��" << endl;
	for (i = 0; i < k + 1; i++) {
		if (stop[i] == 1) {
			cout << i << "	";
		}
	}
	cout << endl;*/

	return 0;
}