#pragma once
#include "pch.h"
#include "Controller.h"
#include <iostream>
using namespace std;



class UI {
private:
	Ctrl c;
public:
	UI();
	UI(Ctrl c1);
	UI(const UI& u);
	~UI();
	UI& operator=(const UI&);

	void meniu();
	void run();

	void citireD();
	void Afisare();
	void citireM();

};

