#include <iostream>
#include <vector>
#include <array>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* push_back(T) - amortizer O(1)
*/

extern bool check;

int main()
{
	
	std::vector<int> v;
	std::cout << "���� - " << v.size() << std::endl;
	std::cout << "�ּ� - " << v.data() << std::endl;
	std::cout << "�ִ� - " << v.capacity() << std::endl;

	v.reserve(123);
	std::cout << "���� - " << v.size() << std::endl;
	std::cout << "�ּ� - " << v.data() << std::endl;
	std::cout << "�ִ� - " << v.capacity() << std::endl;


	


}	