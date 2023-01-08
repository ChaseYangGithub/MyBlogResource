#include<iostream>
using namespace std;
//敲黑板：从1开始数到数字100， 如果数字个位含有7，或者数字十位含有7，或者该数字是7的倍数，我们打印敲桌子，
//其余数字直接打印输出。
// for(起始表达式;条件表达式;末尾循环体) { 循环语句; }
void Knock() {
	for (int i = 1; i <=100; i++) {
		if (i / 10 == 7 || i % 10 == 7 || i % 7 == 0) {
			cout << "\nknock" << endl;
		}
		else {
			cout << i << "，";
		}

	}
}