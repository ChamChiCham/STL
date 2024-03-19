#include <fstream>
#include <iostream>
#include <array>
#include "save.h"

/**
* [���� 6] "����"���� class Dog��ü 100���� ��ϵǾ� �ִ�.
* ������ binary����̰� write �Լ��� sizeof(Dog)*100 ����Ʈ�� ����Ͽ���.
* ������ �о� ���� num���� ū Dog ������ ȭ�鿡 ����϶�.
* class Dog�� ����� ������ ����.
* 
* -> �� ������ ������ �ִ�. � ȯ�濡�� �����ߴ����� ���� ������ �ʿ�
*/

class Dog {
private:
	char c;
	int num;

public:
	void show() const {
		std::cout << "Dog: C:" << c << " NUM:" << num << std::endl;
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

	// �Ʒ��� �߸��� ����̴�. ������ �ϳ��� �о���Ƿ� ��ȿ����
	/*Dog dog;s
	for (int i{ 0 }; i < 100; ++i) {
		in.read((char*)&dog, sizeof(Dog));
		dog.show();
	}*/

	// �̸� �޸𸮸� ���� �о���°� �� ����.
	std::array<Dog, 100> dogs;
	in.read((char*)dogs.data(), sizeof(Dog) * dogs.size());
	for (const auto& dog : dogs) {
		dog.show();
	}


	save("main.cpp");
}

