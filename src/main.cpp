#include <iostream>
#include <fstream>
#include <array>
#include <list>
#include <set>
#include <algorithm>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
* 
* STL container- Sequence - vector
*/

int main()
{
	std::array<String, 50> a;

	/**
	* [����] STL.cpp�� �ܾ a�� �����϶�.
	* ���̿����ļ����� a�� �����϶�.
	* ȭ�鿡 ����϶�.
	*/

	std::ifstream in{ "src\\main.cpp" };

	for (int i = 0; i < 50; ++i) {
		in >> a[i];
	}

	std::sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getLen() < b.getLen();
		});
	
	for (int i = 0; i < 50; ++i)
		in >> a[i]; // in >> std::string�� �̿��ؼ� ����

}	