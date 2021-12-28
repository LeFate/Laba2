#include "SIGN.h"

SIGN::SIGN() :name(""), surname(""), zodiac_sign("")
{
	birthday[0] = 0;
	birthday[1] = 0;
	birthday[2] = 0;
}

SIGN::SIGN(const SIGN& obj)
{
	name = obj.name;
	surname = obj.surname;
	zodiac_sign = obj.zodiac_sign;
	birthday[0] = obj.birthday[0];
	birthday[1] = obj.birthday[1];
	birthday[2] = obj.birthday[2];
}

SIGN::SIGN(std::string _name, std::string _surname, std::string _zodiac_sign, int _day, int _mounth, int _year)
{
	this->name = _name;
	this->surname = _surname;
	this->zodiac_sign = _zodiac_sign;
	this->birthday[0] = _day;
	this->birthday[1] = _mounth;
	this->birthday[2] = _year;

}

std::string SIGN::getName()
{
	return std::string(this->name);
}

std::string SIGN::getSurname()
{
	return std::string(this->surname);
}

std::string SIGN::getZodiac_Sign()
{
	return std::string(this->zodiac_sign);
}

int* SIGN::getBirthday()
{
	return birthday;
}

void SIGN::setName(std::string _name)
{
	this->name = _name;

}

void SIGN::setSurname(std::string _surname)
{
	this->surname = _surname;
}

void SIGN::setZodiac_Sign(std::string _zodiac_sign)
{
	this->zodiac_sign = _zodiac_sign;
}

void SIGN::setBirthday(int day, int mounth, int year)
{
	this->birthday[0] = day;
	this->birthday[1] = mounth;
	this->birthday[2] = year;
}

SIGN& SIGN::operator=(const SIGN& obj)
{
	name = obj.name;
	surname = obj.surname;
	zodiac_sign = obj.zodiac_sign;
	birthday[0] = obj.birthday[0];
	birthday[1] = obj.birthday[1];
	birthday[2] = obj.birthday[2];
	return *this;
}

std::ostream& operator<<(std::ostream& out, const SIGN& other)
{

	out << "Name: " << other.name << "\tSurname:" << other.surname << "\tBirthday: " << other.birthday[0] << "." << other.birthday[1] << "."
		<< other.birthday[2] << "\tZoidiac sign: " << other.zodiac_sign<<"\n";
	return out;
}

bool operator<(const SIGN& ob1, const SIGN& ob2)
{
	if(ob1.birthday[2]<ob2.birthday[2])
		return true;
	else if(ob1.birthday[2] > ob2.birthday[2])
		return false;
	else {
		if (ob1.birthday[1] < ob2.birthday[1])
			return true;
		else if (ob1.birthday[1] > ob2.birthday[1])
			return false;
		else {
		
			if (ob1.birthday[0] < ob2.birthday[0])
				return true;
			else if (ob1.birthday[0] > ob2.birthday[0])
				return false;
			else
				return false;
		}
	
	}
}

bool operator>(const SIGN& ob1, const SIGN& ob2)
{
	if (ob1.birthday[2] > ob2.birthday[2])
		return true;
	else if (ob1.birthday[2] < ob2.birthday[2])
		return false;
	else {
		if (ob1.birthday[1] > ob2.birthday[1])
			return true;
		else if (ob1.birthday[1] < ob2.birthday[1])
			return false;
		else {

			if (ob1.birthday[0] > ob2.birthday[0])
				return true;
			else if (ob1.birthday[0] < ob2.birthday[0])
				return false;
			else
				return false;
		}

	}
}

bool operator==(const SIGN& ob1, const SIGN& ob2)
{
	if (ob1.birthday[2] < ob2.birthday[2])
		return false;
	else if (ob1.birthday[2] > ob2.birthday[2])
		return false;
	else {
		if (ob1.birthday[1] < ob2.birthday[1])
			return false;
		else if (ob1.birthday[1] > ob2.birthday[1])
			return false;
		else {

			if (ob1.birthday[0] < ob2.birthday[0])
				return false;
			else if (ob1.birthday[0] > ob2.birthday[0])
				return false;
			else
				return true;
		}

	}
}

bool operator!=(const SIGN& ob1, const SIGN& ob2)
{
	if (ob1.birthday[2] < ob2.birthday[2])
		return true;
	else if (ob1.birthday[2] > ob2.birthday[2])
		return true;
	else {
		if (ob1.birthday[1] < ob2.birthday[1])
			return true;
		else if (ob1.birthday[1] > ob2.birthday[1])
			return true;
		else {

			if (ob1.birthday[0] < ob2.birthday[0])
				return true;
			else if (ob1.birthday[0] > ob2.birthday[0])
				return true;
			else
				return false;
		}

	}
}
