#include <iostream>


struct Component
{
	virtual void fire() = 0;
	virtual ~Component() {}
};

class SpaceShip : public Component
{
public:
	void fire() { std::cout << "Fire Missile" << std::endl; }
};


//=============================
// ���ּ��� ����� �߰��ϴ� Ŭ�������� ������ �ڵ尡 �����ϴ�.
// ������ ��� Ŭ������ �����ϸ� �����ϴ�.

class Decorator : public Component
{
	// ����߰��� ���� �������� �ʿ��� �پ��� �����..
	Component* comp;
public:
	Decorator(Component* comp) : comp(comp) {}

	void fire() { comp->fire(); }
};
// ���� ��� ��� �߰� ��ü�� "Decorator"���� �Ļ� �˴ϴ�.
class LeftMissile : public Decorator
{
public:
	using Decorator::Decorator;

	void fire()
	{
		Decorator::fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Decorator
{
public:
	using Decorator::Decorator;

	void fire()
	{
		Decorator::fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;

	LeftMissile lm(&ss);

	RightMissile rm(&lm); 
	rm.fire();

}

