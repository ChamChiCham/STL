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
		"12983478912374",
		"1925789012835708912357",
		"353845834590341581592",
		"12418247128212",
		"12312312323312312556789"
	};

	// [���� 10] a�� �� String�� �����ϴ� ���ڸ� ������������ �����϶�
	for (auto& s : a) {
		std::sort(s.begin(), s.end());
	}

	for (const auto& s : a) {
		std::cout << s << std::endl;
	}
}