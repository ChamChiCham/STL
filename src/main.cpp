#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"

/**
* [���� 6] "����"����  class Dog��ü 100�� ��ϵǾ� �ִ�.
* ������ binary����̰� ��� ��ü�� �ѹ��� write �Լ��� ����Ͽ���.
* ������ �о� ���� num���� ū Dog ������ ȭ�鿡 ����϶�.
* class Dog�� ����� ������ ����.
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
	in.read((char*)&dogs, sizeof(Dog) * dogs.size());

	// �Ʒ��� ���� �ڵ��ϴ� ���� �߸��� �ڵ��̴�.
	/*Dog maxDog;
	int maxValue{ std::numeric_limits<int>::min() };
	for (const auto& dog : dogs) {
		if (maxValue < dog.getNum()) {
			maxDog = dog;
			maxValue = dog.getNum();
		}
	}*/

	
	// ���� �� ū�� �Ǵ��ϴ� �Լ��� ������ �Ѵ�. => ���� �Լ�
	auto pos = std::max_element(dogs.begin(), dogs.end(), [](const Dog& lhs, const Dog& rhs) -> bool {
		return lhs.getNum() < rhs.getNum();
		// �̵������� ���� ����
		}) /* ->show() */ ;

	pos->show();
	// save("src\\main.cpp");
}

