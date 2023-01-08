/*
初次学习C++
*/
#include<iostream>	//此处是单行注释 ：
#include "00_程序.h"
using namespace std;	//引用命名空间 标准（std）
//一般在开发过程中尽量避免使用这种直接引入整个命名空间的方式，一般使用std::cout  std::endl这种方式
//避免自定义函数与标准函数名冲突
 void HelloWorld() {
	cout << "Hello World" << endl;	//命名空间std的endl实现输出一个换行符并立即刷新缓冲区

}