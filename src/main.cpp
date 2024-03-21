#include <iostream>
#include <array>
#include <string>
#include "save.h"

/**
* 실행파일의 메모리 구조 - STACK, CODE, DATA, Free Store(HEAP)
*/

using std::cout;
using std::endl;


int num;

int main()
{
	
	int num;
	int* p = new int;
	
	cout << "     STACK " << std::addressof(num) << endl;
	cout << endl;

	cout << "Free Store " << std::addressof(*p) << endl;
	cout << endl;

	cout << "      CODE " << std::addressof(main) << endl;
	cout << endl;

	cout << "      DATA " << std::addressof(::num) << endl;
	cout << endl;


	delete p;
	save("src\\main.cpp");
}

