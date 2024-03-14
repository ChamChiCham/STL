#include <array>
#include <iostream>
#include <fstream>
#include <print>
#include <numeric>
#include "save.h"

/**
* [���� 4] int 100���� ������ ������ Ȯ���϶�.
* int ���� 1���� �����ϴ� ������ ä����.
* ���Ͽ� ����ض�.
*/

// �ڵ����� �ʱ�ȭ ���ش�.
// std::array<int, 100> a;


int main()
{
	// int 100���� default�� �ʱ�ȭ �ϰڴ�.
	std::array<int, 100> a{};
	
	// �Ʒ� �ڵ�� ������� �ʴ´�.
	/*int i{};
	for (int& num : a) {
		num = ++i;
	}*/

	// �Ʒ��� �ڵ带 ����Ѵ�.
	std::iota(a.begin(), a.end(), 1);

	for (auto const num : a) {
		std::print("{:8}", num);
	}

	// std::ios::binary: ��ȯ���� ���� �״�� �����϶�.
	std::ofstream out("int����.txt", std::ios::binary);

	/*for (auto const num : a) {
		std::print(out, "{} ", num);
	}*/

	// int 100���� �����ϱ� ���� �ʿ��� ������?
	// "{} "  -> write
	
	out.write((char*)a.data(), a.size() * sizeof(int));

	// �� 401����Ʈ? �ü������ text mode�� ������ �� ����Ű�� ������ 1����Ʈ���� 2����Ʈ�� �����ؼ�.


	save("src\\main.cpp");
}
