#include <iostream>
#include <functional>
#include "save.h"

/**
* 
* 
* -> 모든 호출 가능타입을 대표하는 클래스가 -> function
*/



void f( /*int를 리턴하고 인자로 int, int를 받을 수 있다면 어떤 거라도 다 좋아 */
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
	// 집에가서 dog 넣어봐 뻗을거임 아마
	f([](int, int) -> int { return 333; });
	f(x);


}