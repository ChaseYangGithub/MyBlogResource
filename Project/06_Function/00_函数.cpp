#include<iostream>
using namespace std;
//����ֵ���� ������ �������б�
//{
//
//       ���������
//
//       return���ʽ
//
//}

//�ӷ�����
int Add(int num1,int  num2) {//�����е�num1,num2��Ϊ��ʽ����������β�
	return num1 + num2;
}

//��ֵ����-/-α
void Swap(int num1, int num2) {
	//ֵ����ʱ���β������β���ʵ�ε�
	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;
	cout << num1 << endl;
	cout << num2 << endl;
}