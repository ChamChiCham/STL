#include <iostream>
#include <vector>
#include <array>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* �̵��� �� ���ܰ� �߻����� ������ ���� - noexcept
*/

extern bool check;

int main()
{
	// push_back�� �̵�, ���� ���� Ȯ���ϱ�

	check = true;
	
	// �Ҹ��ڰ� ������������ ȣ���.
	std::vector<String> v;
	v.reserve(5);

	v.emplace_back("�����Դϴ�.");
	v.emplace_back("���ʹ� dynamic Array�Դϴ�.");
	v.emplace_back("���ʹ� dynamic Array�Դϴ�.");
	v.emplace_back("���ʹ� dynamic Array�Դϴ�.");
	v.emplace_back("���ʹ� dynamic Array�Դϴ�.");

	// �Ҹ��ڰ� ������������ ȣ���.
	std::array<String, 5> ar;

	std::cout << "main end" << std::endl;
}	