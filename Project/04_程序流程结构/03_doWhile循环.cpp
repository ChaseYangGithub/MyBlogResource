#include<iostream>
#include<math.h>
using namespace std;
//ʹ��doWhieѭ��ʵ�����nλ������ˮ�ɻ���
//ˮ�ɻ�����ָһ�� 3 λ��������ÿ��λ�ϵ����ֵ� 3����֮�͵���������
//
//���磺1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 153
//C++Ҫʹ�ôη���#include<math.h>��ʹ��pow��a, b��
void DaffodilsNumber() {

	int sum = 100;
	do {
		 int count = 0;

		count = (int)pow(sum / 100,3)  + pow(sum / 10 - (sum / 100) * 10 ,3) + pow(sum % 10,3);
		if (sum == count) {
			cout << "\t" << count;
		}
		sum++;
	} while (sum >=100&& sum < 1000);
}