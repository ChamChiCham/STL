#include <iostream>
#include <fstream>
#include <array>
#include <list>
#include <set>
#include "save.h"
#include "string.h"

/**
* STL container - Containers are objects that store other objects
*/

int main()
{
	std::array<String, 50> a;

	/**
	* [문제] STL.cpp의 단어를 a에 저장하라.
	* 길이오름파순으로 a를 정렬하라.
	* 화면에 출력하라.
	*/

	std::ifstream in{ "src\\main.cpp" };
	
	for (int i = 0; i < 50; ++i)
		in >> a[i]; // in >> std::string을 이용해서 하자

}	