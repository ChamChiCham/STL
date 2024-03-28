#include <iostream>
#include <array>
#include <random>
#include <print>
#include "save.h"

/**
* [���� 9] int 100���� ������ ������ Ȯ���϶�.
* int 100���� ���� [1, 10000] ���������� �����϶�
* int�� 100���� c�� qsort�� ����Ͽ� ������������ �����϶�
* ���İ���� �� �ٿ� 10���� ȭ�鿡 ����϶�.
* 
* callable type -> ���� �������� ����
*/

std::default_random_engine dre;
std::uniform_int_distribution uid(1, 10000);

int main()
{
	std::array<int, 100> data;
	for (auto& n : data) {
		n = uid(dre);
	}

	for (const auto& n : data) {
		std::print("{:8}", n);
	}
	std::cout << std::endl;


	// ���⼭ qsort�� �����Ѵ� - qsort�� c�Լ������� generic �Լ��̴�
	// qsort( ��� � �Ѱ��� ũ��� �ʾ��� ���Ĺ���� �˷���,)

	// �Լ��� ����ó�� ���???
	//	int (*vari)(const void*, const void*) = func;

	qsort(data.data(), data.size(), sizeof(int), [] /*�Լ� ��ü ���۹���*/ (const void* lhs, const void* rhs) -> int {
		return *(int*)lhs - *(int*)rhs;
		});
		

	for (const auto& n : data) {
		std::print("{:8}", n);
	}

}

