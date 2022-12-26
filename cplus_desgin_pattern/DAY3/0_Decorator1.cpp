// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// ����� ����� ����� �߰�
// => ��ü�� ���� ��� �߰��� �ƴ� Ŭ������ ����� �߰� �Ѱ�
class LeftMissile : public SpaceShip
{
public:
	void fire()
	{
		SpaceShip::fire(); // ������ ����� ���
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ����߰�
	}
};
int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm; // ������ ���� �ϴ� ss ��� ��ü�� ����� �߰��Ȱ��� �ƴ϶�
					// ����� �߰��� ���ο� ��ü(���ּ�)�� �����!!
	lm.fire();
}

