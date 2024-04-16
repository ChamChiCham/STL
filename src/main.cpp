#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* push_back(T) - amortizer O(1)
*/

extern bool check;

int main()
{
	// uniform initialization 
	std::vector<int> v{ 1, 2, 3, 4, 5, 3, 3, 3};

	// initialize_list
	for (int num : {1, 2, 3, 4, 5}) {
		std::cout << num << std::endl;
	}

	// [����] v���� 3�� �����϶�.

	// ���� �����־ �ݺ��ڷθ� ��ȭ�Ҽ� �ִ�.
	// ��ĭ ���� iterator�� �����ؼ�
	// ��ĭ ���ܾ� �Ѵٴ� ������ �ش�.
	// ���� ����°� ���Ͱ� ������ �Ѵ�.
	// erase-remove idiom�̶�� �θ�
	
	// v.erase(std::remove(v.begin(), v.end(), 3), v.end());

	// c++20
	std::erase(v, 3);

	for (const auto& num : v) {
		std::cout << num << std::endl;
	}
	
	
}	