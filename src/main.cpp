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


// ���ø� �Լ� ����
template <class T>
void change(T&, T&);

// �Լ��� �̸��� �ּ�
// �Լ��� ���� �ּҰ� CODE������ �ִ�.
int main()
{
	// ���� ������ STACK�� �����ȴ�.
	Dog a{ 1 }, b{ 2 };
	// �����Ϸ��� �Լ��� ã�� ����
	// 1. change(Dog, Dog)
	// 2. change(Dog&, Dog&)
	// * �̶�, 1�� 2�� �ϳ��� ����ؾ� �Ѵ�. (��ȣ��)
	// 3. ���ø� �ڵ� Ȯ�� 
	//

	// CODE�� �ִ� change �Լ��� ���� �� STACK�� �����Ȳ ����
	change(a, b);

	std::cout << a << " " << b << std::endl;
	save("src\\main.cpp");
}

// ���ø� �Լ� ����
// but �Ϲ������� ���ø� �Լ��� ����� ���Ǵ� �ѹ��� �ۼ��Ѵ�.
// Generic code
template <class T>
void change(T& a, T& b)
{
	std::swap(a, b);
}
