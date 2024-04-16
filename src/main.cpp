#include <iostream>
#include <vector>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* STL container- Sequence - vector(dynamic array - []operator)
* dynamic(runtime) (<-> static(compile time)
*/

extern bool check;

int main()
{
	check = true;
	
	std::vector<String> s;
	s.reserve(10); // ������ �̸� �����ϰ� �������. - �� �޸𸮸� Ȯ���ϱ� ���� ����� �ʿ䰡 ����.

	// std::cout << "s�� �뷮" << s.capacity() << std::endl;

	// std::cout << "���� �߰� -=-=-=-=-=-=" << std::endl << std::endl;
	s.emplace_back("2024��");
	// O(1): ����ð�(�̻簡�� �ʴ´ٸ�) -> armotizes constant time.

	// std::cout << "���� �߰� -=-=-=-=-=-=" << std::endl << std::endl;
	s.emplace_back("4��");

	// std::cout << "���� �߰� -=-=-=-=-=-=" << std::endl << std::endl;
	s.emplace_back("11��");

	std::cout << "���� ����" << std::endl << std::endl;

	// [����] Ű���忡�� �Է��� int���� �հ��� ��հ��� ����϶�.
	// �̷��� vector ���
	
	std::vector<int> v{ std::istream_iterator<int>{std::cin}, {} };

	for (int& num : v) {
		std::cout << num << " ";
	}

}	