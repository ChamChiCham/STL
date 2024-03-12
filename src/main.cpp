#include <iostream>
#include <random>
#include <array>
#include <fstream>
#include <print>
#include "save.h"

/**
* [���� 2] int 100���� ������ ������ ������.
* [0, 99'999] ������ ���� int 100���� �Ҵ��϶�.
* TODO: ȭ�鿡 ���� ����Ѵ�.
* 
*/

// �뷮�� ũ�� ������ STACK ���� DATA�� �ϳ��� ���� ���� ����Ѵ�.
std::default_random_engine dre;
std::uniform_int_distribution uid{ 0, 99'999 };

int main()
{
	std::array<int, 100> a; // ������ T[N]�� ������� �ʴ´�. -> array<T, N> ���

	for (auto& num : a) {
		num = uid(dre);
	}

	// [����] ���� "int����.txt"�� a�� int���� ��� �����϶�.

	std::ofstream out{ "int����.txt" };
	// C++ ���� garbage collection�� ����. �޸� ó���� ���ش�.
	// RAII: ��ü�� �����Ǵ� ������ Resource�� �����Ѵ�. out.close()�� ������� �ʾƵ� �ȴ�.

	for (const auto num : a) {
		std::print(out, "{:8}", num);
	}

	// save("src\\main.cpp");
}
