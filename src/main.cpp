#include <iostream>
#include <array>
#include <list>
#include <set>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* + 자기 자신을 포함 가능.
*/

int main()
{
	// variable
	// 언어가 제공하는 기본 데이터
	// int a;
	
	// a가 컨테이너
	// std::array<int, 10>는 타입
	// std::array<int, 10> a;
	
	// 컨테이너 속에 컨테이너가 들어갈 수 있다.
	// std::array< std::array<int, 10>, 10> a;

	std::array<int, 10> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	// begin()의 타입
	// std::cout << typeid(a.begin()).name();
	
	/*std::array<int, 10>::iterator p = a.begin();
	p.operator++();
	std::array<int, 10>::iterator p = a.end();*/
	
	// 같은 코드를 list, set로도 호환가능
	// sequencial container
	// std::list<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// std::set<int> a{ 6, 1, 24, 6,8,123,23 };


	for (auto p = a.begin(); p != a.end(); ++p)
	{
		// dereference operator
		std::cout << *p << std::endl;
	}

	// range-based for -> range for
	// 아래 코드는 위 코드로 컴파일러가 바꾸어 준다.
	// syntactic sugar
	for (auto& d : a) {
		std::cout << d << std::endl;
	}



}