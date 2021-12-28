#pragma once
#include<string>
#include<iostream>

class SIGN
{

	std::string name;
	std::string surname;
	std::string zodiac_sign;
	int birthday[3];

public:

	SIGN();
	SIGN(const SIGN& obj);
	SIGN(std::string name, std::string surname, std::string zodiac_sign, int day, int mounth, int year);

	std::string getName();
	std::string getSurname();
	std::string getZodiac_Sign();
	int* getBirthday();

	void setName(std::string _name);
	void setSurname(std::string _surname);
	void setZodiac_Sign(std::string _zodiac_sign);
	void setBirthday(int day, int mounth, int year);


	SIGN& operator=(const SIGN& obj);
	friend std::ostream& operator<<(std::ostream& out, const SIGN& other);
	friend bool operator<(const SIGN& ob1, const SIGN& ob2);
	friend bool operator>(const SIGN& ob1, const SIGN& ob2);
	friend bool operator==(const SIGN& ob1, const SIGN& ob2);
	friend bool operator!=(const SIGN& ob1, const SIGN& ob2);

};

