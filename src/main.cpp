#include <iostream>
#include <array>
#include <string>
#include "save.h"

/**
* ���������� �޸� ���� - STACK, CODE, DATA, Free Store(HEAP)
*/

using std::cout;
using std::endl;

// default �����ڸ� �̿��� �ʱ�ȭ �ȴ�.
// int g_a[100];

// �ʱ�ȭ���� ���� ���� data (bss)
// DATA 1MB -> int{} ȣ�� -> ����� �� default �ʱ�ȭ
char g_a[1'000'000];
// �ʱ�ȭ�� ���� data
// [0] -> {1}, ������ DATA -> int{} ȣ�� ->
// �޸��� ��� �̹����� ���� �������Ͽ� �״�� �����Ѵ�.
char g_a0[1'000'000]{ 1 };



int main()
{
	// �޸𸮿� �Ҵ縸 ��. �ʱ�ȭ X
	// int a[100];

	// Stack overflow
	// int a[350'000];
	cout << g_a0[999999] << endl;
	cout << g_a0[0] << endl;

	// save("src\\main.cpp");
}

