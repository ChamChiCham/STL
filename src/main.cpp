#include <iostream>
#include <array>
#include <random>
#include <print>
#include <algorithm>
#include "save.h"

/**
* [문제 9] int 100개를 저장할 공간을 확보하라.
* int 100개의 값을 [1, 10000] 랜덤값으로 설정하라
* int값 100개를 c의 qsort를 사용하여 오름차순으로 정렬하라
* 정렬결과를 한 줄에 10개씩 화면에 출력하라.
* 
* callable type -> 정렬 예제에서 시작
* 
* callable type의 개수는? 무한개
* 
* 많은 데이터를 정렬할 때 정렬 기준을 어떻게 sort함수에 전달하지?
* 1. 함수 포인터
* 2. 람다
* 3. 함수 객체( function object ) - ()(함수 호출)연산자를 오버로딩한 클래스 객체
*  -> 상태를 가질 수 있다.
*/

std::default_random_engine dre;
std::uniform_int_distribution uid(1, 10000);

int cnt;

class Dog {
public:
	// 함수 호출 연산자
	bool operator()(int a, int b) {
		cnt++;
		return a > b;
	}

	void showResult() const {
		std::cout << "호출: " << cnt << std::endl;
	}

};

int main()
{
	std::array<int, 100> data;
	for (auto& n : data) {
		n = uid(dre);
	}

	// data type deduction으로 템플릿 인자 추론
	
	// std::sort를 사용하여 a를 오름차순으로 정렬하라.
	// default 정렬로 실행. a < b
	std::sort(data.begin(), data.end());

	// a > b로 하고싶으면 정렬방법을 sort함수에 제공.
	// 람다 -> code segment에 존재한다. sort에 함수 포인터 제공
	std::sort(data.begin(), data.end(), [](int a, int b) -> bool {
		return a > b;
		});

	// Dog를 통해서 정렬
	Dog dog;
	std::sort(data.begin(), data.end(), dog);

	dog.showResult();

	for (const auto& n : data) {
		std::print("{:8}", n);
	}

	// 다 다른타입. 무한개 타입을 만들 수 있다.
	// int (*g)(int, char);
	// int (*f)(int, int);

}