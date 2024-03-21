#include <iostream>
#include <array>
#include <string>
#include "save.h"

/**
* 실행파일의 메모리 구조 - STACK, CODE, DATA, Free Store(HEAP)
*/

using std::cout;
using std::endl;

// default 생성자를 이용해 초기화 된다.
// int g_a[100];

// 초기화하지 않은 전역 data (bss)
// DATA 1MB -> int{} 호출 -> 실행될 때 default 초기화
char g_a[1'000'000];
// 초기화한 전역 data
// [0] -> {1}, 나머지 DATA -> int{} 호출 ->
// 메모리의 모양 이미지를 만들어서 실행파일에 그대로 저장한다.
char g_a0[1'000'000]{ 1 };



int main()
{
	// 메모리에 할당만 함. 초기화 X
	// int a[100];

	// Stack overflow
	// int a[350'000];
	cout << g_a0[999999] << endl;
	cout << g_a0[0] << endl;

	// save("src\\main.cpp");
}

