#include <iostream>
#include <fstream>
#include <string>

/*
* 简介：从二维数组中找出峰点（大于周围的点），外围的点不用判断。
* 1，打开文件
* 2，使用二维数组从文件中读取数据
* 3，写峰点判断function
* 4，遍历二维数组，带入峰点函数，输出峰点。
* 1
* 5，关闭文件。
*/
using namespace std;

/*
峰点判断函数,判断峰点上下左右
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
	
	cout << "请输入文件名：" << endl;
	cin >> fileName;

	// 1,打开文件
	file.open(fileName.c_str());
	if (file.fail()) {
		cout << "文件输入错误！" << endl;
		exit(1);
	}

	file >> nrows >> ncols;

	if (nrows > 64 || ncols >64) {
		cout << "网格面积太大！" << endl;
		exit(1);
	}
	
	// 2,将文件中的二维数组取出来
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			file>>map[i][j];
		}
	}

	// 3,判断数组中有哪些峰点并输出出来，数组最外圈不必判断
	for (int i = 1; i < nrows - 1; i++) {
		for (int j = 1; j < ncols - 1; j++) {
			if (isPeak(map, i, j)) {
				cout << "峰点为：" << map[i][j] << " 行：" << i << " 列： " << j << endl;
			}
		}
	}

	// 4，关闭文件
	file.close();

	return 0;
}