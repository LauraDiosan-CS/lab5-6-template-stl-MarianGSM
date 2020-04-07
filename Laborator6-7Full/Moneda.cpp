#include "pch.h"
#include <iostream>
#include "Moneda.h"
#include <string>
using namespace std;

Moneda::Moneda() {


	this->nr = 0;
	this->val = 0;
};


Moneda::Moneda(int v, int k) {
	cout << "[MONEDA]: constructor cu param" << endl;
	this->val = v;
	this->nr = k;
};


Moneda::Moneda(const Moneda& m) {
	cout << "[MONEDA]: copy constructor" << endl;
	this->val = m.val;
	this->nr = m.nr;
};


Moneda::~Moneda() { cout << "[MONEDA]: destructor" << endl; };

Moneda& Moneda::operator=(const Moneda& m) {
	if (this != &m) {
		this->val = m.val;
		this->nr = m.nr;
	};
	return *this;
};
=
int Moneda::getNr() { return this->nr; };


int Moneda::getVal() { return this->val; };



void Moneda::setNr(int a) { this->nr = a; };


void Moneda::setVal(int a) { this->val = a; };



char* Moneda::toString() {
	int noChars = 14;
	char* s = new char[noChars];
	char* aux = new char[5];
	char* aux1 = new char[5];

	_itoa_s(this->val, aux, 5, 10);
	_itoa_s(this->nr, aux1, 5, 10);

	strcat_s(s, noChars, aux);
	strcat_s(s, noChars, ";");
	strcat_s(s, noChars, aux1);
	strcat_s(s, noChars, ";");

	return s;
	cout << "cout toString moneda..." << endl;
};
