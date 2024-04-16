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
	s.reserve(10); // 공간을 미리 마련하고 사용하자. - 새 메모리를 확보하기 위한 노력이 필요가 없음.

	// std::cout << "s의 용량" << s.capacity() << std::endl;

	// std::cout << "원소 추가 -=-=-=-=-=-=" << std::endl << std::endl;
	s.emplace_back("2024년");
	// O(1): 상수시간(이사가지 않는다면) -> armotizes constant time.

	// std::cout << "원소 추가 -=-=-=-=-=-=" << std::endl << std::endl;
	s.emplace_back("4월");

	// std::cout << "원소 추가 -=-=-=-=-=-=" << std::endl << std::endl;
	s.emplace_back("11일");

	std::cout << "메인 종료" << std::endl << std::endl;

	// [문제] 키보드에서 입력한 int값의 합계의 평균값을 출력하라.
	// 이럴떄 vector 사용
	
	std::vector<int> v{ std::istream_iterator<int>{std::cin}, {} };

	for (int& num : v) {
		std::cout << num << " ";
	}

}	