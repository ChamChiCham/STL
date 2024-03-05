/**
* file을 save하는 함수 제작
*/

#include <iostream>
#include <string>
#include <fstream>
#include <print>
#include <vector>
#include <algorithm>

void save(std::string_view);

int main()
{
	std::cout << "2024 STL" << std::endl;
	save("src\\main.cpp");
}

void save(std::string_view fileName)
{
	// filename을 읽기 전용으로 연다
	std::ifstream in{fileName.data()};
	if (!in) {
		std::println("save(): Failed to open {}", fileName);
		exit(0);
	}

	// filename의 정보를 확인
	// std::println("{}", sizeof in);
	// std::println("{}", typeid(in).name());

	// 저장할 파일 이름
	std::ofstream out{ "2024 1학기 STL 강의저장.txt", std::ios::app };

	// 읽을 파일의 내용을 읽어 쓸 파일
	// STL 자료구조와 알고리즘을 이용하여 기록한다 (좋은건 아니다) 
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };

	std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });


}