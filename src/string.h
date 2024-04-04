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
	String(String&& other);
	String& operator=(String&& rhs);


	const size_t size() const;

	friend std::ostream& operator<<(std::ostream& os, const String& s);

private:
	static size_t uid;
};
