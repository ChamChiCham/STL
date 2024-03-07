#include <string>
#include <fstream>
#include <print>
#include <vector>
#include <chrono>
#include <algorithm>

#include "save.h"

void save(std::string_view fileName)
{
	// filename을 읽기 전용으로 연다
	std::ifstream in{ fileName.data() };
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

	// 현재 time_point를 얻는다.
	auto now = std::chrono::system_clock::now(); // epoch

	// UTC 시간 형식으로 변환
	auto utc = std::chrono::system_clock::to_time_t(now);

	// 현지 시간으로 변환
	auto lt = std::localtime(&utc);

	// 한국 형식으로 출력한다. (출력스트림의 지역을 변환)
	auto old = out.imbue(std::locale("ko_KR"));

	// 시간을 기록한다.
	out.imbue(old);


	out << "===================================" << std::endl;
	out << fileName << " " << std::put_time(lt, "%x %A %X") << std::endl;
	out << "===================================" << std::endl;

	std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });
}
