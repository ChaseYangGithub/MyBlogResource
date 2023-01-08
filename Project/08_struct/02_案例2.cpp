#include<iostream>
using namespace std;
//设计一个英雄的结构体，包括成员姓名，年龄，性别; 创建结构体数组，数组中存放5名英雄。
//通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
//{"刘备", 23, "男"},
//{ "关羽",22,"男" },
//{ "张飞",20,"男" },
//{ "赵云",21,"男" },
//{ "貂蝉",19,"女" },

//英雄结构体
struct Hero {
	string name;//英雄名称
	int age;//英雄年龄
	string sex;//英雄性别
};

//冒泡排序--年龄升序
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

//打印数据
void PrintHero(Hero hero[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "姓名：" << hero[i].name << "\t年龄：" << hero[i].age << "\t性别：" << hero[i].sex << endl;
	}
}

//案例2
void Case2() {
	Hero hero[] = {
		{"刘备", 23, "男"},
		{ "关羽",22,"男" },
		{ "张飞",20,"男" },
		{ "赵云",21,"男" },
		{ "貂蝉",19,"女" }
	};
	int len = sizeof(hero) / sizeof(Hero);
	BubbleSort(hero, len);
	PrintHero(hero, len);
}