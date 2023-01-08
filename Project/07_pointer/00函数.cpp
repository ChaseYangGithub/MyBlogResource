#include<iostream>
using namespace std;
#include "00_函数.h"
//指针
//可以通过指针间接访问内存
//* 内存编号是从0开始记录的，一般用十六进制数字表示
//* 可以利用指针变量保存地址
void Pointer() {
	int a = 10;

	//指针定义语法： 数据类型 * 变量名 ;
	int * p;
	//指指向变量a的地址
	p = &a;
	cout << &a << endl;
	cout << p << endl;

	//通过*操作指针变量指向的内存空间
	cout << "*p=" << *p << endl;
	/*
	普通变量存放的是数据, 指针变量存放的是地址
	 指针变量可以通过" * "操作符，操作指针变量指向的内存空间，这个过程称为解引用

	总结1： 我们可以通过 & 符号 获取变量的地址

	总结2：利用指针可以记录地址

	总结3：对指针变量解引用，可以操作指针指向的内存
	*/
	
	cout << "指针所占的内存空间" << endl;
	//指针所占据的内存空间   所有指针类型在32位操作系统下是4个字节
	cout << "int=" << sizeof(p) << endl;
	cout << "char=" << sizeof(char*) << endl;
	cout << "float:" << sizeof(float*) << endl;
	cout << "long:" << sizeof(long*) << endl;


	/*
	空指针 ：指针变量指向内存中编号为0的空间

	用途：初始化指针变量

	注意：空指针指向的内存是不可以访问的
	*/
	cout << "空指针" << endl;
	int* q = NULL;
	//cout << *q << endl;	//此处直接报错，不允许访问
	//野指针 ：指针变量指向非法的内存空间
	q = (int*)0x1100;
	/*cout << *q << endl;*/
}	

//const修饰的指针
void ConstPointer() {
	/*
	const修饰指针有三种情况

		1. const修饰指针-- - 常量指针
		2. const修饰常量-- - 指针常量
		3. const即修饰指针，又修饰常量
		*/
	//看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量
	int a = 10;
	int b = 10;

	//const修饰的是指针，指针指向可以改，指针指向的值不可以更改
	const int* p1 = &a;
	p1 = &b; //正确
	//*p1 = 100;  报错


	//const修饰的是常量，指针指向不可以改，指针指向的值可以更改
	int* const p2 = &a;
	//p2 = &b; //错误
	*p2 = 100; //正确

	//const既修饰指针又修饰常量
	const int* const p3 = &a;
	//p3 = &b; //错误
	//*p3 = 100; //错误
}

//利用指针访问数组元素
void PointerArr() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;	//指向数组的指针
	cout << "第一个元素：" << arr[0] << endl;
	cout << "指针访问的第一个元素：" << *p << endl;

	//指针遍历数组
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout << *p << "\t";
		p++;
	}
}

//利用指针函数数值互换
void Temp() {
	int a = 1;
	int b = 2;
	Swap(&a, &b);//地址传递会改变实参
	cout << a << endl;
	cout << b << endl;
}
//数据交换测试
void Swap(int* a,int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//如果不想修改实参，就用值传递，如果想修改实参，就用地址传递


//封装一个函数，利用冒泡排序，实现对整型数组的升序排序
//例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
void BubbleSortTest() {
	int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	BubbleSort(arr, sizeof(arr) / sizeof(int)); //总结：当数组名传入到函数作为参数时，被退化为指向首元素的指针
	//指针遍历数组
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		cout <<arr[i] << "\t";
	}
}

//冒泡排序
void BubbleSort(int *arr,int len) {

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len-1-i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

