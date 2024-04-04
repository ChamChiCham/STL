#include <iostream>
#include <functional>
#include <memory>
#include "save.h"
#include "string.h"

/**
* String 구현
*/


int main()
{
	/**
	* String other = s;
	* = > 이게 왜 안되는가 ?
	*	String에서 default 복사생성자를 만드는데
	*	unique_ptr의 복사생성자가 delete되어 있기 때문.
	*	=> 따로 복사생성자를 만들어야 한다.
	*/
	String s{ "STL 공부를 위한 클래스" };
	String f;
	f = s;
	std::cout << f << std::endl;
	std::cout << s << std::endl;
}