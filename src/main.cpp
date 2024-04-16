#include <iostream>
#include <vector>
#include <array>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* 이동할 때 예외가 발생하지 않음을 보장 - noexcept
*/

extern bool check;

int main()
{
	// push_back의 이동, 복사 순서 확인하기

	check = true;
	
	// 소멸자가 오름차순으로 호출됨.
	std::vector<String> v;
	v.reserve(5);

	v.emplace_back("벡터입니다.");
	v.emplace_back("벡터는 dynamic Array입니다.");
	v.emplace_back("벡터는 dynamic Array입니다.");
	v.emplace_back("벡터는 dynamic Array입니다.");
	v.emplace_back("벡터는 dynamic Array입니다.");

	// 소멸자가 내림차순으로 호출됨.
	std::array<String, 5> ar;

	std::cout << "main end" << std::endl;
}	