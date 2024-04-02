#include <iostream>
#include <functional>
#include <memory>
#include "save.h"

/**
* 
*/

class String
{
	size_t len;
	std::unique_ptr<char[]> p{};

public:
	String(const char* s)
		: len(strlen(s))
	{
		p = std::make_unique<char[]>(len);
		memcpy(p.get(), s, len);
	}

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (size_t i{ 0 }; i < s.len; ++i) {
			os << s.p[i];
		}
		os << std::endl;
		return os;
	}
};

int main()
{
	String s{ "STL ���θ� ���� Ŭ����" };
	std::cout << s << std::endl;


}