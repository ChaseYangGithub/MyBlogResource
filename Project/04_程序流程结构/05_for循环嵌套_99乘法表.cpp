#include<iostream>
using namespace std;

//使用for循环打印九九乘法表
void NineNineMultipleTable() {
	for (int i = 1; i <= 9; i++) {//行
		for (int j = 1; j <= i; j++) {//列
			cout << i <<"*"<<j<<"=" << i * j<<"\t";
		}
		cout << endl;
	}
}