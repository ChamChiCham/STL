#include <iostream>
#include <random>
#include <print>
#include <algorithm>
#include <array>
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

	sizeof a;

	for (auto& num : a) {
		num = uid(dre);
	}

	for (const auto num : a) {
		std::print("{:8}", num);
		// std::print(std::cout, "{:8}", a[i]);
		// ���� cout ���� �ٸ� ostream�� ����ϰ� ������ cout �ڸ��� ����Ѵ�.
	}
	std::cout << std::endl;

	// [���� 2-1] a�� ���� ���� ū ���� ã�� ����Ͻÿ�.

	// stl ��� ���� �ڵ�.
	auto max = a[0];
	// auto max = std::numeric_limits<int>::min();
	for (const auto num : a) {
		if (num > max) { max = num; }
	}
	std::println("Max Value: {}", max);
	
	// stl ��� ���� �ڵ�.
	std::println("Max Value: {}", *std::max_element(a.begin(), a.end()));
	// �̶� end�� ������ ������ �����̴�.

	// stl�� ����ϴ� ����
	// 1. stl �ڵ�� ������ ������ �������� �Ǿ� �ִ�.
	// 2. ������ § �ڵ忡�� �߻��� �� �ִ� ������ �ذ�
	// 3. �ڵ� �ۼ� �ӵ� ���


	// save("src\\main.cpp");
}