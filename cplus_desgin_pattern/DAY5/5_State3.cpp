// 1_State1 - 182 page
#include <iostream>

// ��� 2. ���ϴ� ���� �����Լ���!!

class Charater
{
	int gold;
	int item;
public:
	void run()    { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run() { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class RedItem : public Charater
{
public:
	virtual void do_run() override    { std::cout << "fast run" << std::endl; }
	virtual void do_attack() override { std::cout << "super power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedItem; // ������ ȹ�� ?
					 // => ���� ĳ���� ��ü�� ������ ����� ���� �ƴ϶�
					 // => ����� ������ ���� ���ο� ĳ���͸� �����
					 // => ���� �� �ƴ϶� ����(���ݱ��� ȹ���� gold��)�� ����
					 // => ���´� ���� �ϸ鼭 ���۸� �ٲܼ� ������ ?
	p->run();
	p->attack();
}



