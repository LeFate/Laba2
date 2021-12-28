#pragma once
#include<iostream>
#include<fstream>
#include"SIGN.h"
class DataBase
{

	SIGN* arr;
	int size;
public:
	DataBase();
	~DataBase();
	void sort(SIGN* arr, int size);
	void find();
	int getSize();
	void show();
	void push_back(SIGN obj);
	void push_front(SIGN obj);
	SIGN pop_back();
	SIGN pop_front();
};

