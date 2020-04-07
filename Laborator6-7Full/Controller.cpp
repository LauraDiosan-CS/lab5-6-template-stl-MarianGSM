#include "pch.h"
#include "Controller.h"
#include <iostream>
using namespace std;

Ctrl::Ctrl() {

	this->r1.setSize(0);
	this->r2.setSize(0);
};

Ctrl::Ctrl(RepoT<Dulciuri, 10> a, RepoT<Moneda, 10> b) {

	this->r1 = a;
	this->r2 = b;
};

Ctrl::Ctrl(const Ctrl& c) {

	this->r1 = c.r1;
	this->r2 = c.r2;
};

Ctrl::~Ctrl() {  };

//cauta un dulce in vectorul de dulciuri
int Ctrl::searchD(Dulciuri d) {
	int poz = -1;
	std::vector<Dulciuri>v;
	v = this->r1.getAll(); cout << endl;
	for (int i = 0; i < v.size(); i++) {
		//if (d == v[i]) {};
		if ((v[i].getCod() == d.getCod()) && (v[i].getPret() == d.getPret()) && (strcmp(v[i].getNume(), d.getNume()) == 0)) {
			poz = i;
		};
	};
	return poz;
};

//cauta moneda in vector de monezi
int Ctrl::searchM(Moneda m) {
	int poz = -1;
	std::vector<Moneda>v;
	v = this->r2.getAll();
	for (int i = 0; i < this->r2.getSize(); i++) {
		if ((v[i].getNr() == m.getNr()) && (v[i].getVal() == m.getVal())) {
			poz = i;
		};
	};
	return poz;
};

void Ctrl::addD(Dulciuri d) {
	this->r1.addElem(d);
};

void Ctrl::addM(Moneda m) {
	this->r2.addElem(m);
};

void Ctrl::eliminaD(Dulciuri d) {
	int poz = this->searchD(d);
	this->r1.deleteElem(poz);
};

void Ctrl::eliminaM(Moneda m) {
	int poz = this->searchM(m);
	this->r2.deleteElem(poz);
};

void Ctrl::cumpara(Dulciuri d, int lei) {
	int rest = lei - d.getPret();
	int suma = 0;
	int lung = this->r2.getSize();  //lung vector de monede
	std::vector<Moneda> v;          //vector de monede
	v = this->r2.getAll();
	bool ok = true;
	int i = 0;
	while ((i < lung) && (ok)) {
		int k = 0; //cate monezi de o valoare 
		while ((suma <= rest) && (k <= v[i].getNr())) {
			suma += v[i].getVal();
			k++;
		};
		if (suma > rest) { suma = suma - v[i].getVal(); k--; };
		if (suma == rest) { ok = false; }
		else { i++; };
		if (k != 0)
		{//{ int aux = v[i].getNr(); v[i].setNr(aux - k); };   //k=daca sunt modificari
			cout << "Nu se poate da rest";
		}
	}
	if (ok == false) {
		cout << "se da rest= " << rest << endl;
		this->eliminaD(d);
	}
	else {
		cout << endl;
		cout << "Restul este " << rest;
	};
};

Ctrl& Ctrl::operator=(const Ctrl& c) {
	if (this != &c) {
		this->r1 = c.r1;
		this->r2 = c.r2;
	}
	return *this;
};

void Ctrl::setDulciuri(RepoT<Dulciuri, 10>aux) {
	this->r1 = aux;
};

void Ctrl::setMonede(RepoT<Moneda, 10>aux) {
	this->r2 = aux;
};


