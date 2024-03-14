#include <fstream>
#include <print>
#include <array>
#include "save.h"

/**
* [문제 5] int값 1000개를 "int값들"에 저장하였다
* 파일은 binary 모드로 열었고
* 값은 메모리 크기 그대로 4'000바이트를 기록하였다.
* int값 중 제일 큰 값을 찾아 화면에 출력하라.
*/


int main()
{
	std::array<int, 1000> a{};
	
	std::ifstream in("int값들", std::ios::binary);

	if (!in) { exit(-1); }

	in.read((char*)a.data(), a.size() * sizeof(int));

	std::print("Max value: {}", *std::max_element(a.begin(), a.end()));
}
