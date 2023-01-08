#include<iostream>
using namespace std;
#include<ctime>//随机时间种子

//学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
//设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
//学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
//最终打印出老师数据以及老师所带的学生数据。

//学生结构体定义
struct student {
	string name;//姓名
	int score;//成绩
};
//教师结构体
struct Teacher {
	string name;//教师姓名
	student arr[5];
};
//分配空间
void AllocateSpace(Teacher t[], int len) {//教师结构体数组 数据长度
	string tName = "教师";
	string sName = "学生";
	string nameSeed = "ABCDE";//姓名种子
	for (int i = 0; i < len; i++) {
		t[i].name = tName + nameSeed[i];
		for (int j = 0; j < 5; j++) {
			t[i].arr[j].name = sName + nameSeed[j];
			t[i].arr[j].score = rand() % 61 + 40;//rand()%61代表0-60之间的数据 +40则变成60-100

		}
	}

}
//打印信息
void PrintTeachers(Teacher t[], int len) {
	for (int i = 0; i < len; i++) {
		cout << t[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t姓名：" << t[i].arr[j].name << "\t成绩：" << t[i].arr[j].score << endl;
		}
	}
}

//案例一
void Case1() {
	//srand((unsigned int)time(NULL)); //随机数种子 头文件 #include <ctime>等价
	Teacher t[3];//老师数组
	int len = sizeof(t) / sizeof(Teacher);
	AllocateSpace(t, len);
	PrintTeachers(t, len);
}
