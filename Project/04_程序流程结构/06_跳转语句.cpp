#include<iostream>
using namespace std;
//��ת���
void JumpStatement() {
	//break 
	//������switch��������У���������ֹcase������switch
	//������ѭ������У�������������ǰ��ѭ�����
	//������Ƕ��ѭ���У�����������ڲ�ѭ�����

	//continue
	//��ѭ������У���������ѭ����������δִ�е���䣬����ִ����һ��ѭ��
	//continue��û��ʹ����ѭ����ֹ����break������ѭ��
	for (int i = 0; i < 10; i++) {
		if (i == 5) {	//����iΪ5�����
			continue;
		}
		cout << i << "\t";
	}

	//goto���
	//�ڳ����в�����ʹ��goto��䣬������ɳ������̻���
	cout << "\ngoto---" << endl;	
	cout << "1" << endl;
	goto FLAG;	//��ת����ǵ�
	cout << "2" << endl;
	cout << "3" << endl;
FLAG:
	cout << "flag!" << endl;

 }