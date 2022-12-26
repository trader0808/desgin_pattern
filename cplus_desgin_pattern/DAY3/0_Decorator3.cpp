#include <iostream>


// ��ü�� ��� �߰��� ��������� ��� �Ҽ��־�� �մϴ�.
// => ����� �߰��� ��ü�� �ٽ� ��� �߰�!!

// ��ü�� ��� �߰� ��ü(Decorator)�� ������ ��� Ŭ����

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


class LeftMissile : public Component
{
	Component* ship;
public:
	LeftMissile(Component* s) : ship(s) {}

	void fire()
	{
		ship->fire();	
		std::cout << "Fire Left Missile" << std::endl;
	}
};

class RightMissile : public Component
{
	Component* ship;
public:
	RightMissile(Component* s) : ship(s) {}

	void fire()
	{
		ship->fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
//	ss.fire();

	LeftMissile lm(&ss);
//	lm.fire();

//	RightMissile rm(&ss);
	RightMissile rm(&lm); // �Ǹ� ���� ������� ?
						  // ����� �߰��� ��ü�� �ٽ� ��� �߰�.
	rm.fire();

}

