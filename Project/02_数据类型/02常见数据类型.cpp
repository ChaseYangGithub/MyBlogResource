#include<iostream>
#include<string>	//�ַ������
using namespace std;
void DataType() {
	//������
	float f1 = 3.14;	//��ü���f��˫�������ֿ�
	//˫����
	double d = 4.224;
	cout << "float:" << f1 << endl;
	cout << "double:" << d << endl;

	//��ѧ������
	float f3 = 3e2;		//3*10^2
	float f4 = 4e-3;	//4*0.1^3
	cout << "f3:" << f3 << endl;
	cout << "f4:" << f4 << endl;

	//�ַ���
	char c = 'A';	//�洢���Ƕ�Ӧ��ACSCIIֵ
	cout << "char c:" << c << endl;
	cout << "char:" << sizeof(c) <<endl;

	//ǿ��ת��
	cout << (int)c << endl;
	
	//ת���ַ�
	//\n����
	cout << "����\n";
	//\tˮƽ�Ʊ�� һ������8���ַ�λ�ã���ǰ����ַ������Ʊ����8��,��ǰ�����8����ֱ�ӿ�8��
	cout << "a\taaa" << endl;
	cout << "aaaa\taaa" << endl;
	cout << "aaaaaa\taaa" << endl;
	cout << "aaaaaaaa\taaa" << endl;

	//�ַ���
	//C����ַ���
	char str[] = "hello C++";
	cout << str << endl;
	//C++���
	string  str2 = "hello C++";
	cout << str2 << endl;

	//��������  ��Ϊ0 ����Ϊ��
	bool state = true;
	cout << state << endl;

	//��������
	int a;
	cin >> a;
	cout << "�������ݣ�"<<a << endl;
}