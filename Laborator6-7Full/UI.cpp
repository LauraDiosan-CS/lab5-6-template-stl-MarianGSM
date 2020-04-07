#include "pch.h"
#include <iostream>
#include "UI.h"
using namespace std;

UI::UI() { };

UI::UI(Ctrl c1) {

	this->c = c1;
};

UI::UI(const UI& u) {
	cout << " [UI]: copy constructor" << endl;
	this->c = u.c;
};

UI::~UI() { cout << " [UI]: destructor" << endl; };

UI& UI::operator=(const UI& u) {
	if (this != &u) {
		this->c = u.c;
	};
	return *this;
};

void UI::citireD() {
	cout << "CITIRE DULCE " << endl;
	cout << "dati nume dulce " << endl;
	char* nume = new char[15];
	cin >> nume;
	int cod = 0;
	cout << "dati cod dulce" << endl;
	cin >> cod;
	int pret = 0;
	cout << "dati pret dulce" << endl;
	cin >> pret;
	Dulciuri d1(nume, cod, pret);
	this->c.addD(d1);
};

void UI::citireM() {
	cout << "CITIRE MONEDA " << endl;
	int cod = 0;
	cout << "dati valoarea monedei " << endl;
	cin >> cod;
	int pret = 0;
	cout << "dati nr de monede " << endl;
	cin >> pret;
	Moneda m1(cod, pret);
	this->c.addM(m1);
};

void UI::meniu() {
	cout << "MENIU" << endl;
	cout << "1 = Citire dulciuri..." << endl;
	cout << "2 = Citire monede..." << endl;
	cout << "3 = Alegere produs..." << endl;
	cout << "4 = Cumparare produs ales / Tranzactia se poate sau nu realiza..." << endl;
	cout << "5 = EXIT APLICATIE" << endl;

};

void UI::run() {
	this->meniu();
	int opt = 0;
	int poz = 0;
	Dulciuri aux;
	while (opt != 5) {
		cout << "dati optiune " << endl;
		cin >> opt;
		if (opt == 1) {
			cout << "dati nr de dulciuri " << endl;
			int n = 0;
			cin >> n;
			for (int i = 0; i < n; i++) { this->citireD(); };
		}
		else if (opt == 2) {
			cout << "dati nr tip de monede " << endl;
			int n = 0;
			cin >> n;
			for (int i = 0; i < n; i++) { this->citireM(); };
		}
		else if (opt == 3) {
			cout << "[RUN]: cititre date produs ales " << endl;
			cout << "dati nume dulce " << endl;
			char* nume = new char[15];
			cin >> nume;
			int cod = 0;
			cout << "dati cod dulce" << endl;
			cin >> cod;
			int pret = 0;
			cout << "dati pret dulce" << endl;
			cin >> pret;
			Dulciuri d1(nume, cod, pret);
			poz = this->c.searchD(d1);
			if (poz == -1) { cout << "Produs ales nu exista " << endl; }
			else { cout << "produs selectat " << endl; aux = d1; };
		}
		else if (opt == 4) {
			cout << "Cumparare produs. Introduceti suma de plata " << endl;
			int lei = 0; cin >> lei;
			this->c.cumpara(aux, lei);
		}
		else if (opt == 5) { cout << "EXIT APLICATIE " << endl; }
		else { cout << "optiune invalida"; };
	}
};