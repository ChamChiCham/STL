#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"
#include "string.h"

/**
* String ����
*/

extern bool check;


int main()
{
	std::array<String, 5> a{
		"2024��", "4��", "4��", "�����", "�ູ�� STL"
	};

	for (const auto& s : a) {
		std::cout << s << std::endl;
	}

	// a�� ���� ������������ �����϶�.
	check = true;
	std::sort(a.begin(), a.end(), [](const String& lhs, const String& rhs) {
		return lhs.size() < rhs.size();
		});
	check = false;

	for (const auto& s : a) {
		std::cout << s << std::endl;
	}
}