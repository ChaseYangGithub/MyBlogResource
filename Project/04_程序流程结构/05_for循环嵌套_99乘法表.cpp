#include<iostream>
using namespace std;

//ʹ��forѭ����ӡ�žų˷���
void NineNineMultipleTable() {
	for (int i = 1; i <= 9; i++) {//��
		for (int j = 1; j <= i; j++) {//��
			cout << i <<"*"<<j<<"=" << i * j<<"\t";
		}
		cout << endl;
	}
}