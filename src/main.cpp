#include <iostream>
#include <random>
#include <array>
#include <fstream>
#include <print>
#include "save.h"

/**
* [문제 2] int 100개를 저장할 공간을 만들어라.
* [0, 99'999] 범위의 값을 int 100개를 할당하라.
* TODO: 화면에 값을 출력한다.
* 
*/

// 용량이 크기 때문에 STACK 말고 DATA에 하나만 만들어서 돌려 사용한다.
std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 99'999 };

int main()
{
	std::array<int, 100> a; // 앞으로 T[N]은 사용하지 않는다. -> array<T, N> 사용

	for (auto& num : a) {
		num = uid(dre);
	}

	// [문제] 파일 "int값들.txt"에 a의 int값을 모두 저장하라.

	std::ofstream out{ "int값들.txt" };
	// C++ 언어는 garbage collection이 없음. 메모리 처리를 해준다.
	// RAII: 객체가 생성되는 시점에 Resource를 관리한다. out.close()를 사용하지 않아도 된다.

	for (const auto num : a) {
		std::print(out, "{:8}", num);
	}

	// save("src\\main.cpp");
}
