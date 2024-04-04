#pragma once
#include <memory>

class String
{
private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	size_t id{};

public:
	// 이 두 함수는 만들 필요가 전혀 없다.
	String();
	~String();

	String(const char* s);

	String(const String& other);
	String& operator=(const String& lhs);

	friend std::ostream& operator<<(std::ostream& os, const String& s);

private:
	static size_t uid;
};
