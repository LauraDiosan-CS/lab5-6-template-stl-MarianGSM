#pragma once
#include "pch.h"
#include <iostream>
using namespace std;

class Dulciuri {
private:
	char* nume;
	int cod;
	int pret;
public:
	Dulciuri();
	Dulciuri(char* n, int c, int p);
	Dulciuri(const Dulciuri& c);
	~Dulciuri();
	Dulciuri& operator=(const Dulciuri& c);

	char* getNume();
	int getPret();
	int getCod();

	void setNume(char* t);
	void setPret(int p);
	void setCod(int);

	char* toString();

	friend ostream& operator<<(ostream&, const Dulciuri&);
};
