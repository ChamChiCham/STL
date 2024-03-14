#include <random>
#include <fstream>
#include <iostream>
#include <array>
#include "save.h"

/**
* [문제 6] "개들"에는 class DOg객체 100개가 기록되어 있다.
* 파일은 binary모드이고 write 함수로 sizeof(Dog)*100 바이트를 기록하였다.
* 파일을 읽어 가장 num값이 큰 Dog 정보를 화면에 출력하라.
* class Dog의 멤버는 다음과 같다.
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
		return os << "글자: " << dog.c << ", 숫자: " << dog.num << std::endl;
	}
};

int main()
{
	std::array<Dog, 100> dogs;
	for (const Dog& dog : dogs)
		std::cout << dog << std::endl;

	std::ofstream out{ "개들", std::ios::binary };
	out.write((char*)dogs.data(), sizeof(Dog) * dogs.size());
}

