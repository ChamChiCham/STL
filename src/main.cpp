#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <print>
#include <numeric>
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
	std::vector<int> v(100);

	std::iota(v.begin(), v.end(), 1);
	
	for (int num : v) {
		std::print("{:8}", num);
	}
	
	std::println("");

	// [문제] v에서 홀수를 제거하라.
	std::erase_if(v, [](int x) {
		return x & 1;
		});

	for (int num : v) {
		std::print("{:8}", num);
	}
}	