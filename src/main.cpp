#include <iostream>
#include "save.h"

/**
* 람다의 정체
*/


void jump() {
	std::cout << "jump" << std::endl;
}

void slide() {
	std::cout << "slide" << std::endl;
}


int main()
{
	void (*f)() = jump;
	while (true) {
		std::cout << "a 키를 누르면 기능을 수행";
		char c;
		std::cin >> c;

		if ('a' == c) {
			f = jump;
		}

		if ('s' == c) {
			if (f == jump) {
				f = slide;
			}
			else {
				f = jump;
			}
		}
		f();
	}


}