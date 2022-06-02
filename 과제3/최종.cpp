// ��� ����
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// ��� ����
#define MAX_STRING 32

// �Լ� ����
void doTask();

void registeration();
void clothes_onsale();
void clothes_complete();
void sales_stat();
void program_exit();

void search(); //���� �߰�
void purchase(); //���� �߰�
void clothes_purchase(); //���� �߰�
void purchase_eval(); //���� �߰�

// ���� ����
ifstream fin("input.txt");
ofstream fout("output.txt");

string currentID;
string nameinfo;
string SSNinfo;
string passwordinfo;
string IDinfo;



struct clothes {
	string productname;
	string productioncompany;
	string price;
	string quantity;
	string avg_satisfaction;
	string currentID; //���� �߰�(analysis class diagram���� �ݿ� �ʿ�)
};

struct MemberInfo
{
	string membername;
	string memberSSN;
	string memberID;
	string memberpassword;
};

MemberInfo member[100];
struct MemberInfo* p = member;

class Member {

};

class SignUpUI {
public:
	void signupinterface();		//ȸ������ �Է¹ޱ�
};

class SignUp {
public:
	SignUp();
	void addaccount(string name, string SSN, string ID, string password);

};

void SignUpUI::signupinterface() {		//ȸ������ : �����
	char name[MAX_STRING], SSN[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

	fin >> name >> SSN >> ID >> password;
	currentID = ID;
	nameinfo = name;
	passwordinfo = password;
	SSNinfo = SSN;


	fout << "1.1. ȸ������" << endl;
	fout << name << " " << SSN << " " << ID << " " << password << endl;
}

SignUp::SignUp() {
	SignUpUI signupui;
	signupui.signupinterface();
}

void SignUp::addaccount(string name, string SSN, string ID, string password) {
	p->membername = name;
	p->memberSSN = SSN;
	p->memberID = ID;
	p->memberpassword = password;
	p++;
	return;
}

class WithDrawUI {		//ȸ��Ż��
public:
	void withdrawinterface();
};

class WithDraw {
public:
	WithDraw();
	void deleteaccount(string ID);
};

void WithDrawUI::withdrawinterface() {

	fout << "1.2. ȸ��Ż��" << endl;
	fout << currentID << endl;
}

WithDraw::WithDraw() {
	WithDrawUI withdrawui;
	withdrawui.withdrawinterface();
}

void WithDraw::deleteaccount(string ID) {
	struct MemberInfo* p = member;
	for (int i = 0; i < 100; i++)
	{
		if (ID == p[i].memberID)
		{
			p->memberID = "NULL";
			p->membername = "NULL";
			p->memberSSN = "NULL";
			p->memberSSN == "NULL";
		}
	}
	return;
}

class LogInUI {
public:
	void logininterface();
};

class LogIn {
public:
	LogIn();
};

void LogInUI::logininterface() {
	char ID[MAX_STRING], password[MAX_STRING];
	int checkid = 0;

	fin >> ID >> password;
	IDinfo = ID;
	passwordinfo = password;

	currentID = ID;

	fout << "2.1. �α���" << endl;
	fout << ID << " " << password << endl;

}
LogIn::LogIn() {
	LogInUI loginui;
	loginui.logininterface();
}


class LogOutUI {
public:
	void logoutinterface();
};

class LogOut {
public:
	LogOut();
};

void LogOutUI::logoutinterface() {
	fout << "2.2. �α׾ƿ�" << endl;
	fout << currentID << endl;
}

LogOut::LogOut() {
	LogOutUI logoutui;
	logoutui.logoutinterface();
}

clothes searched_clothes; // ���� �߰�

clothes purchased_clothes[MAX_STRING]; //���� �߰�
int purchased_count = 0; //���� �߰�

clothes c_array[MAX_STRING];
int count = 0;
int is_program_exit = 0;

int main()
{ // ���� ������� ���� �ʱ�ȭ

	doTask();
	return 0;
}

void doTask() { // �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;


	while (!is_program_exit) { // �Է����Ͽ��� �޴� ���� 2���� �б�
		fin >> menu_level_1;
		fin >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1) {
		case 1:
		{
			switch (menu_level_2) {
			case 1:
			{
				SignUp signup;
				signup.addaccount(nameinfo, SSNinfo, IDinfo, passwordinfo);
				break;
			}
			case 2:
			{
				WithDraw withdraw;
				withdraw.deleteaccount(currentID);
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2) {
			case 1:
			{
				LogIn login;
				break;
			}
			case 2:
			{
				LogOut logout;
				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // "3.1. �Ǹ��Ƿ� ��ϡ� �޴� �κ�
			{
				registeration();
				break;
			}
			case 2: // "3.2 ��� ��ǰ ��ȸ" �޴� �κ� 
			{
				clothes_onsale();
				break;
			}
			case 3:
			{
				clothes_complete();
				break;
			}
			}
			break;
		}
		case 4:
		{
			switch (menu_level_2)
			{
			case 1: // "4.1. ��ǰ ���� �˻�" �޴� �κ�
			{
				search();
				break;
			}
			case 2: // "4.2. ��ǰ ����" �޴� �κ�
			{
				purchase();
				break;
			}
			case 3: // "4.3. ��ǰ ���� ���� ��ȸ" �޴� �κ�
			{
				clothes_purchase();
				break;
			}
			case 4: // "4.4. ��ǰ ���Ÿ����� ��" �޴� �κ�
			{
				purchase_eval();
				break;
			}
			}
			break;
		}

		case 5:
		{
			switch (menu_level_2) {
			case 1: // 
			{
				sales_stat();
				break;
			}
			}
			break;
		}

		case 6:
		{
			switch (menu_level_2) {
			case 1:
			{
				program_exit();
				break;
			}
			}
			break;
		}

		}
	}
}

void program_exit() {
	is_program_exit = 1;
	fout << "6.1. ����" << endl;
}

void search()
{
	string productname;
	string productioncompany;
	string price;
	string quantity;
	string sellerID;

	fin >> productname;

	fout << "4.1. ��ǰ ���� �˻�" << endl;

	for (int i = 0; i < ::count; i++)
	{
		if (c_array[i].productname == productname)
		{
			searched_clothes = c_array[i]; // �˻� ��ǰ ����ü(searched_clothes)�� �Է¹��� ��ǰ �̸��� ���Ե� �Ǹ� ��ǰ ����ü(c_array)�� ����
			fout << c_array[i].currentID << " ";
			fout << c_array[i].productname << " ";
			fout << c_array[i].productioncompany << " ";
			fout << c_array[i].price << " ";
			fout << c_array[i].quantity << " ";
			fout << c_array[i].avg_satisfaction << endl;
			break;
		}
	}
}//���� �߰�

void purchase()
{
	fout << "4.2. ��ǰ ����" << endl;
	for (int i = 0; i < ::count; i++)
	{
		if (c_array[i].productname == searched_clothes.productname) //�˻� ��ǰ ����ü�� �̸��� �Ǹ� ��ǰ ����ü�� �̸��� ���� ���  
		{
			c_array[i].quantity = to_string(stoi(c_array[i].quantity) - 1); //�Ǹ� ��ǰ ����ü�� ���� -1�ϱ�
			purchased_clothes[::purchased_count++] = c_array[i]; //���Ż�ǰ ����ü(purchased_clothes)�� �� �Ǹ� ��ǰ ����ü ���� (�̷��� �ϸ� ������ 2�� �̻��� ��ǰ�� 2�� �̻� ������ ��� purchased_clothes�� quantity�� �ǽð� �ݿ��� �ȵǴ� ������ ����)
			fout << c_array[i].currentID << " ";
			fout << c_array[i].productname << endl; // �Ǹ��� id�� ��ǰ�� ���
			break;
		}
	}
}//���� �߰�

void clothes_purchase()
{
	fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
	for (int i = 0; i < ::purchased_count; i++) //���Ż�ǰ ����ü(purchased_clothes) ���� ���
	{
		fout << purchased_clothes[i].currentID << " ";
		fout << purchased_clothes[i].productname << " ";
		fout << purchased_clothes[i].productioncompany << " ";
		fout << purchased_clothes[i].price << " ";
		fout << purchased_clothes[i].quantity << " ";
		fout << purchased_clothes[i].avg_satisfaction << endl;
	}

}//���� �߰�

void purchase_eval()
{
	string avg_satisfaction;

	fin >> avg_satisfaction;

	fout << "4.4. ��ǰ ���Ÿ����� ��" << endl;
	for (int i = 0; i < ::count; i++) //�Ǹ� ��ǰ ����ü�� ������ �� �ݿ�
	{
		if (c_array[i].productname == searched_clothes.productname)
		{
			c_array[i].avg_satisfaction = avg_satisfaction;
			fout << c_array[i].currentID << " ";
			fout << c_array[i].productname << " ";
			fout << c_array[i].avg_satisfaction << endl;
			break;
		}
	}
	for (int i = 0; i < ::purchased_count; i++) //���� ��ǰ ����ü�� ������ �� �ݿ�
	{
		if (purchased_clothes[i].productname == searched_clothes.productname)
		{
			purchased_clothes[i].avg_satisfaction = avg_satisfaction;
			break;
		}
	}
}//���� �߰�


void registeration()
{
	string productname;
	string productioncompany;
	string price;
	string quantity;
	string avg_satisfaction;

	fin >> productname;
	fin >> productioncompany;
	fin >> price;
	fin >> quantity;

	clothes c1;
	c1.productname = productname;
	c1.productioncompany = productioncompany;
	c1.price = price;
	c1.quantity = quantity;
	c1.avg_satisfaction = '0'; //�߰�
	c1.currentID = IDinfo;

	c_array[::count++] = c1;

	fout << "3.1. �Ǹ� �Ƿ� ���" << endl;

	fout << productname << " ";
	fout << productioncompany << " ";
	fout << price << " ";
	fout << quantity << endl;
}


void clothes_onsale()
{
	fout << "3.2. ��� ��ǰ ��ȸ" << endl;
	for (int i = 0; i < ::count; i++)
	{
		fout << c_array[i].productname << " ";
		fout << c_array[i].productioncompany << " ";
		fout << c_array[i].price << " ";
		fout << c_array[i].quantity << endl;

	}
}

void clothes_complete()
{
	fout << "3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ" << endl;
	for (int i = 0; i < ::count; i++)
	{
		fout << c_array[i].productname << " ";
		fout << c_array[i].productioncompany << " ";
		fout << c_array[i].price << " ";
		fout << c_array[i].quantity << " ";
		fout << c_array[i].avg_satisfaction << endl;

	}
}

void sales_stat()
{
	fout << "5.1 �Ǹ� ��ǰ ���" << endl;


	for (int i = 0; i < ::count; i++)
	{
		fout << c_array[i].productname << " ";
		fout << (stoi(c_array[i].price) * stoi(c_array[i].quantity)) << " ";
		fout << c_array[i].avg_satisfaction << endl;

	}
}
