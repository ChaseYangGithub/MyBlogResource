#include<iostream>
#include<string>	//字符串相关
using namespace std;
void DataType() {
	//单精度
	float f1 = 3.14;	//最好加上f和双精度区分开
	//双精度
	double d = 4.224;
	cout << "float:" << f1 << endl;
	cout << "double:" << d << endl;

	//科学计数法
	float f3 = 3e2;		//3*10^2
	float f4 = 4e-3;	//4*0.1^3
	cout << "f3:" << f3 << endl;
	cout << "f4:" << f4 << endl;

	//字符型
	char c = 'A';	//存储的是对应的ACSCII值
	cout << "char c:" << c << endl;
	cout << "char:" << sizeof(c) <<endl;

	//强制转换
	cout << (int)c << endl;
	
	//转义字符
	//\n换行
	cout << "换行\n";
	//\t水平制表符 一个代表8个字符位置，其前面的字符加上制表符共8个,若前面大于8个则直接空8个
	cout << "a\taaa" << endl;
	cout << "aaaa\taaa" << endl;
	cout << "aaaaaa\taaa" << endl;
	cout << "aaaaaaaa\taaa" << endl;

	//字符串
	//C风格字符串
	char str[] = "hello C++";
	cout << str << endl;
	//C++风格
	string  str2 = "hello C++";
	cout << str2 << endl;

	//布尔类型  假为0 非零为真
	bool state = true;
	cout << state << endl;

	//数据输入
	int a;
	cin >> a;
	cout << "整形数据："<<a << endl;
}