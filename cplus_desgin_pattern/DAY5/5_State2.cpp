// 1_State1 - 182 page
#include <iostream>

// �������� ȹ�� ���¿� ���� ĳ������ ������ ����Ǿ�� �մϴ�.
// ��� 1. ���
// => �ű� ������ �����, ��� �����Լ��� ����Ǿ�� �Ѵ�.
// => OCP �� �����Ҽ� ����.

class Charater
{
	int gold;
	int item;
public:
	void run() 
	{
		if( item == 1 )
			std::cout << "run" << std::endl; 
		else if( item == 2)
			std::cout << "fast run" << std::endl;
	}

	void attack() 
	{
		if ( item == 1)
			std::cout << "attack" << std::endl; 
		else if ( item == 2)
			std::cout << "power attack" << std::endl;
	}
};




int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



