#include "pch.h"
#include <iostream>
#include "testDulciuri.h"
#include "testRepo.h"
#include "UI.h"
using namespace std;

int main()
{
	testD();
	tests();
	UI u = UI();
	u.run();

	return 0;
}


