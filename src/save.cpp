#include <string>
#include <fstream>
#include <print>
#include <vector>
#include <chrono>
#include <algorithm>

#include "save.h"

void save(std::string_view fileName)
{
	// filename�� �б� �������� ����
	std::ifstream in{ fileName.data() };
	if (!in) {
		std::println("save(): Failed to open {}", fileName);
		exit(0);
	}

	// filename�� ������ Ȯ��
	// std::println("{}", sizeof in);
	// std::println("{}", typeid(in).name());

	// ������ ���� �̸�
	std::ofstream out{ "2024 1�б� STL ��������.txt", std::ios::app };

	// ���� ������ ������ �о� �� ����
	// STL �ڷᱸ���� �˰����� �̿��Ͽ� ����Ѵ� (������ �ƴϴ�) 
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };

	// ���� time_point�� ��´�.
	auto now = std::chrono::system_clock::now(); // epoch

	// UTC �ð� �������� ��ȯ
	auto utc = std::chrono::system_clock::to_time_t(now);

	// ���� �ð����� ��ȯ
	auto lt = std::localtime(&utc);

	// �ѱ� �������� ����Ѵ�. (��½�Ʈ���� ������ ��ȯ)
	auto old = out.imbue(std::locale("ko_KR"));

	// �ð��� ����Ѵ�.
	out.imbue(old);


	out << "===================================" << std::endl;
	out << fileName << " " << std::put_time(lt, "%x %A %X") << std::endl;
	out << "===================================" << std::endl;

	std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });
}
