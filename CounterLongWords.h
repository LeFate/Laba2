#pragma once
#include<fstream>
#include<iostream>


class CounterLongWords
{
public:
	CounterLongWords();
	std::string find(std::string path);
	std::string findMax(std::string line);

};

