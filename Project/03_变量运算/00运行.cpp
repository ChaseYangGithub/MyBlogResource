/*
变量运算
*/
#include<iostream>
using namespace std;
int main() {
	int a = 5;
	int b = 10;
	//算术运算符
	//简单四则运算
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;	//舍去除法的余数
	//取模
	cout << a % b<< endl;	//只保留除法的余数
	//递增递减 在前先运算后赋值 在后面先赋值在运算
	cout << a++ << endl;
	cout << ++a << endl;
	cout << b-- << endl;
	cout << --b << endl;

	
	//赋值运算符
	a += 2;
	cout <<a << endl;
	a -= 2;
	cout << a << endl; 
	a *= 2;
	cout << a << endl;	
	a /= 2;
	cout << a << endl;	
	a %= 2;
	cout << a << endl;	
	
	//比较运算符
	cout << (a == b)<< endl;
	cout << (a > b )<< endl;
	cout << (a < b) << endl;
	cout << (a != b) << endl;
	cout << (a >= b) << endl;
	cout << (a <= b) << endl;

	//逻辑运算符 ！非  ||或  &&与
	cout << (!a) << endl;
	cout << (a || b) << endl;
	cout << (a && b) << endl;


	return 0;
}