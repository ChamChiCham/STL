#include <fstream>
#include <iostream>
#include <array>
#include "save.h"

/**
* [문제 6 변형] "개들"에는 몇개인지 모르는 class Dog객체가 기록되어 있다.
* 파일은 binary모드이고 모든 객체를 한번에 write 함수로 기록하였다.
* 파일을 읽어 가장 num값이 큰 Dog 정보를 화면에 출력하라.
* class Dog의 멤버는 다음과 같다.
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
	std::ifstream in{ "개들", std::ios::binary };
	if (!in) {
		std::cout << "Cannot read files." << std::endl;
		exit(-1);
	}
	
	// 100번째 Dog, c: i num: -2228


	// in 파일의 크기를 filesystem을 이용하여 얻는다.
	// 파일 사이즈/sizeof(Dog) => 100개
	// 개수를 모를 떈 다음과 같은 방법으로 코딩 new Dog[num];

	Dog dog;
	int count{};
	while (in >> dog) { count++; }

	std::cout << "읽은 Dog 개수" << count << std::endl;
	dog.show();

	save("src\\main.cpp");
}

