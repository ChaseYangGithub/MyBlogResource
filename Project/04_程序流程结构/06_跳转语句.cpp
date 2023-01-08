#include<iostream>
using namespace std;
//跳转语句
void JumpStatement() {
	//break 
	//出现在switch条件语句中，作用是终止case并跳出switch
	//出现在循环语句中，作用是跳出当前的循环语句
	//出现在嵌套循环中，跳出最近的内层循环语句

	//continue
	//在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
	//continue并没有使整个循环终止，而break会跳出循环
	for (int i = 0; i < 10; i++) {
		if (i == 5) {	//跳过i为5的情况
			continue;
		}
		cout << i << "\t";
	}

	//goto语句
	//在程序中不建议使用goto语句，以免造成程序流程混乱
	cout << "\ngoto---" << endl;	
	cout << "1" << endl;
	goto FLAG;	//跳转到标记点
	cout << "2" << endl;
	cout << "3" << endl;
FLAG:
	cout << "flag!" << endl;

 }