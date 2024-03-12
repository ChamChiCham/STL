#include <iostream>
#include <random>
#include <print>
#include <algorithm>
#include <array>
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

	sizeof a;

	for (auto& num : a) {
		num = uid(dre);
	}

	for (const auto num : a) {
		std::print("{:8}", num);
		// std::print(std::cout, "{:8}", a[i]);
		// 내가 cout 말고 다른 ostream을 사용하고 싶으면 cout 자리에 명시한다.
	}
	std::cout << std::endl;

	// [문제 2-1] a의 값중 가장 큰 값을 찾아 출력하시오.

	// stl 사용 전의 코드.
	auto max = a[0];
	// auto max = std::numeric_limits<int>::min();
	for (const auto num : a) {
		if (num > max) { max = num; }
	}
	std::println("Max Value: {}", max);
	
	// stl 사용 이후 코드.
	std::println("Max Value: {}", *std::max_element(a.begin(), a.end()));
	// 이때 end는 마지막 원소의 다음이다.

	// stl을 사용하는 이유
	// 1. stl 코드는 최적의 성능을 가지도록 되어 있다.
	// 2. 손으로 짠 코드에서 발생할 수 있는 오류를 해결
	// 3. 코드 작성 속도 향상


	// save("src\\main.cpp");
}