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
	check = true;

	// ���ʹ� ������ �� ������ �ڷᱸ��.
	// �߰��� �������� ������ �ٸ� �ڷᱸ���� �����ϴ� ���� �� ����.
	std::vector<String> v{ "1", "2", "3", "4", "5"};

	// [����] v���� 3�� �����϶�.

	std::erase(v, "3");

	for (const String& s : v) {
		std::cout << s << std::endl;
	}
	
	std::cout << "���� ��" << std::endl;
}	