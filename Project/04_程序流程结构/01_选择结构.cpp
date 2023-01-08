#include<iostream>
using namespace std;
void ChooseStruct(){
	int score = 720;
	//if语句 --成绩大于600考上本科
	/*cout << "输入分数：";
	cin >> score;*/
	if (score > 600) {
		cout << "01考上学校" << endl;
	}

	//多行if语句--
	if (score > 600) {
		cout << "考上学校为一本" << endl;
	}
	else {
		cout << "02落榜" << endl;
	}

	//多条件if语句
	if (score > 700) {
		cout << "重点一本" << endl;
	}
	else if (score > 600) {
		cout << "考上一本有望" << endl;
	}
	else {
		cout << "不幸落榜" << endl;
	}

	//三目运算符
	int a = 10, b = 20, c = 30;
	int d;
	d = a > b ? a : b;	//条件a>b 值 为a 否则为b
	cout << "d=" << d << endl;

	//switch语句
	int evalue = 3;
	switch (evalue) {
	case 10:
		cout << "完美" << endl;
		break;
	case 9:
		cout << "出色" << endl;
		break;
	default:
		cout << "一般" << endl;
		break;
	}
}