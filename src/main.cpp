#include <fstream>
#include <print>
#include <array>
#include "save.h"

/**
* [���� 5] int�� 1000���� "int����"�� �����Ͽ���
* ������ binary ���� ������
* ���� �޸� ũ�� �״�� 4'000����Ʈ�� ����Ͽ���.
* int�� �� ���� ū ���� ã�� ȭ�鿡 ����϶�.
*/


int main()
{
	std::array<int, 1000> a{};
	
	std::ifstream in("int����", std::ios::binary);

	if (!in) { exit(-1); }

	in.read((char*)a.data(), a.size() * sizeof(int));

	std::print("Max value: {}", *std::max_element(a.begin(), a.end()));
}
