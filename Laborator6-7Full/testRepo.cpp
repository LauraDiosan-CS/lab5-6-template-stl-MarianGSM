#include "pch.h"
#include "testRepo.h"

#include <vector>
#include "Dulciuri.h"
#include <iostream>
#include <cassert>
using namespace std;

void tests() {
	std::vector<Dulciuri> v;
	RepoT<Dulciuri, 10>r;
	int n = 3;
	char* type = new char[10];
	strcpy_s(type, 10, "ciocolata");
	char* type1 = new char[6];
	strcpy_s(type1, 5, "corn");
	char* type2 = new char[8];
	strcpy_s(type2, 8, "strudel");
	Dulciuri d1(type, 34567, 4);
	Dulciuri d2(type1, 15242, 7);
	Dulciuri d3(type2, 47112, 3);
	r.addElem(d1);
	r.addElem(d2);
	r.addElem(d3);
	v = r.getAll();

	assert(v[0].getCod() == 34567);
	assert(v[0].getPret() == 4);
	assert(strcmp(type, v[0].getNume()) == 0);

	assert(v[1].getCod() == 15242);
	assert(v[1].getPret() == 7);
	assert(strcmp(type1, v[1].getNume()) == 0);

	assert(v[2].getCod() == 47112);
	assert(v[2].getPret() == 3);
	assert(strcmp(type2, v[2].getNume()) == 0);

	std::cout << "vectorul de dulciuri : " << endl;
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << endl;
	}
	std::cout << "testele Repo au trecut" << endl;
}