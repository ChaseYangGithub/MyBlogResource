#include<iostream>
using namespace std;
#include "00_����.h"
//�ṹ�嶨��
struct student {
	string name;	//����
	int age;	//����
	int score;	//�ɼ�
}stu3;//	�ṹ�����������ʽ3

//�ṹ��Ķ���
void StructD() {
	//�ṹ�������û��Զ�����������ͣ������û��洢��ͬ����������
	//�﷨�� struct �ṹ����{ �ṹ���Ա�б� }��
	//	ͨ���ṹ�崴�������ķ�ʽ�����֣�
	//	1  struct �ṹ���� ������
	//	2  struct �ṹ���� ������ = { ��Ա1ֵ �� ��Ա2ֵ... }
	//	3  ����ṹ��ʱ˳�㴴������



	//�ṹ����������ʽ1
	struct student stu1;	//struct����ʡ��

	stu1.age = 18;
	stu1.name = "����";
	stu1.score = 100;

	cout << "������" << stu1.name << "���䣺" << stu1.age << "�ɼ�:" << stu1.score << endl;

	//�ṹ�����������ʽ2
	struct student stu2 = { "����",19,80 };
	cout << "������" << stu2.name << "���䣺" << stu2.age << "�ɼ���" << stu2.score << endl;

	//
	stu3.name = "����";
	stu3.age = 23;
	stu3.score = 90;
	cout << "������" << stu3.name << "���䣺" << stu3.age << "�ɼ���" << stu3.score << endl;

}
//> �ܽ�1������ṹ��ʱ�Ĺؼ�����struct������ʡ��
//> �ܽ�2�������ṹ�����ʱ���ؼ���struct����ʡ��
//> �ܽ�3���ṹ��������ò����� ''.''  ���ʳ�Ա

//�ṹ������
//���Զ���Ľṹ����뵽�����з���ά��
//�﷨��struct  �ṹ���� ������[Ԫ�ظ���] = { {} , {} , ... {} }
void StructArr() {
	//�ṹ������
	struct student arr[3] = {
		{"����",14,100},
		{"����",18,80},
		{"����",23,90}
	};
	for (int i = 0; i < sizeof(arr) / sizeof(student); i++) {
		cout << "������" << arr[i].name << " ���䣺" << arr[i].age << " �ɼ���" << arr[i].score << endl;
	}
}

//�ṹ��ָ��
//����:ͨ��ָ����ʽṹ���еĳ�Ա
//���ò����� -> ����ͨ���ṹ��ָ����ʽṹ������
void StructPointer() {
	struct student stu = { "chase",23,120 };
	struct student* p = &stu;
	p->score = 130;	//ָ��ͨ��->���������Է��ʳ�Ա
	cout << "������" << p->name << " ���䣺" << p->age << " �ɼ���" << p->score << endl;
}

//�ṹ��Ƕ��  
//�ڽṹ���п��Զ�����һ���ṹ����Ϊ��Ա���������ʵ������
void StructNesting() {
	//��ʦ�ṹ�嶨��
	struct Teacher {
		//��Ա�б�
		int id;//ְ�����
		string name;//��ʦ����
		int age;//��ʦ����
		struct student stu;//�ӽṹ�� ѧ��

	};
	struct Teacher t1;
	t1.id = 10000;
	t1.name = "����ʢ";
	t1.age = 45;
	t1.stu.name = "chase";
	t1.stu.age = 23;
	t1.stu.score = 120;
	cout << "��ʦ ְ����ţ�" << t1.id << " ������" << t1.name << "���䣺" <<t1.age<< endl;
	cout << "����ѧ�� ������" << t1.stu.name << " ���䣺" << t1.stu.age << " �ɼ���" << t1.stu.score << endl;
}


//ֵ����
void PStudent(student stu) {
	stu.age = 34;
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
}
//��ַ����
void PStudent2(student* stu) {
	stu->name = "chase";
	stu->age = 21;
	stu->score = 123;
	cout << stu->name << " " << stu->age << " " << stu->score << endl;
}
//�ṹ�庯������ 
//��������޸��������е����ݣ���ֵ���ݣ���֮�õ�ַ����
void StructParameter() {
	student stu = { "����",17,100 };
	PStudent(stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	PStudent2(&stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
}

//�ṹ��ʹ��const
//ʹ��const����ֹ�����
void printStudent(const student* stu) //��const��ֹ�������е������
{
	//stu->age = 100; //����ʧ�ܣ���Ϊ����const����
	cout << "������" << stu->name << " ���䣺" << stu->age << " ������" << stu->score << endl;

}

