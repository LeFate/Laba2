#include <iostream>
#include"DataBase.h"
#include <Windows.h>
#include"CounterLongWords.h"

int main()
{

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	bool flag = true;
	int n;
	try
	{
		while (flag) {
			std::cout << "Main menu:\n";
			std::cout << "1. First mission\n";
			std::cout << "2. Second mission\n";
			std::cout << "3. Exit\n";
			std::cin >> n;
			if (n == 1)
				DataBase db;
			else if (n == 2)
				CounterLongWords c;
			else 
				flag = false;
			
		
		}
		
	}
	catch (const char* exeption)
	{
		std::cout << exeption << "\n";
	}

}

