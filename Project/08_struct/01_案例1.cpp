#include<iostream>
using namespace std;
#include<ctime>//���ʱ������

//ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������
//���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա
//ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ
//���մ�ӡ����ʦ�����Լ���ʦ������ѧ�����ݡ�

//ѧ���ṹ�嶨��
struct student {
	string name;//����
	int score;//�ɼ�
};
//��ʦ�ṹ��
struct Teacher {
	string name;//��ʦ����
	student arr[5];
};
//����ռ�
void AllocateSpace(Teacher t[], int len) {//��ʦ�ṹ������ ���ݳ���
	string tName = "��ʦ";
	string sName = "ѧ��";
	string nameSeed = "ABCDE";//��������
	for (int i = 0; i < len; i++) {
		t[i].name = tName + nameSeed[i];
		for (int j = 0; j < 5; j++) {
			t[i].arr[j].name = sName + nameSeed[j];
			t[i].arr[j].score = rand() % 61 + 40;//rand()%61����0-60֮������� +40����60-100

		}
	}

}
//��ӡ��Ϣ
void PrintTeachers(Teacher t[], int len) {
	for (int i = 0; i < len; i++) {
		cout << t[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t������" << t[i].arr[j].name << "\t�ɼ���" << t[i].arr[j].score << endl;
		}
	}
}

//����һ
void Case1() {
	//srand((unsigned int)time(NULL)); //��������� ͷ�ļ� #include <ctime>�ȼ�
	Teacher t[3];//��ʦ����
	int len = sizeof(t) / sizeof(Teacher);
	AllocateSpace(t, len);
	PrintTeachers(t, len);
}
