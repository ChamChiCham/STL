#include <iostream>
#include "save.h"


/**
* [문제] main을 변경하지 않고 의도대로 실행되도록 change()을 선언하고 정의하라.
*/

class Dog {
private:
	int value;

public:
	Dog(int _value)
		: value(_value)
	{}
	
	 friend std::ostream& operator<<(std::ostream& out, const Dog& dog) {
		out << dog.value;
		return out;
	}
};


// 템플릿 함수 선언
template <class T>
void change(T&, T&);

// 함수의 이름은 주소
// 함수의 시작 주소가 CODE영역에 있다.
int main()
{
	// 지역 변수는 STACK에 생성된다.
	Dog a{ 1 }, b{ 2 };
	// 컴파일러가 함수를 찾는 순서
	// 1. change(Dog, Dog)
	// 2. change(Dog&, Dog&)
	// * 이때, 1과 2중 하나만 사용해야 한다. (모호함)
	// 3. 템플릿 코드 확장 
	//

	// CODE에 있는 change 함수로 가기 전 STACK에 진행상황 저장
	change(a, b);

	std::cout << a << " " << b << std::endl;
	save("src\\main.cpp");
}

// 템플릿 함수 정의
// but 일반적으로 템플릿 함수의 선언과 정의는 한번에 작성한다.
// Generic code
template <class T>
void change(T& a, T& b)
{
	std::swap(a, b);
}
