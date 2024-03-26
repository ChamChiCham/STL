#include <iostream>
#include <numeric>
#include <thread>
#include "save.h"

/**
* [문제 7] int num 값을 입력받으시오.
* free store에서 int를 num개 할당받아라
* int값을 1부터 시작하는 정수로 채워라.
* int값의 합계를 출력하라
* 이 과정을 영원히 반복하라.
* 해결하는 코드를 답지에 적어라.
* 
* free store - RAII
* 
* c++언어에서 사용하지 않도록 권고
* 1. char*		-> std::string
* 2. T[N]		-> std::array<T,N>
* 3. T*(raw*)	-> unique_ptr, shared_ptr(스마트 포인터)
* 
* RAII - 메모리, FILE, j thread, mutex
*/

class Dog {
public:
	Dog() { std::cout << "Dog 생성" << std::endl; }
	~Dog() { std::cout << "Dog 소멸" << std::endl; }
};

class 스마트포인터 {
private:
	Dog* p;


public:
	스마트포인터(Dog* p) : p{ p } {}
	~스마트포인터() { delete p; }
};
void f()
{
	std::cout << "f 시작." << std::endl;
	스마트포인터 p{ new Dog };

	throw 1234;

	std::cout << "f 끝." << std::endl;
}

int main()
{
	std::cout << "main 시작." << std::endl;

	try {
		f();
	}
	catch (...) { // ... elipses

		// stack에 있는 모든 객체들의 소멸자를 호출 => 메모리가 새지 않음.
		std::cout << "예외발생" << std::endl;
	}


	/**
	* 문제가 발생하는 상황
	* 1. memory leak
	* 2. dangling pointer 
	* 3. 제어경로가 복잡해 질 경우
	* -> RAII (메모리를 자동화하는 기술)
	*/

	//save("src\main.cpp");

	std::cout << "main 끝." << std::endl;
}

