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
	// [문제] 키보드에서 입력한 단어를 오름차순으로 정렬 후 출력하라.
	check = true;
	std::vector<std::string> v{ std::istream_iterator<std::string>{std::cin}, {} };

	std::sort(v.begin(), v.end());

	for (const std::string& s : v) {
		std::cout << s << std::endl;
	}
}	