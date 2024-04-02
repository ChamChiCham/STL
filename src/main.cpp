#include <iostream>
#include <array>
#include <random>
#include <print>
#include <algorithm>
#include "save.h"

/**
* 람다의 정체
*/

std::default_random_engine dre;
std::uniform_int_distribution uid(1, 10000);

class Dog {

};

auto g_lambda = []() {
	std::cout << "람다래 나는" << std::endl;
	};




int main()
{
	// 람다함수의 정의

	// class `int __cdecl main(void)'::`2'::<lambda_1>
	// 다음과 같은 형태로 지역에서 람다를 선언한다.
	auto lambda = []() {
		std::cout << "람다래 나는" << std::endl;
		};

	// 이 이름은 컴파일러가 만들어 준 것이다.
	std::cout << typeid(lambda).name() << std::endl;
	
	// 람다의 정체는 class!!

	// 이것과 다름이 없음.
	// Dog dog;

	// 람다 여러개: 규칙성
	auto lambda2 = []() {
		std::cout << "람다래 나는" << std::endl;
		};

	std::cout << typeid(lambda2).name() << std::endl;

	auto lambda3 = []() {
		std::cout << "람다래 나는" << std::endl;
		};

	std::cout << typeid(lambda3).name() << std::endl;

	// 전역 람다: 전역에 람다를 쓸거면 애초에 람다의 의미가 없음.
	std::cout << typeid(g_lambda).name() << std::endl;



}