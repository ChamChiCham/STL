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

	// [문제] v에서 3을 제거하라.

	// 벽이 쳐져있어서 반복자로만 대화할수 있다.
	// 한칸 떙긴 iterator을 리턴해서
	// 한칸 떙겨야 한다는 정보를 준다.
	// 실제 지우는건 벡터가 지워야 한다.
	// erase-remove idiom이라고 부름
	
	// v.erase(std::remove(v.begin(), v.end(), 3), v.end());

	// c++20
	std::erase(v, 3);

	for (const auto& num : v) {
		std::cout << num << std::endl;
	}
	
	
}	