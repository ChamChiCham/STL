#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"

/**
* [���� 6-2] "����"����  class Dog��ü 100�� ��ϵǾ� �ִ�.
* ������ binary����̰� ��� ��ü�� �ѹ��� write �Լ��� ����Ͽ���.
* ������ �о� ���� num���� 10'000�̸��� Dog ��ü�� �� ������ ȭ�鿡 ����϶�.
* class Dog�� ����� ������ ����.
* 
* ���� �ð�-:: ���������� �޸� ���� - STACK, CODE, DATA, Free Store(HEAP)
*/

class Dog {
private:
	char c{};
	int num{};

public:

	int getNum() const { return num; }

	void show() const {
		std::cout << "Dog: C:" << c << " NUM:" << num << std::endl;
	}

	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		return is.read((char*)&dog, sizeof(Dog));
	}
};

int main()
{
	std::ifstream in{ "����", std::ios::binary };
	if (!in) {
		std::cout << "Cannot read files." << std::endl;
		exit(-1);
	}
	
	// 100��° Dog, c: i num: -2228

	std::array<Dog, 100> dogs;
	in.read((char*)dogs.data(), sizeof(Dog) * dogs.size());

	// �̷� ������ �ۼ��ϸ� �����̷�
	/*int cnt{};
	for (const auto& dog : dogs) {
		if (dog.getNum() < 10'000) { cnt++; }
	}*/

	auto cnt{ std::count_if(dogs.begin(), dogs.end(), [](const Dog& dog) {
		if (10'000 > dog.getNum()) {
			return true;
		}
		return false;
		}) };
	std::cout << cnt << std::endl;



	// save("src\\main.cpp");
}

