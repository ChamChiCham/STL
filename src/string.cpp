#include "string.h"
#include <iostream>
#include <print>

size_t String::uid{};

String::String()
	: id{++uid}
{
	std::println("[{}] - 생성자, 개수: {}, 주소: {}",
		id, len, static_cast<void*>(p.get()));
}

String::~String()
{
	std::println("[{}] - 소멸자, 개수: {}, 주소: {}",
		id, len, static_cast<void*>(p.get()));
}

String::String(const char* s)
	: len(strlen(s))
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);
	std::println("[{}] - char* 생성자, 개수: {}, 주소: {}",
		id, len, static_cast<void*>(p.get()));
}

String::String(const String& other)
	: len{ other.len }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	std::println("[{}] - 복사 생성자, 개수: {}, 주소: {}",
		id, len, static_cast<void*>(p.get()));
}

String& String::operator=(const String& lhs)
{
	if (this == &lhs) { return *this; }
	len = lhs.len;
	p.release();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), lhs.p.get(), len);

	std::println("[{}] - 복사 대입 연산자, 개수: {}, 주소: {}",
		id, len, static_cast<void*>(p.get()));
	
	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
	for (size_t i{ 0 }; i < s.len; ++i) {
		os << s.p[i];
	}
	return os;
}