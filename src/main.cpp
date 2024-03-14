#include <array>
#include <iostream>
#include <fstream>
#include <print>
#include <numeric>
#include "save.h"

/**
* [문제 4] int 100개를 저장할 공간을 확보하라.
* int 값을 1부터 시작하는 정수로 채워라.
* 파일에 기록해라.
*/

// 자동으로 초기화 해준다.
// std::array<int, 100> a;


int main()
{
	// int 100개를 default로 초기화 하겠다.
	std::array<int, 100> a{};
	
	// 아래 코드는 사용하지 않는다.
	/*int i{};
	for (int& num : a) {
		num = ++i;
	}*/

	// 아래의 코드를 사용한다.
	std::iota(a.begin(), a.end(), 1);

	for (auto const num : a) {
		std::print("{:8}", num);
	}

	// std::ios::binary: 변환하지 말고 그대로 저장하라.
	std::ofstream out("int값들.txt", std::ios::binary);

	/*for (auto const num : a) {
		std::print(out, "{} ", num);
	}*/

	// int 100개를 저장하기 위해 필요한 공간은?
	// "{} "  -> write
	
	out.write((char*)a.data(), a.size() * sizeof(int));

	// 왜 401바이트? 운영체제에서 text mode로 저장할 때 엔터키를 원래는 1바이트에서 2바이트로 저장해서.


	save("src\\main.cpp");
}
