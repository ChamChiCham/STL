#pragma once
#include <memory>

class String
{
private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	size_t id{};

public:
	// �� �� �Լ��� ���� �ʿ䰡 ���� ����.
	String();
	~String();

	String(const char* s);

	String(const String& other);
	String& operator=(const String& rhs);

	// �̵� ������ / �̵� �Ҵ� ������
	// �̵� �ø�ƽ��(moving semantics)�� ����Ͽ� ��ü�� �ٸ� ��ü�� �̵���Ű�� �� ���˴ϴ�.
	
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
