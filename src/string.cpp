#include "string.h"
#include <iostream>
#include <print>

size_t String::uid{};

String::String()
	: id{++uid}
{
	std::println("[{}] - ������, ����: {}, �ּ�: {}",
		id, len, static_cast<void*>(p.get()));
}

String::~String()
{
	std::println("[{}] - �Ҹ���, ����: {}, �ּ�: {}",
		id, len, static_cast<void*>(p.get()));
}

String::String(const char* s)
	: len(strlen(s))
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), s, len);
	std::println("[{}] - char* ������, ����: {}, �ּ�: {}",
		id, len, static_cast<void*>(p.get()));
}

String::String(const String& other)
	: len{ other.len }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	std::println("[{}] - ���� ������, ����: {}, �ּ�: {}",
		id, len, static_cast<void*>(p.get()));
}

String& String::operator=(const String& lhs)
{
	if (this == &lhs) { return *this; }
	len = lhs.len;
	p.release();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), lhs.p.get(), len);

	std::println("[{}] - ���� ���� ������, ����: {}, �ּ�: {}",
		id, len, static_cast<void*>(p.get()));
	
	return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
	for (size_t i{ 0 }; i < s.len; ++i) {
		os << s.p[i];
	}
	return os;
}