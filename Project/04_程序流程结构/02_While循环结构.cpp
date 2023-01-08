#include<iostream>
using namespace std;
//猜数字
void GuessNumber() {
	//VS格式化代码：Ctrl+k Ctrl+D
	int num = 76, guess = 0;
	cout << "请输入猜测数据：";
	cin >> guess;
	while (guess != num) {	//先判断再执行
		if (guess > 2 * num) {
			cout << "too Big" << endl;
		}
		else if (guess > 1.2 * num) {
			cout << "big" << endl;
		}
		else if ( guess>num) {
			cout << "little big" << endl;
		}
		else if (guess >=0.75 * num) {
			cout << "little small" << endl;
		}
		else if (guess < 0.75 * num) {
			cout << "too small" << endl;
		}
		cout << "请输入猜测数据：";
		cin >> guess;
	}
	cout << "Yes" << endl;
}