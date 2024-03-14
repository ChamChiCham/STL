#include <random>
#include <fstream>
#include <iostream>
#include <array>
#include "save.h"

/**
* [���� 6] "����"���� class DOg��ü 100���� ��ϵǾ� �ִ�.
* ������ binary����̰� write �Լ��� sizeof(Dog)*100 ����Ʈ�� ����Ͽ���.
* ������ �о� ���� num���� ū Dog ������ ȭ�鿡 ����϶�.
* class Dog�� ����� ������ ����.
*/

std::default_random_engine dre;
std::uniform_int_distribution<int> uidC{'a', 'z'};
std::uniform_int_distribution uidNum{ -9'999, 9'999 };


class Dog {
private:
	char c{ static_cast<char>(uidC(dre)) };
	int num{ uidNum(dre) };
public:
	friend std::ostream& operator<< (std::ostream& os, const Dog& dog) {
		return os << "����: " << dog.c << ", ����: " << dog.num << std::endl;
	}
};

int main()
{
	std::array<Dog, 100> dogs;
	for (const Dog& dog : dogs)
		std::cout << dog << std::endl;

	std::ofstream out{ "����", std::ios::binary };
	out.write((char*)dogs.data(), sizeof(Dog) * dogs.size());
}

