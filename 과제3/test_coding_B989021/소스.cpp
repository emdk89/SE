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

// ���� ����
ifstream fin("input.txt");
ofstream fout("output.txt");




struct clothes {
	string productname;
	string productioncompany;
	string price;
	string quantity;
	string avg_satisfaction;
};

clothes c_array[MAX_STRING];
int count = 0;

int main()
{ // ���� ������� ���� �ʱ�ȭ

		doTask();
		return 0;
}


void doTask() { // �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;


	while (!fin.eof()) { // �Է����Ͽ��� �޴� ���� 2���� �б�
		fin >> menu_level_1;
		fin >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1) {
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
		case 5:
		{
			switch (menu_level_2) {
			case 1: // 
			{
				sales_stat();
				break;
			}
			}
		}

		}
	}
	return;
}

	void registeration()
	{
		string productname;
		string productioncompany;
		string price;
		string quantity;


		fin >> productname;
		fin >> productioncompany;
		fin >> price;
		fin >> quantity;

		struct clothes c1;
		c1.productname = productname;
		c1.productioncompany = productioncompany;
		c1.price = price;
		c1.quantity = quantity;

		c_array[::count++] = c1;

		fout << "3.1. �Ǹ� �Ƿ� ���" <<endl;

		fout << productname <<" ";
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

