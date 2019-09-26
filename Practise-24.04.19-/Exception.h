#pragma once
#pragma warning(disable : 4996)// отклб\ючение ошибки 4996
#include<cstring>
#include<iostream>
using namespace std;


class Exception
{
	int Line;// строка, где возникло исключение
	char *File;//файл,где произошло исключение
	char *funck;//функция,где произошло исключение
	char *Descr;//тип исключения
public:
	Exception(int i,const char *f,const char *fu, const char *d)
	{
		Line = i;
		int n = strlen(f) + 1;
		File = new char[n];
		strcpy(File, f);
		n = strlen(fu) + 1;
		funck = new char[n];
		strcpy(funck, fu);
		n = strlen(d) + 1;
		Descr = new char[n];
		strcpy(Descr, d);
	};
	Exception(const Exception& a)
	{
		Line = a.Line;
		int n = strlen(a.File);
		File = new char[n];
		strcpy(File, a.File);
		n = strlen(a.funck);
		funck = new char[n];
		strcpy(funck, a.funck);
		n = strlen(a.Descr);
		Descr = new char[n];
		strcpy(Descr, a.Descr);
	};
	Exception()
	{
		delete[] File;
		delete[] funck;
		delete[] Descr;
	};
	void print()
	{
		std::cout << Descr << std::endl;
		std::cout <<"Humber file: " <<File << std::endl;
		std::cout <<"Name function: "<< funck << std::endl;
		std::cout <<"Numder line: "<< Line << std::endl;
	};
};