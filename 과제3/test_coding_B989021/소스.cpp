// 헤더 선언
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// 상수 선언
#define MAX_STRING 32

// 함수 선언
void doTask();
void registeration();
void clothes_onsale();
void clothes_complete();
void sales_stat();

// 변수 선언
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
{ // 파일 입출력을 위한 초기화

		doTask();
		return 0;
}


void doTask() { // 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;


	while (!fin.eof()) { // 입력파일에서 메뉴 숫자 2개를 읽기
		fin >> menu_level_1;
		fin >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1) {
		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // "3.1. 판매의류 등록“ 메뉴 부분
			{
				registeration();
				break;
			}
			case 2: // "3.2 등록 상품 조회" 메뉴 부분 
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

		fout << "3.1. 판매 의류 등록" <<endl;

		fout << productname <<" ";
		fout << productioncompany << " ";
		fout << price << " ";
		fout << quantity << endl;
	}

	
	void clothes_onsale()
	{
		fout << "3.2. 등록 상품 조회" << endl;
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
		fout << "3.3 판매 완료 상품 조회" << endl;
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
		fout << "5.1 판매 상품 통계" << endl;


		for (int i = 0; i < ::count; i++)
		{
			fout << c_array[i].productname << " ";
			fout << (stoi(c_array[i].price) * stoi(c_array[i].quantity)) << " ";
			fout << c_array[i].avg_satisfaction << endl;

		}
	}

