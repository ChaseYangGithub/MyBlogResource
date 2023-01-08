#include<iostream>
#include<math.h>
using namespace std;
//使用doWhie循环实现求解n位数的类水仙花数
//水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
//
//例如：1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 153
//C++要使用次方请#include<math.h>并使用pow（a, b）
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