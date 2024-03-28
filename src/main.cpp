#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <fstream>
#include "save.h"

/**
* [문제 8] main.cpp을 읽어 모든 소문자를 대문자로 변환하여
* "STL대문자.txt"에 저장하다.
*/

int main()
{
	std::ifstream in{ "src\\main.cpp", std::ios::binary };

	if (!in) {
		return 1234567890;
	}

	std::ofstream out{ "STL대문자.txt" };

	// 효율성 면에는 다음 코드가 제일 좋음. 그러나 아래 방법 사용
	/*char c;
	while (in.read(&c, sizeof(char))) {
		out << (c = toupper(c));
	}*/
	
	// 가독성 면에서 이게 좋음.
	// 근데 한번에 다루면 더 좋음. 한글자씩 읽으면 부담이 된다.
	// 하고싶은 사람은 벡터로 한번에 넣어서 해봐라..
	std::transform(std::istreambuf_iterator<char>{in}, {},
		std::ostreambuf_iterator<char>{out}, [](char c) {
			return toupper(c);
		});




}

