#include <iostream>
#include <array>
#include <list>
#include <set>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
*/

int main()
{
	std::array<int, 3> a{ 1, 2, 3 };

	// a[0] + sizeof(int) * -10
	//std::cout << a[-10] << std::endl;
	//std::cout << a[10] << std::endl;

	int num;
	std::cin >> num;

	// �Ϲ����� ��Ȳ
	/*if (0 < num and num < 2)
		std::cout << a[num] << std::endl;*/

	// ������ Ȯ���ϰ� ������ �̷���
	/*try {
		std::cout << a.at(num) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}*/


}	