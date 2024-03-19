#include <fstream>
#include <iostream>
#include <array>
#include "save.h"

/**
* [문제 6] "개들"에는 class Dog객체 100개가 기록되어 있다.
* 파일은 binary모드이고 write 함수로 sizeof(Dog)*100 바이트를 기록하였다.
* 파일을 읽어 가장 num값이 큰 Dog 정보를 화면에 출력하라.
* class Dog의 멤버는 다음과 같다.
* 
* -> 이 문제에 오류가 있다. 어떤 환경에서 저장했는지에 대한 정보가 필요
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
	std::ifstream in{ "개들", std::ios::binary };
	if (!in) {
		std::cout << "Cannot read files." << std::endl;
		exit(-1);
	}
	
	// 100번째 Dog, c: i num: -2228

	// 아래는 잘못된 방법이다. 일일이 하나씩 읽어오므로 비효율적
	/*Dog dog;s
	for (int i{ 0 }; i < 100; ++i) {
		in.read((char*)&dog, sizeof(Dog));
		dog.show();
	}*/

	// 미리 메모리를 만들어서 읽어오는게 더 좋다.
	std::array<Dog, 100> dogs;
	in.read((char*)dogs.data(), sizeof(Dog) * dogs.size());
	for (const auto& dog : dogs) {
		dog.show();
	}


	save("main.cpp");
}

