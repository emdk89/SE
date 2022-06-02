// ��� ����
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// ��� ����
#define MAX_STRING 32

// �Լ� ����
void doTask();

void program_exit();

void search(); 
void purchase(); 
void clothes_purchase(); 
void purchase_eval(); 

// ���� ����
ifstream fin("input.txt");
ofstream fout("output.txt");

struct clothes {
	string productname;
	string productioncompany;
	string price;
	string quantity;
	string avg_satisfaction;
	string currentID; 
};

clothes searched_clothes; 

clothes purchased_clothes[MAX_STRING]; 
int purchased_count = 0;

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
				break;
			}
			case 2:
			{
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
				break;
			}
			case 2:
			{
				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				break;
			}
			case 2: 
			{
				break;
			}
			case 3:
			{
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
			case 1: 
			{
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