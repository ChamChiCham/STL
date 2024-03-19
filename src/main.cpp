#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"

/**
* [문제 6-2] "개들"에는  class Dog객체 100개 기록되어 있다.
* 파일은 binary모드이고 모든 객체를 한번에 write 함수로 기록하였다.
* 파일을 읽어 가장 num값이 10'000미만인 Dog 객체는 몇 개인지 화면에 출력하라.
* class Dog의 멤버는 다음과 같다.
* 
* 다음 시간-:: 실행파일의 메모리 구조 - STACK, CODE, DATA, Free Store(HEAP)
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
	in.read((char*)dogs.data(), sizeof(Dog) * dogs.size());

	// 이런 식으로 작성하면 빵점이래
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

