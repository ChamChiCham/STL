#include <iostream>
#include <vector>
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
	
	std::vector<String> v;

	v.push_back("벡터입니다.");

	std::cout << std::endl << std::endl;
	v.push_back("벡터는 dynamic Array입니다.");

	// 왜 [3] -> [4]는 이동이고 [2] -> [5]는 복사인가?
	// 복사 동작은 원본이 살아남는 동작이다.
	// [3] -> [4] 인자로 받아들이는게 이름없는 무가치한 데이터이기 때문에 이동을 호출한다. 
	// 정보가 사라져도 상관없음.
	// [2] -> [5] 에서 [2]나 [5]중 하나는 무조건 보존해야할 소중한 정보.

	// 이때 이 클래스가 이동동작 중 절대로 잘못될 일이 없다고 보장하면
	// 이동동작을 실시함. 이것이 noexcept
	std::cout << "main end" << std::endl;
}	