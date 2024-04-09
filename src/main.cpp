#include <iostream>
#include <array>
#include <list>
#include <set>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* + �ڱ� �ڽ��� ���� ����.
*/

int main()
{
	// variable
	// �� �����ϴ� �⺻ ������
	// int a;
	
	// a�� �����̳�
	// std::array<int, 10>�� Ÿ��
	// std::array<int, 10> a;
	
	// �����̳� �ӿ� �����̳ʰ� �� �� �ִ�.
	// std::array< std::array<int, 10>, 10> a;

	std::array<int, 10> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	// begin()�� Ÿ��
	// std::cout << typeid(a.begin()).name();
	
	/*std::array<int, 10>::iterator p = a.begin();
	p.operator++();
	std::array<int, 10>::iterator p = a.end();*/
	
	// ���� �ڵ带 list, set�ε� ȣȯ����
	// sequencial container
	// std::list<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// std::set<int> a{ 6, 1, 24, 6,8,123,23 };


	for (auto p = a.begin(); p != a.end(); ++p)
	{
		// dereference operator
		std::cout << *p << std::endl;
	}

	// range-based for -> range for
	// �Ʒ� �ڵ�� �� �ڵ�� �����Ϸ��� �ٲپ� �ش�.
	// syntactic sugar
	for (auto& d : a) {
		std::cout << d << std::endl;
	}



}