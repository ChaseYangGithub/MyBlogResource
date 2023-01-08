#include<iostream>
using namespace std;
//一维数组定义
void ArrayBasic() {
	//总结1：数组名的命名规范与变量名命名规范一致，不要和变量重名
	//总结2：数组中下标是从0开始索引
	// 
	//1. 数据类型  数组名[ 数组长度 ]; 
	int score[10];
	//输出
	score[0] = 1;
	score[1] = 2;
	score[4] = 7;
	cout << "score[4]=" << score[4] << endl;

	//2. 数据类型  数组名[数组长度] = { 值1，值2 ... }; 
	//如果{}内不足10个数据，剩余数据用0补全
	int score2[10] = { 2,132,5,31,5262,412,432,53 };
	//输出
	cout << "score2[3]=" << score2[3] << endl;
	cout << "score2[9]=" << score2[9] << endl;

	//3. 数据类型  数组名[] = { 值1，值2 ... }; 
	int score3[] = { 12,21,42,31 };
	cout << "score3[3]=" << score3[3] << endl;
	//注意：数组名是常量，不可以赋值
	//总结1：直接打印数组名，可以查看数组所占内存的首地址
	//总结2：对数组名进行sizeof，可以获取整个数组占内存空间的大小,对于整型数据除以4可以获得数组数据个数
	cout << "score3大小：" << sizeof(score3) << endl;
	cout << "score2大小:" << sizeof(score2) << endl;
}

//	在一个数组中记录了五只小猪的体重，如：int arr[5] = { 300,350,200,400,250 };
//找出并打印最重的小猪体重。
void Weight() {
	int arr[5] = { 300,350,200,400,250 };
	int Max = 0;
	//对数组名进行sizeof，可以获取整个数组占内存空间的大小,对于整型数据除以4可以获得数组数据个数
	for (int i = 0; i < sizeof(arr) / 4; i++) {
		if (arr[Max] < arr[i]) {
			Max = i;
		}
	}
	cout << "最重序号为：" << Max << ",重量为：" << arr[Max] << endl;
}

//数组逆置数据
//如原数组元素为：1, 3, 2, 5, 4; 逆置后输出结果为:4, 5, 2, 3, 1
void Reverse() {
	int temp;
	int arr[] = { 1,2,3,4,5,6 ,7 };
	for (int i = 0; i < sizeof(arr) / 4; i++) {
		if (i < sizeof(arr) / 8) {//前半部分数据交换
			temp = arr[i];
			arr[i] = arr[sizeof(arr) / 4 - 1 - i];	//总长度length=sizeof(arr)/4 区间0~length-1,对称首尾交换
			arr[sizeof(arr) / 4 - 1 - i] = temp;
		}
	}
	for (int i = 0; i < sizeof(arr) / 4; i++) {
		cout << arr[i] << "\t";
	}
}

//冒泡排序
//：** 最常用的排序算法，对数组内元素进行排序
//1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
//2. 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
//3. 重复以上的步骤，每次比较次数 - 1，直到不需要比较
void BubbleSort() {
	//将数组 { 4,2,8,0,5,7,1,3,9 } 进行升序排序
	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	for (int i = 0; i < sizeof(arr) / 4 - 1; i++) {
		for (int j = 0; j < (sizeof(arr) / 4 - i - 1); j++) {//每一循环交换将最大值放到了最后，所以最后一个值不需要再比较
			if (arr[j] > arr[j + 1]) {//前面大则交换
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < sizeof(arr) / 4; i++) {
		cout << arr[i] << "\t";
	}

}

//二维数组定义方式
void MakeArray() {
	/*
	1. 数据类型  数组名[ 行数 ][ 列数 ];
	2. 数据类型  数组名[ 行数 ][ 列数 ] = { {数据1，数据2 } ，{数据3，数据4 } };
	3. 数据类型  数组名[ 行数 ][ 列数 ] = { 数据1，数据2，数据3，数据4};
	4. 数据类型  数组名[  ][ 列数 ] = { 数据1，数据2，数据3，数据4};
	*/
	//数组类型 数组名 [行数][列数]
	int arr[2][3];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}

	//数据类型 数组名[行数][列数] = { {数据1，数据2 } ，{数据3，数据4 } };
	int arr2[2][3] = { {1,2,3},{4,5,6} };

	//数据类型 数组名[行数][列数] = { 数据1，数据2 ,数据3，数据4  };
	int arr3[2][3] = { 1,2,3,4,5,6 };

	//数据类型 数组名[][列数] = { 数据1，数据2 ,数据3，数据4  }; 在定义二维数组时，如果初始化了数据，可以省略行数
	int arr4[][3] = { 1,2,3,4,5,6 };

	//二维数组大小
	cout << "二维数组大小： " << sizeof(arr) << endl;
	cout << "二维数组一行大小： " << sizeof(arr[0]) << endl;
	cout << "二维数组元素大小： " << sizeof(arr[0][0]) << endl;

	cout << "二维数组行数： " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "二维数组列数： " << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

	//地址
	cout << "二维数组首地址：" << arr << endl;
	cout << "二维数组第一行地址：" << arr[0] << endl;
	cout << "二维数组第二行地址：" << arr[1] << endl;

	cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;
}

//案例描述：有三名同学（张三，李四，王五），在一次考试中的成绩分别如下表，**请分别输出三名同学的总成绩**
//	每行数据为一个人的
//| 张三 | 100 | 100 | 100  |
//| ---- | ---- | ---- | ---- |
//| 李四 | 90 | 50 | 100  |
//| 王五 | 60 | 70 | 80 |


void  Grade() {
	int arr[3][3] = { {100,100,100},{90,50,100},{60,70,80} };
	string name[3] = { "张三","李四","王五" };
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += arr[i][j];
		}
		cout << name[i] << "同学总成绩为" << sum << endl;
	}
}
