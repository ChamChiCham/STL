#include <iostream>
#include <memory>
#include "save.h"

/**
* 
* unique_ptr ��� - �ڿ��� ���� ����(ownership)
*/

class Dog {
public:
	Dog() { std::cout << "Dog ����" << std::endl; }
	~Dog() { std::cout << "Dog �Ҹ�" << std::endl; }
};

int main()
{
	// Dog 10��ü�� Free Store�� ����� ����.

	// �� ������ ���������� �����ϴ�. new�� delete�� ¦�� �Ǿ�� �ϴµ� delete�� ����?
	// std::unique_ptr<Dog[]> p{new Dog[]};

	// ��κ��� STL �Լ��� ���ø��� ���ڷ� deduction�� �� ������ make_unique�� ����ؾ� ��.
	std::unique_ptr<Dog[]> p{ std::make_unique<Dog[]>(10) };



	//save("src\main.cpp");
	std::cout << "main() ended." << std::endl; // �� ���� ������ �� p�� ��ü �Ҹ�
}

