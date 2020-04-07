
#pragma once
#include "pch.h"
#include <iostream>
using namespace std;


class Moneda {

private:
	int val; //valoarea monedei
	int nr;   //numar de monede

public:

	Moneda();
	Moneda(int v, int k);
	Moneda(const Moneda& m);
	~Moneda();

	Moneda& operator=(const Moneda& m);

	int getNr();
	int getVal();

	void setNr(int a);
	void setVal(int a);

	char* toString();
};


