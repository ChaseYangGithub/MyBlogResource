#include<iostream>
using namespace std;
//���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�; �����ṹ�����飬�����д��5��Ӣ�ۡ�
//ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
//{"����", 23, "��"},
//{ "����",22,"��" },
//{ "�ŷ�",20,"��" },
//{ "����",21,"��" },
//{ "����",19,"Ů" },

//Ӣ�۽ṹ��
struct Hero {
	string name;//Ӣ������
	int age;//Ӣ������
	string sex;//Ӣ���Ա�
};

//ð������--��������
void BubbleSort(Hero hero[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (hero[j].age > hero[j + 1].age) {
				Hero temp = hero[j];
				hero[j] = hero[j + 1];
				hero[j + 1] = temp;

			}
		}
	}
}

//��ӡ����
void PrintHero(Hero hero[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "������" << hero[i].name << "\t���䣺" << hero[i].age << "\t�Ա�" << hero[i].sex << endl;
	}
}

//����2
void Case2() {
	Hero hero[] = {
		{"����", 23, "��"},
		{ "����",22,"��" },
		{ "�ŷ�",20,"��" },
		{ "����",21,"��" },
		{ "����",19,"Ů" }
	};
	int len = sizeof(hero) / sizeof(Hero);
	BubbleSort(hero, len);
	PrintHero(hero, len);
}