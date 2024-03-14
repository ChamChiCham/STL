#include <iostream>
#include <fstream>
#include <algorithm>
#include <print>
#include "save.h"

/**
* [문제 3] "int값들.txt"에는 몇 개인지 모르는 int값이 있다.
* 제일 큰 값을 찾아 화면에 출력하라.
*/

int main()
{
	std::ifstream in{ "int값들.txt" };
	if (!in) { exit(-1); }

	int num;

	//std::print("Max Value: {}", std::max_element(std::ifstream_iterator<int>{in}, {}));
	std::print("Max Value: {}", *std::max_element(std::istream_iterator<int>{in}, {}));
	// save("src\\main.cpp");
}
