#include <iostream>
#include <vector>
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
*/

extern bool check;

int main()
{
	// [����] STL.cpp�� �ִ� �ҹ����� ���Ƚ���� ����϶�.
	// a - 10
	// b - 8
	// c - 0
	// ...
	// z - 2

	std::array<int, 26> alpha_counts{};
	std::ifstream in{ "src\\main.cpp" };
	
	if (not in) {
		return -1;
	}

	char ch{};
	while (in >> ch) {
		if (islower(ch)) {
			alpha_counts[ch - 'a']++;
		}
	}

	for (int i = 0; i < 26; ++i) {
		std::cout << static_cast<char>(i + 'a') << " - " << alpha_counts[i] << std::endl;
	}

}	