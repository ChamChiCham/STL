#include <iostream>
#include <functional>
#include "save.h"

/**
* 
* 
* -> ��� ȣ�� ����Ÿ���� ��ǥ�ϴ� Ŭ������ -> function
*/



void f( /*int�� �����ϰ� ���ڷ� int, int�� ���� �� �ִٸ� � �Ŷ� �� ���� */
		std::function<int(int, int)> y
)
{
	std::cout << y(3, 5) << std::endl;
}

int x(int a, int b)
{
	return a * b;
}

int main()
{
	// �������� dog �־�� �������� �Ƹ�
	f([](int, int) -> int { return 333; });
	f(x);


}