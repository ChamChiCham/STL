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



template <typename T>
inline void change(T&, T&);

// 함수의 시작 주소가 CODE영역에 있다.
int main()
{
	// 지역 변수는 STACK에 생성된다.
	Dog a{ 1 }, b{ 2 };

	// CODE에 있는 change 함수로 가기 전 STACK에 진행상황 저장
	change(a, b);

	std::cout << a << " " << b << std::endl;
	save("src\\main.cpp");
}

template <typename T>
inline void change(T& a, T& b)
{
	std::swap<T>(a, b);
}
