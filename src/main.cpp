#include <iostream>
#include <array>
#include <random>
#include <print>
#include "save.h"

/**
* [문제 9] int 100개를 저장할 공간을 확보하라.
* int 100개의 값을 [1, 10000] 랜덤값으로 설정하라
* int값 100개를 c의 qsort를 사용하여 오름차순으로 정렬하라
* 정렬결과를 한 줄에 10개씩 화면에 출력하라.
* 
* callable type -> 정렬 예제에서 시작
*/

std::default_random_engine dre;
std::uniform_int_distribution uid(1, 10000);

int main()
{
	std::array<int, 100> data;
	for (auto& n : data) {
		n = uid(dre);
	}

	for (const auto& n : data) {
		std::print("{:8}", n);
	}
	std::cout << std::endl;


	// 여기서 qsort로 정렬한다 - qsort는 c함수이지만 generic 함수이다
	// qsort( 어디 몇개 한개의 크기는 너안의 정렬방법을 알려줘,)

	// 함수를 변수처럼 사용???
	//	int (*vari)(const void*, const void*) = func;

	qsort(data.data(), data.size(), sizeof(int), [] /*함수 자체 시작번지*/ (const void* lhs, const void* rhs) -> int {
		return *(int*)lhs - *(int*)rhs;
		});
		

	for (const auto& n : data) {
		std::print("{:8}", n);
	}

}

