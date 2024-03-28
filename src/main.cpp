#include <iostream>
#include <memory>
#include "save.h"

/**
* 
* unique_ptr 사용 - 자원을 독점 소유(ownership)
*/

class Dog {
public:
	Dog() { std::cout << "Dog 생성" << std::endl; }
	~Dog() { std::cout << "Dog 소멸" << std::endl; }
};

int main()
{
	// Dog 10객체를 Free Store에 만들어 본다.

	// 이 문장은 문제없지만 불편하다. new와 delete가 짝이 되어야 하는데 delete가 없네?
	// std::unique_ptr<Dog[]> p{new Dog[]};

	// 대부분의 STL 함수는 탬플릿의 인자로 deduction할 수 있으나 make_unique는 명시해야 함.
	std::unique_ptr<Dog[]> p{ std::make_unique<Dog[]>(10) };



	//save("src\main.cpp");
	std::cout << "main() ended." << std::endl; // 이 문장 수행한 후 p의 객체 소멸
}

