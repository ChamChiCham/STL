#include <iostream>
#include <list>
#include <array>
#include <algorithm>
#include <print>
#include <numeric>
#include <fstream>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* push back(T) - amortized O(1)
* erase (N)
*/

extern bool check;

int main()
{
	std::list<String> v{ "1", "2", "4", "5"};

	auto p = v.begin();
	++p;
	++p;

	// [문제] v에서 3을 추가하라.

	check = true;
	v.emplace(p, "3");
	check = false;

	for (const String& s : v) {
		std::cout << s << std::endl;
	}
	
}	