#include<iostream>
using namespace std;
//返回值类型 函数名 （参数列表）
//{
//
//       函数体语句
//
//       return表达式
//
//}

//加法函数
int Add(int num1,int  num2) {//定义中的num1,num2称为形式参数，简称形参
	return num1 + num2;
}

//数值交换-/-伪
void Swap(int num1, int num2) {
	//值传递时，形参是修饰不了实参的
	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;
	cout << num1 << endl;
	cout << num2 << endl;
}