#include<iostream>
using namespace std;
#include "����.h"
int main() {
	//�ӷ�����
	int a = 3, b = 5;
	//int c=Add(a,b);	//�����ӷ� ,����ʱ��a��b��Ϊʵ�ʲ��������ʵ��
	//cout << "a+b=" << c << endl;
	
	//��ֵ���� - α
	Swap(a, b);	// ֵ����ʱ���β������β���ʵ�ε�
	cout << a << endl;
	cout << b << endl;


	system("pause");
	return 0;
}