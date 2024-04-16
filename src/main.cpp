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
	std::vector<char> v;
	/*while (true) {
		if (v.size() == v.capacity()) {
			std::cout << "개수 - " << v.size() << std::endl;
			std::cout << "주소 - " << v.data() << std::endl;
			std::cout << "최대 - " << v.capacity() << std::endl;
		}
		v.push_back(0);
	}*/

	std::cout << "vector<int> 최대 몇개? - " << v.max_size() << std::endl;
}	