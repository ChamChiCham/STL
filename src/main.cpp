#include <iostream>
#include <numeric>
#include <thread>
#include "save.h"

/**
* [문제 7] int num 값을 입력받으시오.
* free store에서 int를 num개 할당받아라
* int값을 1부터 시작하는 정수로 채워라.
* int값의 합계를 출력하라
* 이 과정을 영원히 반복하라.
* 해결하는 코드를 답지에 적어라.
* 
* free store - RAII
* 
* c++언어에서 사용하지 않도록 권고
* 1. char*		-> std::string
* 2. T[N]		-> std::array<T,N>
* 3. T*(raw*)	-> unique_ptr, shared_ptr(스마트 포인터)
*/

int main()
{
	
	while (true) {
		long long num;
		std::cin >> num;
		// 컴파일 타임에는 알 수 없는 값.
		// 속도가 걸림
		int* data{ nullptr };
		data = new int[num]{};
		std::iota(data, data + num, 1);
		long long sum{ std::accumulate(data, data + num, 0LL) };
		std::cout << sum << std::endl;
		delete[] data;

	}



	//save("src\main.cpp");
}

