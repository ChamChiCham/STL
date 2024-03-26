#include <iostream>
#include <numeric>
#include <thread>
#include "save.h"

/**
* [���� 7] int num ���� �Է¹����ÿ�.
* free store���� int�� num�� �Ҵ�޾ƶ�
* int���� 1���� �����ϴ� ������ ä����.
* int���� �հ踦 ����϶�
* �� ������ ������ �ݺ��϶�.
* �ذ��ϴ� �ڵ带 ������ �����.
* 
* free store - RAII
* 
* c++���� ������� �ʵ��� �ǰ�
* 1. char*		-> std::string
* 2. T[N]		-> std::array<T,N>
* 3. T*(raw*)	-> unique_ptr, shared_ptr(����Ʈ ������)
* 
* RAII - �޸�, FILE, j thread, mutex
*/

class Dog {
public:
	Dog() { std::cout << "Dog ����" << std::endl; }
	~Dog() { std::cout << "Dog �Ҹ�" << std::endl; }
};

class ����Ʈ������ {
private:
	Dog* p;


public:
	����Ʈ������(Dog* p) : p{ p } {}
	~����Ʈ������() { delete p; }
};
void f()
{
	std::cout << "f ����." << std::endl;
	����Ʈ������ p{ new Dog };

	throw 1234;

	std::cout << "f ��." << std::endl;
}

int main()
{
	std::cout << "main ����." << std::endl;

	try {
		f();
	}
	catch (...) { // ... elipses

		// stack�� �ִ� ��� ��ü���� �Ҹ��ڸ� ȣ�� => �޸𸮰� ���� ����.
		std::cout << "���ܹ߻�" << std::endl;
	}


	/**
	* ������ �߻��ϴ� ��Ȳ
	* 1. memory leak
	* 2. dangling pointer 
	* 3. �����ΰ� ������ �� ���
	* -> RAII (�޸𸮸� �ڵ�ȭ�ϴ� ���)
	*/

	//save("src\main.cpp");

	std::cout << "main ��." << std::endl;
}

