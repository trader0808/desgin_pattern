// 1_State1 - 182 page
#include <iostream>

// ������ ĳ���͸� ������ ���ô�.
// Item ȹ�濡 ���� ���� ĳ������ �پ��� ������ �����ϰ� �ʹ�.
class Charater
{
	int gold;
	int item;
public:
	void run()    { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};
int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



