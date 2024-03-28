#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <fstream>
#include "save.h"

/**
* [���� 8] main.cpp�� �о� ��� �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ�
* "STL�빮��.txt"�� �����ϴ�.
*/

int main()
{
	std::ifstream in{ "src\\main.cpp", std::ios::binary };

	if (!in) {
		return 1234567890;
	}

	std::ofstream out{ "STL�빮��.txt" };

	// ȿ���� �鿡�� ���� �ڵ尡 ���� ����. �׷��� �Ʒ� ��� ���
	/*char c;
	while (in.read(&c, sizeof(char))) {
		out << (c = toupper(c));
	}*/
	
	// ������ �鿡�� �̰� ����.
	// �ٵ� �ѹ��� �ٷ�� �� ����. �ѱ��ھ� ������ �δ��� �ȴ�.
	// �ϰ���� ����� ���ͷ� �ѹ��� �־ �غ���..
	std::transform(std::istreambuf_iterator<char>{in}, {},
		std::ostreambuf_iterator<char>{out}, [](char c) {
			return toupper(c);
		});




}

