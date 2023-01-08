#include<iostream>
using namespace std;
#include "00_函数.h"
//结构体定义
struct student {
	string name;	//姓名
	int age;	//年龄
	int score;	//成绩
}stu3;//	结构体变量创建方式3

//结构体的定义
void StructD() {
	//结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
	//语法： struct 结构体名{ 结构体成员列表 }；
	//	通过结构体创建变量的方式有三种：
	//	1  struct 结构体名 变量名
	//	2  struct 结构体名 变量名 = { 成员1值 ， 成员2值... }
	//	3  定义结构体时顺便创建变量



	//结构变量创建方式1
	struct student stu1;	//struct可以省略

	stu1.age = 18;
	stu1.name = "张三";
	stu1.score = 100;

	cout << "姓名：" << stu1.name << "年龄：" << stu1.age << "成绩:" << stu1.score << endl;

	//结构体变量创建方式2
	struct student stu2 = { "李四",19,80 };
	cout << "姓名：" << stu2.name << "年龄：" << stu2.age << "成绩：" << stu2.score << endl;

	//
	stu3.name = "王五";
	stu3.age = 23;
	stu3.score = 90;
	cout << "姓名：" << stu3.name << "年龄：" << stu3.age << "成绩：" << stu3.score << endl;

}
//> 总结1：定义结构体时的关键字是struct，不可省略
//> 总结2：创建结构体变量时，关键字struct可以省略
//> 总结3：结构体变量利用操作符 ''.''  访问成员

//结构体数组
//将自定义的结构体放入到数组中方便维护
//语法：struct  结构体名 数组名[元素个数] = { {} , {} , ... {} }
void StructArr() {
	//结构体数组
	struct student arr[3] = {
		{"张三",14,100},
		{"李四",18,80},
		{"王五",23,90}
	};
	for (int i = 0; i < sizeof(arr) / sizeof(student); i++) {
		cout << "姓名：" << arr[i].name << " 年龄：" << arr[i].age << " 成绩：" << arr[i].score << endl;
	}
}

//结构体指针
//作用:通过指针访问结构体中的成员
//利用操作符 -> 可以通过结构体指针访问结构体属性
void StructPointer() {
	struct student stu = { "chase",23,120 };
	struct student* p = &stu;
	p->score = 130;	//指针通过->操作符可以访问成员
	cout << "姓名：" << p->name << " 年龄：" << p->age << " 成绩：" << p->score << endl;
}

//结构体嵌套  
//在结构体中可以定义另一个结构体作为成员，用来解决实际问题
void StructNesting() {
	//教师结构体定义
	struct Teacher {
		//成员列表
		int id;//职工编号
		string name;//教师姓名
		int age;//教师年龄
		struct student stu;//子结构体 学生

	};
	struct Teacher t1;
	t1.id = 10000;
	t1.name = "李宗盛";
	t1.age = 45;
	t1.stu.name = "chase";
	t1.stu.age = 23;
	t1.stu.score = 120;
	cout << "教师 职工编号：" << t1.id << " 姓名：" << t1.name << "年龄：" <<t1.age<< endl;
	cout << "辅导学生 姓名：" << t1.stu.name << " 年龄：" << t1.stu.age << " 成绩：" << t1.stu.score << endl;
}


//值传递
void PStudent(student stu) {
	stu.age = 34;
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
}
//地址传递
void PStudent2(student* stu) {
	stu->name = "chase";
	stu->age = 21;
	stu->score = 123;
	cout << stu->name << " " << stu->age << " " << stu->score << endl;
}
//结构体函数传参 
//如果不想修改主函数中的数据，用值传递，反之用地址传递
void StructParameter() {
	student stu = { "张三",17,100 };
	PStudent(stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	PStudent2(&stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
}

//结构体使用const
//使用const来防止误操作
void printStudent(const student* stu) //加const防止函数体中的误操作
{
	//stu->age = 100; //操作失败，因为加了const修饰
	cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;

}

