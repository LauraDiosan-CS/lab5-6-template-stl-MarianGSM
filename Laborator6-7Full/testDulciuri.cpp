#pragma once
#include "pch.h"
#include "testDulciuri.h"
#include "Dulciuri.h"
#include <assert.h>
#include<iostream>
using namespace std;

void testD() {
	char* tip = new char[5];
	strcpy_s(tip, 4, "aba");
	Dulciuri d = Dulciuri(tip, 456, 9);
	char* tip1 = new char[5];
	strcpy_s(tip, 4, "cdc");
	Dulciuri d1 = Dulciuri(tip1, 123, 4);

	d.setCod(666);
	d.setPret(10);
	d.setNume(tip1);



	assert(d.getCod() == 666);
	assert(strcmp(d.getNume(), tip1) == 0);
	assert(d.getPret() == 10);
	assert(d1.getCod() == 123);
	assert(d1.getPret() == 4);
	assert(strcmp(d1.getNume(), d1.getNume()) == 0);
	cout << "teste clasa Dulciuri functioneaza" << endl;
}
