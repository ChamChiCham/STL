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
	// [����] Ű���忡�� �Է��� �ܾ ������������ ���� �� ����϶�.
	check = true;
	std::vector<std::string> v{ std::istream_iterator<std::string>{std::cin}, {} };

	std::sort(v.begin(), v.end());

	for (const std::string& s : v) {
		std::cout << s << std::endl;
	}
}	