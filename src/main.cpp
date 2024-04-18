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

	// 벡터는 덧붙일 때 용이한 자료구조.
	// 중간에 지울일이 있으면 다른 자료구조를 생각하는 것이 더 좋음.
	std::vector<String> v{ "1", "2", "3", "4", "5"};

	// [문제] v에서 3을 제거하라.

	std::erase(v, "3");

	for (const String& s : v) {
		std::cout << s << std::endl;
	}
	
	std::cout << "메인 끝" << std::endl;
}	