#include <iostream>
#include <functional>
#include <memory>
#include "save.h"
#include "string.h"

/**
* String ����
*/


int main()
{
	/**
	* String other = s;
	* = > �̰� �� �ȵǴ°� ?
	*	String���� default ��������ڸ� ����µ�
	*	unique_ptr�� ��������ڰ� delete�Ǿ� �ֱ� ����.
	*	=> ���� ��������ڸ� ������ �Ѵ�.
	*/
	String s{ "STL ���θ� ���� Ŭ����" };
	String f;
	f = s;
	std::cout << f << std::endl;
	std::cout << s << std::endl;
}