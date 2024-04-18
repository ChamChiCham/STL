#include <iostream>
#include <deque>
#include <algorithm>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* STL container - deque
* push_back / push_front
*/

extern bool check;

int main()
{
	std::deque<int> d{ 1, 2, 3, 4 };

	for (int i = 0; i < d.size(); ++i) {
		std::cout << d[i] << " - " << &d[i] << std::endl;
	}
	std::cout << std::endl;
	d.push_back(5);

	for (int i = 0; i < d.size(); ++i) {
		std::cout << d[i] << " - " << &d[i] << std::endl;
	}

	std::cout << std::endl;
	d.push_front(0);

	for (int i = 0; i < d.size(); ++i) {
		std::cout << d[i] << " - " << &d[i] << std::endl;
	}

}	