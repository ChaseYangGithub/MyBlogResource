#include<iostream>
using namespace std;
//������
void GuessNumber() {
	//VS��ʽ�����룺Ctrl+k Ctrl+D
	int num = 76, guess = 0;
	cout << "������²����ݣ�";
	cin >> guess;
	while (guess != num) {	//���ж���ִ��
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
		cout << "������²����ݣ�";
		cin >> guess;
	}
	cout << "Yes" << endl;
}