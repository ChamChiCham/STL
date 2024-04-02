#include <iostream>
#include <array>
#include <random>
#include <print>
#include <algorithm>
#include "save.h"

/**
* ������ ��ü
*/

std::default_random_engine dre;
std::uniform_int_distribution uid(1, 10000);

class Dog {

};

auto g_lambda = []() {
	std::cout << "���ٷ� ����" << std::endl;
	};




int main()
{
	// �����Լ��� ����

	// class `int __cdecl main(void)'::`2'::<lambda_1>
	// ������ ���� ���·� �������� ���ٸ� �����Ѵ�.
	auto lambda = []() {
		std::cout << "���ٷ� ����" << std::endl;
		};

	// �� �̸��� �����Ϸ��� ����� �� ���̴�.
	std::cout << typeid(lambda).name() << std::endl;
	
	// ������ ��ü�� class!!

	// �̰Ͱ� �ٸ��� ����.
	// Dog dog;

	// ���� ������: ��Ģ��
	auto lambda2 = []() {
		std::cout << "���ٷ� ����" << std::endl;
		};

	std::cout << typeid(lambda2).name() << std::endl;

	auto lambda3 = []() {
		std::cout << "���ٷ� ����" << std::endl;
		};

	std::cout << typeid(lambda3).name() << std::endl;

	// ���� ����: ������ ���ٸ� ���Ÿ� ���ʿ� ������ �ǹ̰� ����.
	std::cout << typeid(g_lambda).name() << std::endl;



}