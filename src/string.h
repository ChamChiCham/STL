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
	String& operator=(const String& rhs);

	// 이동 생성자 / 이동 할당 연산자
	// 이동 시멘틱스(moving semantics)를 사용하여 객체를 다른 객체로 이동시키는 데 사용됩니다.
	
	String(String&& other) noexcept;
	String& operator=(String&& rhs) noexcept;


	char* begin() const;
	char* end() const;

	const size_t size() const;

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	//friend std::istream& operator>>(std::istream& is, String& s);

	//const size_t getLen() const;
	
private:
	static size_t uid;
};
