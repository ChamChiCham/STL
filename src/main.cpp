#include <iostream>
#include "save.h"


/**
* [����] main�� �������� �ʰ� �ǵ���� ����ǵ��� change()�� �����ϰ� �����϶�.
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

// �Լ��� ���� �ּҰ� CODE������ �ִ�.
int main()
{
	// ���� ������ STACK�� �����ȴ�.
	Dog a{ 1 }, b{ 2 };

	// CODE�� �ִ� change �Լ��� ���� �� STACK�� �����Ȳ ����
	change(a, b);

	std::cout << a << " " << b << std::endl;
	save("src\\main.cpp");
}

template <typename T>
inline void change(T& a, T& b)
{
	std::swap<T>(a, b);
}
