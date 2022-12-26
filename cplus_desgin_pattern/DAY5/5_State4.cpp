// 1_State1 - 182 page
#include <iostream>

// ��� 3. ���ϴ� ���� �ٸ� Ŭ���� ��!!

// ������ ȹ�濡 ���� ���ؾ� �ϴ� ��� ������ ������ �������̽�
struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}

	// �̿ܿ��� "jump(), slide(), fly()" �� �پ��� ���۵��� ����.
};


class Charater
{
	int gold;
	int item;
	IAction* action = nullptr;
public:
	void set_action(IAction* p) { action = p; }
	
	// ĳ������ ��� ������ "������ ������ Action ��ü" �� ���� �մϴ�.
	// => action ��ü�� ���� ĳ������ ��� ������ ���������
	// => "����(��� ����Ÿ)" �� ���� �մϴ�.
	// => "Ŭ������ ��κ��� ��� �Լ�"�� ��ü �ϴ� ��
	void run() { action->run(); }
	void attack() { action->attack(); }
};

// �����ۿ� ���� ������ ������ Ŭ������
class NoItem : public IAction
{
public:
	virtual void run()    override { std::cout << "run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};

class RedItem : public IAction
{
public:
	virtual void run()    override { std::cout << "fast run" << std::endl; }
	virtual void attack() override { std::cout << "attack" << std::endl; }
};

class StarItem : public IAction
{
public:
	virtual void run()    override { std::cout << "fast run" << std::endl; }
	virtual void attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	NoItem ni;
	RedItem ri;
	StarItem si;

	Charater* p = new Charater;
	p->set_action(&ni);
	p->run();
	p->attack();

	p->set_action(&si); // ĳ������ ������ �����մϴ�.
						// => ������ ���´� ���� �˴ϴ�.
						// => ��ġ �ٸ� Ŭ������ ����ϴ� ȿ���� ���� �˴ϴ�.
	p->run();
	p->attack();

}




// ������ ���Ͽ��� ���ϴ� ���� �ٸ� Ŭ������ �и��ؼ�
// "�������̽�"�� ��ü �ϴ� ������ 3���� �Դϴ�.
// => 3���� ��� ������ Ŭ���� ���̾�׷��� ������ �˴ϴ�.
// => �ǵ��� ���� �����̸� ����
// 
// strategy : ��ü�� ����ϴ� �˰����� ��ü
// state    : ��ü�� ���¿� ���� ��� ������ ��ü(�ٸ� Ŭ���� ó�� ���δ�)
// 
// builder  : ������ ��ü�� ���鶧 "������ ����"�� ����ϴµ�
//			  �� ������ ǥ���� �ٸ� ���

// 186 page