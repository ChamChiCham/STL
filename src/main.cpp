#include <iostream>
#include <fstream>
#include <algorithm>
#include <print>
#include "save.h"

/**
* [���� 3] "int����.txt"���� �� ������ �𸣴� int���� �ִ�.
* ���� ū ���� ã�� ȭ�鿡 ����϶�.
*/

int main()
{
	std::ifstream in{ "int����.txt" };
	if (!in) { exit(-1); }

	int num;

	//std::print("Max Value: {}", std::max_element(std::ifstream_iterator<int>{in}, {}));
	std::print("Max Value: {}", *std::max_element(std::istream_iterator<int>{in}, {}));
	// save("src\\main.cpp");
}
