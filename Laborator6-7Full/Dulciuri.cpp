#include "pch.h"
#include "Dulciuri.h"
#include <iostream>
#include<string>
using namespace std;






//Descr: crearea unui dulce
//In: -
//Out: o instanta a unui dulce
Dulciuri::Dulciuri() {

	this->nume = NULL;
	this->cod = 0;
	this->pret = 0;
}


Dulciuri::Dulciuri(char* n, int c, int p) {

	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
	this->pret = p;
	this->cod = c;
}


Dulciuri::Dulciuri(const Dulciuri& c) {

	this->nume = new char[strlen(c.nume) + 1];
	strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
	this->pret = c.pret;
	this->cod = c.cod;
}

//Descr: distrugerea unui dulce
//In: un dulce 
//Out: - (destructor)
Dulciuri::~Dulciuri() {
	if (this->nume != NULL) {

		delete[]this->nume;
		this->nume = NULL;
	}
	
}

Dulciuri& Dulciuri::operator=(const Dulciuri& c) {
	if (this != &c) {
		setNume(c.nume);
		pret = c.pret;
		cod = c.cod;
	}
	return *this;
}


int Dulciuri::getPret() {
	
	return this->pret;
}

char* Dulciuri::getNume() {
	return this->nume;
}

int Dulciuri::getCod() {
	return this->cod;
}


void Dulciuri::setPret(int p) {
	this->pret = p;
}

void Dulciuri::setCod(int z) {
	this->cod = z;
}



void Dulciuri::setNume(char* t) {
	delete[]this->nume;
	this->nume = new char[strlen(t) + 1];
	strcpy_s(this->nume, strlen(t) + 1, t);
}


char* Dulciuri::toString() {
	if (this->nume != NULL) {
		int noChars = strlen(this->nume) + 1 + 5 + 1 + 5 + 2;
		char* aux = new char[5];
		char* aux1 = new char[5];
		char* s = new char[noChars];
		strcpy_s(s, noChars, this->nume);
		strcat_s(s, noChars, ";");
		_itoa_s(this->pret, aux, 5, 10);
		_itoa_s(this->cod, aux1, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, ";");
		strcat_s(s, noChars, aux1);
		strcat_s(s, noChars, ";");


		if (aux) {
			delete[] aux;
			aux = NULL;
		}

		strcat_s(s, noChars, ";");
		return s;
		cout << "cout tostring dulciuri..." << endl;
	}
	else
	{
		char* v = new char[1];
		strcpy_s(v, 1, "");
		return v;
	}
}

ostream& operator<<(ostream& os, const Dulciuri& f) {
	os << f.nume << " " << f.cod << " " << f.pret << endl;
	return os;
}