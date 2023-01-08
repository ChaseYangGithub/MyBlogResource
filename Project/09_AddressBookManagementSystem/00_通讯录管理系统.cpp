//通讯录是一个可以记录亲人、好友信息的工具。
//
//本教程主要利用C++来实现一个通讯录管理系统
//
//系统中需要实现的功能如下：
//
//* 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
//* 显示联系人：显示通讯录中所有联系人信息
//* 删除联系人：按照姓名进行删除指定联系人
//* 查找联系人：按照姓名查看指定联系人信息
//* 修改联系人：按照姓名重新修改指定联系人
//* 清空联系人：清空通讯录中所有信息
//* 退出通讯录：退出当前使用的通讯录
#include<iostream>
using namespace std;
//constexpr使指定的常量表达式获得在程序编译阶段计算出结果的能力，而不必等到程序运行阶段
constexpr auto MaxSize = 1000;
//联系人信息包括：姓名、性别、年龄、联系电话、家庭住址
struct Person {
	string name;	//联系人姓名
	string sex;		//联系人性别
	int age;	//联系人年龄
	long telephone;	//联系电话
	string address;	//家庭住址
};
//通讯录结构体
struct AddressBook {
	Person person[MaxSize];//联系人数组
	int number;	//通讯录人数
};
void ShowMenu();
void AddContact(AddressBook *book);
void ShowContact(AddressBook book);
int IsExit(AddressBook book, string name);
void DeleteContact(AddressBook* book);
void SearchContact(AddressBook book);
void ModifyContact(AddressBook* book);
void DeleteBook(AddressBook* book);
int main() {
	//初始化通讯录
	AddressBook book;
	book.number = 0;	//人数为0
	int select = 0;//选择功能
	while (true) {
		ShowMenu();
		//根据用户不同的选择，进入不同的功能，可以选择switch分支结构，将整个架构进行搭建
		cout << "请选择功能：";
		cin >> select;
		switch (select) {
		case 0:cout << "已经退出系统" << endl;
			break;
		case 1:AddContact(&book);
			break;
		case 2:ShowContact(book);
			break;
		case 3:DeleteContact(&book);
			ShowContact(book);
			break;
		case 4:SearchContact(book);
			break;
		case 5:ModifyContact(&book);
			break;
		case 6:DeleteBook(&book);
			break;
		}
	}
	system("pause");
	return 0;
}

//删除通讯录
void DeleteBook(AddressBook* book) {
	cout << "你确定要删除么？\n 1 yes \n 2 no" << endl;
	int tag = -1;
	cin >> tag;
	if (tag == 1) {
		book->number = 0;
		cout << "删除成功";
	}
	else if(tag==2){
		cout << "已经取消删除" << endl;
	}
	else {
		cout << "数据不合法！" << endl;
		DeleteBook(book);
	}
	system("pause");
	system("cls");
}

//按照姓名重新修改指定联系人
void ModifyContact(AddressBook* book) {
	string name = "";//待修改姓名
	cout << "请输入待修改姓名：";
	cin >>name;
	int tag = IsExit(*book, name);
	if (tag < 0) {
		cout << "姓名不存在" << endl;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名:";
		cin >> name;
		book->person[tag].name = name;

		//性别
		cout << "请输入性别!" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (1) {
			cout << "\n输入性别:";
			cin >> sex;
			if (sex == 1) {
				book->person[tag].sex = "男";
				break;
			}
			else if (sex == 2) {
				book->person[tag].sex = "女";
				break;
			}
			else {
				cout << "输入有误，请重新输入！";
				continue;
			}
		}

		//年龄
		int age;
		cout << "请输入年龄：";
		cin >> age;
		while (cin.fail()) {	//判断输入数据的合法性
			cin.clear();
			cout << "输入错误" << endl;
			cin.ignore(10000, '\n');//清除\n前的10000个字符
			cout << "请输入年龄：";
			cin >> age;
		}
		book->person[tag].age = age;

		//联系电话
		cout << "请输入联系电话：";
		long tele = 0;
		cin >> tele;
		book->person[tag].telephone = tele;

		//家庭住址
		cout << "请输入家庭住址：";
		string address = " ";
		cin >> address;
		book->person[tag].address = address;
	}
	ShowContact(*book);
}

