#include <iostream>
#include <array>
#include <random>
#include <print>
#include <algorithm>
#include "save.h"

/**
* [���� 9] int 100���� ������ ������ Ȯ���϶�.
* int 100���� ���� [1, 10000] ���������� �����϶�
* int�� 100���� c�� qsort�� ����Ͽ� ������������ �����϶�
* ���İ���� �� �ٿ� 10���� ȭ�鿡 ����϶�.
* 
* callable type -> ���� �������� ����
* 
* callable type�� ������? ���Ѱ�
* 
* ���� �����͸� ������ �� ���� ������ ��� sort�Լ��� ��������?
* 1. �Լ� ������
* 2. ����
* 3. �Լ� ��ü( function object ) - ()(�Լ� ȣ��)�����ڸ� �����ε��� Ŭ���� ��ü
*  -> ���¸� ���� �� �ִ�.
*/

std::default_random_engine dre;
std::uniform_int_distribution uid(1, 10000);

int cnt;

class Dog {
public:
	// �Լ� ȣ�� ������
	bool operator()(int a, int b) {
		cnt++;
		return a > b;
	}

	void showResult() const {
		std::cout << "ȣ��: " << cnt << std::endl;
	}

};

int main()
{
	std::array<int, 100> data;
	for (auto& n : data) {
		n = uid(dre);
	}

	// data type deduction���� ���ø� ���� �߷�
	
	// std::sort�� ����Ͽ� a�� ������������ �����϶�.
	// default ���ķ� ����. a < b
	std::sort(data.begin(), data.end());

	// a > b�� �ϰ������ ���Ĺ���� sort�Լ��� ����.
	// ���� -> code segment�� �����Ѵ�. sort�� �Լ� ������ ����
	std::sort(data.begin(), data.end(), [](int a, int b) -> bool {
		return a > b;
		});

	// Dog�� ���ؼ� ����
	Dog dog;
	std::sort(data.begin(), data.end(), dog);

	dog.showResult();

	for (const auto& n : data) {
		std::print("{:8}", n);
	}

	// �� �ٸ�Ÿ��. ���Ѱ� Ÿ���� ���� �� �ִ�.
	// int (*g)(int, char);
	// int (*f)(int, int);

}