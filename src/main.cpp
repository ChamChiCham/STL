#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"

/**
* [문제 6] "개들"에는  class Dog객체 100개 기록되어 있다.
* 파일은 binary모드이고 모든 객체를 한번에 write 함수로 기록하였다.
* 파일을 읽어 가장 num값이 큰 Dog 정보를 화면에 출력하라.
* class Dog의 멤버는 다음과 같다.
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
	std::ifstream in{ "개들", std::ios::binary };
	if (!in) {
		std::cout << "Cannot read files." << std::endl;
		exit(-1);
	}
	
	// 100번째 Dog, c: i num: -2228

	std::array<Dog, 100> dogs;
	in.read((char*)&dogs, sizeof(Dog) * dogs.size());

	// 아래와 같이 코딩하는 것은 잘못된 코드이다.
	/*Dog maxDog;
	int maxValue{ std::numeric_limits<int>::min() };
	for (const auto& dog : dogs) {
		if (maxValue < dog.getNum()) {
			maxDog = dog;
			maxValue = dog.getNum();
		}
	}*/

	
	// 누가 더 큰지 판단하는 함수를 만들어야 한다. => 람다 함수
	auto pos = std::max_element(dogs.begin(), dogs.end(), [](const Dog& lhs, const Dog& rhs) -> bool {
		return lhs.getNum() < rhs.getNum();
		// 이딴식으로 쓰지 말래
		}) /* ->show() */ ;

	pos->show();
	// save("src\\main.cpp");
}

