#include<iostream>
using namespace std;
void ChooseStruct(){
	int score = 720;
	//if��� --�ɼ�����600���ϱ���
	/*cout << "���������";
	cin >> score;*/
	if (score > 600) {
		cout << "01����ѧУ" << endl;
	}

	//����if���--
	if (score > 600) {
		cout << "����ѧУΪһ��" << endl;
	}
	else {
		cout << "02���" << endl;
	}

	//������if���
	if (score > 700) {
		cout << "�ص�һ��" << endl;
	}
	else if (score > 600) {
		cout << "����һ������" << endl;
	}
	else {
		cout << "�������" << endl;
	}

	//��Ŀ�����
	int a = 10, b = 20, c = 30;
	int d;
	d = a > b ? a : b;	//����a>b ֵ Ϊa ����Ϊb
	cout << "d=" << d << endl;

	//switch���
	int evalue = 3;
	switch (evalue) {
	case 10:
		cout << "����" << endl;
		break;
	case 9:
		cout << "��ɫ" << endl;
		break;
	default:
		cout << "һ��" << endl;
		break;
	}
}