/*
��������
*/
#include<iostream>
using namespace std;
int main() {
	int a = 5;
	int b = 10;
	//���������
	//����������
	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;	//��ȥ����������
	//ȡģ
	cout << a % b<< endl;	//ֻ��������������
	//�����ݼ� ��ǰ�������ֵ �ں����ȸ�ֵ������
	cout << a++ << endl;
	cout << ++a << endl;
	cout << b-- << endl;
	cout << --b << endl;

	
	//��ֵ�����
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
	
	//�Ƚ������
	cout << (a == b)<< endl;
	cout << (a > b )<< endl;
	cout << (a < b) << endl;
	cout << (a != b) << endl;
	cout << (a >= b) << endl;
	cout << (a <= b) << endl;

	//�߼������ ����  ||��  &&��
	cout << (!a) << endl;
	cout << (a || b) << endl;
	cout << (a && b) << endl;


	return 0;
}