#include "string.h"
#include <iostream>
#include <print>

bool check{ false };

size_t String::uid{};

String::String()
	: id{++uid}
{
	if (check) {
		std::println("[{}] - 생성자, 개수: {}, 주소: {}",
			id, len, static_cast<void*>(p.get()));
	}
}

String::~String()
{
	if (check) {
		std::println("[{}] - 소멸자, 개수: {}, 주소: {}",
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
		std::println("[{}] - char* 생성자, 개수: {}, 주소: {}",
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
		std::println("[{}] - 복사 생성자, 개수: {}, 주소: {}",
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
		std::println("[{}] - 복사 대입 연산자, 개수: {}, 주소: {}",
			id, len, static_cast<void*>(p.get()));
	}
	
	return *this;
}

String::String(String&& other)
	: len{other.len}
	, id{++uid}
{
	p.reset(other.p.get());
	other.p.release();
	other.len = 0;

	if (check) {
		std::println("[{}] - 이동 생성자, 개수: {}, 주소: {}",
			id, len, static_cast<void*>(p.get()));
	}
}

String& String::operator=(String&& rhs)
{
	if (this == &rhs)
		return *this;

	len = rhs.len;
	p.reset(rhs.p.get());
	rhs.len = 0;
	rhs.p.reset();

	if (check) {
		std::println("[{}] - 이동 할당 연산자, 개수: {}, 주소: {}",
			id, len, static_cast<void*>(p.get()));
	}

	return *this;
}

const size_t String::size() const
{
	return len;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
	for (size_t i{ 0 }; i < s.len; ++i) {
		os << s.p[i];
	}
	return os;
}