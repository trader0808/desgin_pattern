#include <iostream>
/*
// �̱��� �ڵ带 �ڵ������ϴ� ��ũ��
#define MAKE_SINGLETON(classname)				\
private:										\
	classname() {}								\
	classname(const classname&) = delete;		\
	classname& operator=(const classname&) = delete;	\
public:													\
	static classname& getInstance()						\
	{													\
		static classname instance;						\
		return instance;								\
	}
*/
#include "helper.h" // �� �ȿ� �� ��ũ�� �ֽ��ϴ�.

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

}









