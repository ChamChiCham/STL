#include <fstream>
#include <iostream>
#include <array>
#include "save.h"

/**
* [���� 6 ����] "����"���� ����� �𸣴� class Dog��ü�� ��ϵǾ� �ִ�.
* ������ binary����̰� ��� ��ü�� �ѹ��� write �Լ��� ����Ͽ���.
* ������ �о� ���� num���� ū Dog ������ ȭ�鿡 ����϶�.
* class Dog�� ����� ������ ����.
*/

class Dog {
private:
	char c;
	int num;

public:
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


	// in ������ ũ�⸦ filesystem�� �̿��Ͽ� ��´�.
	// ���� ������/sizeof(Dog) => 100��
	// ������ �� �� ������ ���� ������� �ڵ� new Dog[num];

	Dog dog;
	int count{};
	while (in >> dog) { count++; }

	std::cout << "���� Dog ����" << count << std::endl;
	dog.show();

	save("src\\main.cpp");
}

