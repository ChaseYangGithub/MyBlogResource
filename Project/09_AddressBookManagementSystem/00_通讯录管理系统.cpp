//ͨѶ¼��һ�����Լ�¼���ˡ�������Ϣ�Ĺ��ߡ�
//
//���̳���Ҫ����C++��ʵ��һ��ͨѶ¼����ϵͳ
//
//ϵͳ����Ҫʵ�ֵĹ������£�
//
//* �����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ������¼1000��
//* ��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
//* ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
//* ������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
//* �޸���ϵ�ˣ��������������޸�ָ����ϵ��
//* �����ϵ�ˣ����ͨѶ¼��������Ϣ
//* �˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼
#include<iostream>
using namespace std;
//constexprʹָ���ĳ������ʽ����ڳ������׶μ��������������������صȵ��������н׶�
constexpr auto MaxSize = 1000;
//��ϵ����Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ
struct Person {
	string name;	//��ϵ������
	string sex;		//��ϵ���Ա�
	int age;	//��ϵ������
	long telephone;	//��ϵ�绰
	string address;	//��ͥסַ
};
//ͨѶ¼�ṹ��
struct AddressBook {
	Person person[MaxSize];//��ϵ������
	int number;	//ͨѶ¼����
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
	//��ʼ��ͨѶ¼
	AddressBook book;
	book.number = 0;	//����Ϊ0
	int select = 0;//ѡ����
	while (true) {
		ShowMenu();
		//�����û���ͬ��ѡ�񣬽��벻ͬ�Ĺ��ܣ�����ѡ��switch��֧�ṹ���������ܹ����д
		cout << "��ѡ���ܣ�";
		cin >> select;
		switch (select) {
		case 0:cout << "�Ѿ��˳�ϵͳ" << endl;
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

//ɾ��ͨѶ¼
void DeleteBook(AddressBook* book) {
	cout << "��ȷ��Ҫɾ��ô��\n 1 yes \n 2 no" << endl;
	int tag = -1;
	cin >> tag;
	if (tag == 1) {
		book->number = 0;
		cout << "ɾ���ɹ�";
	}
	else if(tag==2){
		cout << "�Ѿ�ȡ��ɾ��" << endl;
	}
	else {
		cout << "���ݲ��Ϸ���" << endl;
		DeleteBook(book);
	}
	system("pause");
	system("cls");
}

//�������������޸�ָ����ϵ��
void ModifyContact(AddressBook* book) {
	string name = "";//���޸�����
	cout << "��������޸�������";
	cin >>name;
	int tag = IsExit(*book, name);
	if (tag < 0) {
		cout << "����������" << endl;
	}
	else {
		//����
		string name;
		cout << "����������:";
		cin >> name;
		book->person[tag].name = name;

		//�Ա�
		cout << "�������Ա�!" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;
		while (1) {
			cout << "\n�����Ա�:";
			cin >> sex;
			if (sex == 1) {
				book->person[tag].sex = "��";
				break;
			}
			else if (sex == 2) {
				book->person[tag].sex = "Ů";
				break;
			}
			else {
				cout << "�����������������룡";
				continue;
			}
		}

		//����
		int age;
		cout << "���������䣺";
		cin >> age;
		while (cin.fail()) {	//�ж��������ݵĺϷ���
			cin.clear();
			cout << "�������" << endl;
			cin.ignore(10000, '\n');//���\nǰ��10000���ַ�
			cout << "���������䣺";
			cin >> age;
		}
		book->person[tag].age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��";
		long tele = 0;
		cin >> tele;
		book->person[tag].telephone = tele;

		//��ͥסַ
		cout << "�������ͥסַ��";
		string address = " ";
		cin >> address;
		book->person[tag].address = address;
	}
	ShowContact(*book);
}

//������ϵ��
void SearchContact(AddressBook book) {
	string name="";//����������
	cout << "�������������:";
	cin >> name;
	int tag = IsExit(book, name);//���
	if (tag < 0) {
		cout << "����������" << endl;
	}
	else {
		cout << "������" << book.person[tag].name << " �Ա�"
			<< book.person[tag].sex << " ���䣺"
			<< book.person[tag].age << " �绰��"
			<< book.person[tag].telephone << " ��ַ��"
			<< book.person[tag].address << endl;
	}
	system("pause");
	system("cls");

}
//ɾ����ϵ��
void DeleteContact(AddressBook* book) {
	string uname = "";
	cout << "����������";
	cin >> uname;
	int num = IsExit(*book, uname);	//�������������
	if (num < 0) {
		cout << "����������" << endl;
	}
	else {
		for (int i = num; i < book->number-1; i++) {
			book->person[i] = book->person[i + 1];
		}
	}
	book->number--;//������һ
}
//�������ж� ���ڷ������ ���򷵻�-1
int IsExit(AddressBook book,string name) {
	for (int i = 0; i < book.number; i++) {
		if (book.person[i].name == name) {
			return i;//���ڷ���
		}
	}
	return -1;//���ݲ�����
}
//��ʾ��ϵ��
void ShowContact(AddressBook book) {
	//�ж������ǰͨѶ¼��û����Ա������ʾ��¼Ϊ�գ���������0����ʾͨѶ¼����Ϣ
	if (book.number == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		cout << "����\t����\t�Ա�\t�绰\t\t��ַ" << endl;
		for (int i = 0; i < book.number; i++) {
			cout << book.person[i].name << "\t" << book.person[i].age << "\t" 
				<< book.person[i].sex << "\t" << book.person[i].telephone << "\t\t" 
				<< book.person[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ
void AddContact(AddressBook* book) {
	//�����ϵ��ǰ���ж�ͨѶ¼�Ƿ�������������˾Ͳ�����ӣ�δ�����������ϵ����Ϣ������뵽ͨѶ¼
	//�ж�ͨѶ¼�ǲ�������
	if (book->number == MaxSize) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;//void����������������м�λ����ǰ�˳�������ʹ��return���
	}
	else {
		//����
		string name;
		cout << "����������:";
		cin >> name;
		book->person[book->number].name = name;
		
		//�Ա�
		cout << "�������Ա�!" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;
		while (1) {
			cout << "\n�����Ա�:" ;
			cin >> sex;
			if (sex == 1 ) {
				book->person[book->number].sex = "��";
				break;
			}
			else if (sex == 2) {
				book->person[book->number].sex = "Ů";
				break;
			}
			else {
				cout << "�����������������룡";
				continue;
			}
		}

		//����
		int age;
		cout << "���������䣺";
		cin >> age;
		while (cin.fail()) {	//�ж��������ݵĺϷ���
			cin.clear();
			cout << "�������" << endl;
			cin.ignore(10000,'\n');//���\nǰ��10000���ַ�
			cout << "���������䣺";
			cin >> age;
		}
		book->person[book->number].age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��";
		long tele = 0;
		cin >> tele;
		book->person[book->number].telephone = tele;

		//��ͥסַ
		cout << "�������ͥסַ��";
		string address=" ";
		cin >> address;
		book->person[book->number].address = address;
		
		//����ͨѶ¼����
		book->number = book->number + 1;
		cout << "��ӳɹ���" << endl;
		system("pause");//���ֱ������Ļ����ͣ��Ļʲô��������
		system("cls");	//����	
	}

}
//��ʾ�˵�
void ShowMenu() {
	cout << "**************************" << endl;
	cout << "**\t1 �����ϵ��\t**" << endl;
	cout << "**\t2 ��ʾ��ϵ��\t**" << endl;
	cout << "**\t3 ɾ����ϵ��\t**" << endl;
	cout << "**\t4 ������ϵ��\t**" << endl;
	cout << "**\t5 �޸���ϵ��\t**" << endl;
	cout << "**\t6 �����ϵ��\t**" << endl;
	cout << "**\t0 �˳�ͨѶ¼\t**" << endl;
	cout << "**************************" << endl;
}