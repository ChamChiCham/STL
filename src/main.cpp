#include <iostream>
#include "save.h"

/**
* ������ ��ü
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
		std::cout << "a Ű�� ������ ����� ����";
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