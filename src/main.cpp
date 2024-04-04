#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "string.h"

/**
* String 구현
*/

extern bool check;


int main()
{
	std::array<String, 5> a{
		"2024년", "4월", "4일", "목요일", "행복한 STL"
	};

	for (const auto& s : a) {
		std::cout << s << std::endl;
	}

	// a를 길이 오름차순으로 정렬하라.
	check = true;
	std::sort(a.begin(), a.end(), [](const String& lhs, const String& rhs) {
		return lhs.size() < rhs.size();
		});
	check = false;

	for (const auto& s : a) {
		std::cout << s << std::endl;
	}
}