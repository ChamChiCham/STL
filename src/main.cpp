#include <iostream>
#include <numeric>
#include <thread>
#include "save.h"

/**
* [���� 7] int num ���� �Է¹����ÿ�.
* free store���� int�� num�� �Ҵ�޾ƶ�
* int���� 1���� �����ϴ� ������ ä����.
* int���� �հ踦 ����϶�
* �� ������ ������ �ݺ��϶�.
* �ذ��ϴ� �ڵ带 ������ �����.
* 
* free store - RAII
* 
* c++���� ������� �ʵ��� �ǰ�
* 1. char*		-> std::string
* 2. T[N]		-> std::array<T,N>
* 3. T*(raw*)	-> unique_ptr, shared_ptr(����Ʈ ������)
*/

int main()
{
	
	while (true) {
		long long num;
		std::cin >> num;
		// ������ Ÿ�ӿ��� �� �� ���� ��.
		// �ӵ��� �ɸ�
		int* data{ nullptr };
		data = new int[num]{};
		std::iota(data, data + num, 1);
		long long sum{ std::accumulate(data, data + num, 0LL) };
		std::cout << sum << std::endl;
		delete[] data;

	}



	//save("src\main.cpp");
}

