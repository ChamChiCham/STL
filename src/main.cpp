#include <iostream>
#include <vector>
#include <ranges>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* STL container- Sequence - vector(dynamic array - []operator)
* dynamic(runtime) (<-> static(compile time)
*/

int main()
{
	std::vector<int> v{ 10000 };

	for (const auto& num : v | std::views::drop( v.size() - 100)) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	
	std::cout << sizeof v << std::endl;



}	