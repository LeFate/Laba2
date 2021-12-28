#include "DataBase.h"

DataBase::DataBase(): size(0),arr(nullptr)
{
	
	bool flag = true;
	int day = 0, mounth = 0, year = 0;
	int n = 0;
	std::string name, surname, zodiac;
	while (flag) {
		try {
			std::cout << "\t\tMenu\t\t\n";
			std::cout << "1. Add person\n";
			std::cout << "2. Delete person\n";
			std::cout << "3. Change data\n";
			std::cout << "4. Show all persons\n";
			std::cout << "5. Find person\n";
			std::cout << "6. Exit\n";
			std::cout << "Enter number of command: ";
			std::cin >> n;


			switch (n)
			{
			case 1:

				std::cout << "\nEnter name: ";
				std::cin >> name;
				std::cout << "\nEnter surname: ";
				std::cin >> surname;
				std::cout << "\nEnter zodiac sign: ";
				std::cin >> zodiac;

				std::cout << "\nEnter day: ";
				std::cin >> day;
				std::cout << "\nEnter mounth: ";
				std::cin >> mounth;
				std::cout << "\nEnter year: ";
				std::cin >> year;
				push_back(SIGN(name, surname, zodiac, day, mounth, year));
				sort(arr, size);
				break;
			case 2:
				pop_back();
				sort(arr, size);
				break;
			case 3:
				show();
				std::cout << "\nEnter index: ";
				std::cin >> n;
				std::cout << "\nEnter name: ";
				std::cin >> name;
				std::cout << "\nEnter surname: ";
				std::cin >> surname;
				std::cout << "\nEnter zodiac sign: ";
				std::cin >> zodiac;

				std::cout << "\nEnter day: ";
				std::cin >> day;
				std::cout << "\nEnter mounth: ";
				std::cin >> mounth;
				std::cout << "\nEnter year: ";
				std::cin >> year;

				arr[n].setName(name);
				arr[n].setSurname(surname);
				arr[n].setZodiac_Sign(zodiac);
				arr[n].setBirthday(day, mounth, year);
				break;

			case 4:
				show();
				break;
			case 5:
				find();
				break;

			default:
				flag = false;
				break;
			}
		}
		catch (const char* exeption) {
			std::cout << exeption << "\n";
		}


	}
	
}

DataBase::~DataBase()
{
	
	if (size != 0)
		delete[] arr;
	


}

void DataBase::sort(SIGN* arr, int size)
{	
	if (size == 0)
		throw "Empty array";
	int i = 0, j = size - 1;
	SIGN x = arr[size / 2];

	do {
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;

		if (i <= j) {
			SIGN tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;


		}
	} while (i <= j);

	if (j > 0)
		sort(arr, j + 1);
	if (i < size)
		sort(&arr[i], size - i);
}

void DataBase::find()
{
	int cnt = 0;
	std::string surname;
	std::cout << "\nEnter surname for find: ";
	std::cin >> surname;

	for (int i = 0; i < size; i++) {

		if (surname == arr[i].getSurname()) {
			std::cout << arr[i] << "\n";
			cnt++;
		}
	}
	if (cnt == 0)
		std::cout << "Not found person with surname " << surname << "\n";
}

int DataBase::getSize()
{
    return this->size;
}

void DataBase::show()
{
	if (size == 0)
		throw "empty array";

	for (int i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
}

void DataBase::push_back(SIGN obj)
{
	SIGN* arrNew = new SIGN[size + 1];

	if (size != 0) {
		for (int i = 0; i < size; i++)
			arrNew[i] = arr[i];
		arrNew[size] = obj;
	}
	else
		arrNew[size] = obj;

	size++;
	SIGN* buf = arr;
	arr = arrNew;
	delete[] buf;
}

void DataBase::push_front(SIGN obj)
{
	SIGN* arrNew = new SIGN[size + 1];

	if (size != 0) {
		arrNew[0] = obj;
		for (int i = 1; i < size + 1; i++)
			arrNew[i] = arr[i - 1];

	}
	else
		arrNew[size] = obj;

	size++;
	SIGN* bufferPtr = arr;
	arr = arrNew;
	delete[] bufferPtr;

}

SIGN DataBase::pop_back()
{
	if (size == 0)
		throw "empty array";


	SIGN* arrNew = new SIGN[size - 1];
	if (size == 1) {
		SIGN popData(arr[0]);
		delete[] arr;
		arr = nullptr;
		size--;
		return SIGN(popData);
	}
	for (int i = 0; i < size - 1; i++)
		arrNew[i] = arr[i];

	SIGN popData(arr[size - 1]), * bufptr = arr;
	arr = arrNew;
	delete[] bufptr;
	size--;

	return SIGN(popData);
}

SIGN DataBase::pop_front()
{
	if (size == 0)
		throw "empty list";


	SIGN popData(arr[0]), * bufferPtr = arr;
	SIGN* arrNew = new SIGN[size - 1];//выделили память под новый массив
	if (size == 1) {
		delete[] arr;
		arr = nullptr;
		size--;
		return SIGN(popData);
	}
	for (int i = 1; i < size; i++)//начиная со второго элемента заполняем новый массив
		arrNew[i - 1] = arr[i];

	arr = arrNew;
	delete[] bufferPtr;
	size--;
	return SIGN(popData);
	
}
