#include "string.h"
#include <iostream>
#include <algorithm>
#include <print>

bool check{ false };

size_t String::uid{};

String::String()
	: id{++uid}
{
	if (check) {
		std::println("[{}] - ������, ����: {}, �ּ�: {}",
			id, len, static_cast<void*>(p.get()));
	}
}

String::~String()
{
	if (check) {
		std::println("[{}] - �Ҹ���, ����: {}, �ּ�: {}",
			id, len, static_cast<void*>(p.get()));
	}
}

String::String(const char* s)
	: len(strlen(s))
	, id{++uid}
{
		p = std::make_unique<char[]>(len);
		memcpy(p.get(), s, len);

	if (check) {
		std::println("[{}] - char* ������, ����: {}, �ּ�: {}",
			id, len, static_cast<void*>(p.get()));
	}
}

String::String(const String& other)
	: len{ other.len }
	, id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (check) {
		std::println("[{}] - ���� ������, ����: {}, �ּ�: {}",
			id, len, static_cast<void*>(p.get()));
	}
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs) { return *this; }
	len = rhs.len;
	p.release();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), rhs.p.get(), len);

	if (check) {
		std::println("[{}] - ���� ���� ������, ����: {}, �ּ�: {}",
			id, len, static_cast<void*>(p.get()));
	}
	
	return *this;
}

String::String(String&& other) noexcept
	: len{other.len}
	, id{++uid}
{
	// reset�� ����ؼ� �ٲ���
	p = std::move(other.p);
	other.p.release();
	other.len = 0;

	if (check) {
		std::println("[{}] - �̵� ������, ����: {}, �ּ�: {}",
			id, len, static_cast<void*>(p.get()));
	}
}

String& String::operator=(String&& rhs) noexcept
{
	if (this == &rhs)
		return *this;

	len = rhs.len;
	// reset�� ����ؼ� �ٲ���
	// reset(p.get());
	p = std::move(rhs.p);
	rhs.p.release();
	rhs.len = 0;

	if (check) {
		std::println("[{}] - �̵� �Ҵ� ������, ����: {}, �ּ�: {}",
			id, len, static_cast<void*>(p.get()));
	}

	return *this;
}

char* String::begin() const
{
	return p.get();
}

char* String::end() const
{
	return p.get() + len;
}

const size_t String::size() const
{
	return len;
}

bool String::operator==(const String& other) const
{
	if (len != other.len) { return false; }
	return std::equal(p.get(), p.get() + len, other.p.get());
}

std::ostream& operator<<(std::ostream& os, const String& s) {
	for (size_t i{ 0 }; i < s.len; ++i) {
		os << s.p[i];
	}
	return os;
}
//
//std::istream& operator>>(std::istream& is, String& s) {
//	std::ifstream in{ "src\\main.cpp" };
//
//}