//查找联系人
void SearchContact(AddressBook book) {
	string name="";//待查找姓名
	cout << "请输入查找姓名:";
	cin >> name;
	int tag = IsExit(book, name);//序号
	if (tag < 0) {
		cout << "姓名不存在" << endl;
	}
	else {
		cout << "姓名：" << book.person[tag].name << " 性别："
			<< book.person[tag].sex << " 年龄："
			<< book.person[tag].age << " 电话："
			<< book.person[tag].telephone << " 地址："
			<< book.person[tag].address << endl;
	}
	system("pause");
	system("cls");

}
//删除联系人
void DeleteContact(AddressBook* book) {
	string uname = "";
	cout << "输入姓名：";
	cin >> uname;
	int num = IsExit(*book, uname);	//检查姓名存在性
	if (num < 0) {
		cout << "姓名不存在" << endl;
	}
	else {
		for (int i = num; i < book->number-1; i++) {
			book->person[i] = book->person[i + 1];
		}
	}
	book->number--;//数量减一
}
//存在性判断 存在返回序号 否则返回-1
int IsExit(AddressBook book,string name) {
	for (int i = 0; i < book.number; i++) {
		if (book.person[i].name == name) {
			return i;//存在返回
		}
	}
	return -1;//数据不存在
}
//显示联系人
void ShowContact(AddressBook book) {
	//判断如果当前通讯录中没有人员，就提示记录为空，人数大于0，显示通讯录中信息
	if (book.number == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		cout << "姓名\t年龄\t性别\t电话\t\t地址" << endl;
		for (int i = 0; i < book.number; i++) {
			cout << book.person[i].name << "\t" << book.person[i].age << "\t" 
				<< book.person[i].sex << "\t" << book.person[i].telephone << "\t\t" 
				<< book.person[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//添加联系
void AddContact(AddressBook* book) {
	//添加联系人前先判断通讯录是否已满，如果满了就不再添加，未满情况将新联系人信息逐个加入到通讯录
	//判断通讯录是不是满了
	if (book->number == MaxSize) {
		cout << "通讯录已满，无法添加！" << endl;
		return;//void函数如果想在它的中间位置提前退出，可以使用return语句
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名:";
		cin >> name;
		book->person[book->number].name = name;
		
		//性别
		cout << "请输入性别!" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (1) {
			cout << "\n输入性别:" ;
			cin >> sex;
			if (sex == 1 ) {
				book->person[book->number].sex = "男";
				break;
			}
			else if (sex == 2) {
				book->person[book->number].sex = "女";
				break;
			}
			else {
				cout << "输入有误，请重新输入！";
				continue;
			}
		}

		//年龄
		int age;
		cout << "请输入年龄：";
		cin >> age;
		while (cin.fail()) {	//判断输入数据的合法性
			cin.clear();
			cout << "输入错误" << endl;
			cin.ignore(10000,'\n');//清除\n前的10000个字符
			cout << "请输入年龄：";
			cin >> age;
		}
		book->person[book->number].age = age;

		//联系电话
		cout << "请输入联系电话：";
		long tele = 0;
		cin >> tele;
		book->person[book->number].telephone = tele;

		//家庭住址
		cout << "请输入家庭住址：";
		string address=" ";
		cin >> address;
		book->person[book->number].address = address;
		
		//更新通讯录人数
		book->number = book->number + 1;
		cout << "添加成功！" << endl;
		system("pause");//如果直接清屏幕不暂停屏幕什么都看不见
		system("cls");	//清屏	
	}

}
//显示菜单
void ShowMenu() {
	cout << "**************************" << endl;
	cout << "**\t1 添加联系人\t**" << endl;
	cout << "**\t2 显示联系人\t**" << endl;
	cout << "**\t3 删除联系人\t**" << endl;
	cout << "**\t4 查找联系人\t**" << endl;
	cout << "**\t5 修改联系人\t**" << endl;
	cout << "**\t6 清空联系人\t**" << endl;
	cout << "**\t0 退出通讯录\t**" << endl;
	cout << "**************************" << endl;
}