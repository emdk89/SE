// 헤더 선언
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// 상수 선언
#define MAX_STRING 32

// 함수 선언
void doTask();

void program_exit();

void search(); 
void purchase(); 
void clothes_purchase(); 
void purchase_eval(); 

// 변수 선언
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
{ // 파일 입출력을 위한 초기화

	doTask();
	return 0;
}

void doTask() { // 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;


	while (!is_program_exit) { // 입력파일에서 메뉴 숫자 2개를 읽기
		fin >> menu_level_1;
		fin >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
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
			case 1: // "4.1. 상품 정보 검색" 메뉴 부분
			{
				search();
				break;
			}
			case 2: // "4.2. 상품 구매" 메뉴 부분
			{
				purchase();
				break;
			}
			case 3: // "4.3. 상품 구매 내역 조회" 메뉴 부분
			{
				clothes_purchase();
				break;
			}
			case 4: // "4.4. 상품 구매만족도 평가" 메뉴 부분
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
	fout << "6.1. 종료" << endl;
}

void search()
{
	string productname;
	string productioncompany;
	string price;
	string quantity;
	string sellerID;

	fin >> productname;

	fout << "4.1. 상품 정보 검색" << endl;

	for (int i = 0; i < ::count; i++)
	{
		if (c_array[i].productname == productname)
		{
			searched_clothes = c_array[i]; // 검색 상품 구조체(searched_clothes)에 입력받은 제품 이름이 포함된 판매 상품 구조체(c_array)를 대입
			fout << c_array[i].currentID << " ";
			fout << c_array[i].productname << " ";
			fout << c_array[i].productioncompany << " ";
			fout << c_array[i].price << " ";
			fout << c_array[i].quantity << " ";
			fout << c_array[i].avg_satisfaction << endl;
			break;
		}
	}
}//세현 추가

void purchase()
{
	fout << "4.2. 상품 구매" << endl;
	for (int i = 0; i < ::count; i++)
	{
		if (c_array[i].productname == searched_clothes.productname) //검색 상품 구조체의 이름과 판매 상품 구조체의 이름이 같은 경우  
		{
			c_array[i].quantity = to_string(stoi(c_array[i].quantity) - 1); //판매 상품 구조체의 수량 -1하기
			purchased_clothes[::purchased_count++] = c_array[i]; //구매상품 구조체(purchased_clothes)에 그 판매 상품 구조체 대입 (이렇게 하면 수량이 2개 이상인 제품을 2번 이상 구매한 경우 purchased_clothes에 quantity가 실시간 반영이 안되는 오류가 있음)
			fout << c_array[i].currentID << " ";
			fout << c_array[i].productname << endl; // 판매자 id와 상품명 출력
			break;
		}
	}
}//세현 추가

void clothes_purchase()
{
	fout << "4.3. 상품 구매 내역 조회" << endl;
	for (int i = 0; i < ::purchased_count; i++) //구매상품 구조체(purchased_clothes) 내역 출력
	{
		fout << purchased_clothes[i].currentID << " ";
		fout << purchased_clothes[i].productname << " ";
		fout << purchased_clothes[i].productioncompany << " ";
		fout << purchased_clothes[i].price << " ";
		fout << purchased_clothes[i].quantity << " ";
		fout << purchased_clothes[i].avg_satisfaction << endl;
	}

}//세현 추가

void purchase_eval()
{
	string avg_satisfaction;

	fin >> avg_satisfaction;

	fout << "4.4. 상품 구매만족도 평가" << endl;
	for (int i = 0; i < ::count; i++) //판매 상품 구조체의 만족도 값 반영
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
	for (int i = 0; i < ::purchased_count; i++) //구매 상품 구조체의 만족도 값 반영
	{
		if (purchased_clothes[i].productname == searched_clothes.productname)
		{
			purchased_clothes[i].avg_satisfaction = avg_satisfaction;
			break;
		}
	}
}//세현 추가