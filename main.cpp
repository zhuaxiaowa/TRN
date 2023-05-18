#include <iostream>
#include <fstream>
#include <string>

/*
* ��飺�Ӷ�ά�������ҳ���㣨������Χ�ĵ㣩����Χ�ĵ㲻���жϡ�
* 1�����ļ�
* 2��ʹ�ö�ά������ļ��ж�ȡ����
* 3��д����ж�function
* 4��������ά���飬�����㺯���������㡣
* 1
* 5���ر��ļ���
*/
using namespace std;

/*
����жϺ���,�жϷ����������
*/
bool isPeak(int map[64][64], int i,int j) {
	if ((map[i-1][j] < map[i][j]) && 
		(map[i][j + 1] < map[i][j]) &&
		(map[i + 1][j] < map[i][j])&&
		(map[i][j - 1] < map[i][j])
		) {
		return true;
	}
	return false;
}

int main(void)
{
	int nrows, ncols;
	int map[64][64];
	string fileName;
	ifstream file;
	
	cout << "�������ļ�����" << endl;
	cin >> fileName;

	// 1,���ļ�
	file.open(fileName.c_str());
	if (file.fail()) {
		cout << "�ļ��������" << endl;
		exit(1);
	}

	file >> nrows >> ncols;

	if (nrows > 64 || ncols >64) {
		cout << "�������̫��" << endl;
		exit(1);
	}
	
	// 2,���ļ��еĶ�ά����ȡ����
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			file>>map[i][j];
		}
	}

	// 3,�ж�����������Щ��㲢�����������������Ȧ�����ж�
	for (int i = 1; i < nrows - 1; i++) {
		for (int j = 1; j < ncols - 1; j++) {
			if (isPeak(map, i, j)) {
				cout << "���Ϊ��" << map[i][j] << " �У�" << i << " �У� " << j << endl;
			}
		}
	}

	// 4���ر��ļ�
	file.close();

	return 0;
}