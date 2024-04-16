#include <iostream>
#include <vector>
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
	
	std::vector<String> v;

	v.push_back("�����Դϴ�.");

	std::cout << std::endl << std::endl;
	v.push_back("���ʹ� dynamic Array�Դϴ�.");

	// �� [3] -> [4]�� �̵��̰� [2] -> [5]�� �����ΰ�?
	// ���� ������ ������ ��Ƴ��� �����̴�.
	// [3] -> [4] ���ڷ� �޾Ƶ��̴°� �̸����� ����ġ�� �������̱� ������ �̵��� ȣ���Ѵ�. 
	// ������ ������� �������.
	// [2] -> [5] ���� [2]�� [5]�� �ϳ��� ������ �����ؾ��� ������ ����.

	// �̶� �� Ŭ������ �̵����� �� ����� �߸��� ���� ���ٰ� �����ϸ�
	// �̵������� �ǽ���. �̰��� noexcept
	std::cout << "main end" << std::endl;
}	