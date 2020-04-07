#pragma once
#include "pch.h"
#include <iostream>
#include "Repo.h"
#include "Dulciuri.h"
#include "Moneda.h"
using namespace std;



class Ctrl {
private:
	RepoT<Dulciuri, 10> r1;  //repo de dulciuri
	RepoT<Moneda, 10> r2;    //repo de monezi

public:

	Ctrl();      //constructor
	Ctrl(RepoT<Dulciuri, 10> a, RepoT<Moneda, 10> b);//constructor cu parametri
	Ctrl(const Ctrl& c); // constructor de copiere
	~Ctrl(); //destructor
	Ctrl& operator=(const Ctrl& c);

	int searchD(Dulciuri d); //cauta dulce
	int searchM(Moneda m); //cauta moneda

	void eliminaD(Dulciuri d); //elimina dulce
	void eliminaM(Moneda m); //elimina moneda

	//void updateD(char* n, int c,int p,int poz);
	//void updateM(int v, int n, int poz);

	void addD(Dulciuri d); //adauga dulce
	void addM(Moneda m); //adauga moneda

	void cumpara(Dulciuri d, int lei); //cumpara dulce
	//char* toString();

	void setMonede(RepoT<Moneda, 10> aux);
	void setDulciuri(RepoT<Dulciuri, 10> aux);

};

