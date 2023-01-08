#include<iostream>
using namespace std;
#include "函数.h"
int main() {
	//加法定义
	int a = 3, b = 5;
	//int c=Add(a,b);	//函数加法 ,调用时的a，b称为实际参数，简称实参
	//cout << "a+b=" << c << endl;
	
	//数值交换 - 伪
	Swap(a, b);	// 值传递时，形参是修饰不了实参的
	cout << a << endl;
	cout << b << endl;


	system("pause");
	return 0;
}