// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void fire() { std::cout << "Fire Missile" << std::endl; }
};


// ����� ����� ����� �߰� : Ŭ������ ����(�ڵ��ۼ���)���� ����� �߰�
// ������ ����� ����� �߰� : Ŭ������ �ƴ� ��ü�� �������� ����� �߰��Ҽ� �ִ�.

class LeftMissile 
{
	SpaceShip* ship; // �ٽ� : ������ �Ǵ� ������ ����
					 //       (�� Ÿ���̸� �ȵ˴ϴ�.)
					// �̹� �����Ǿ� �ִ� ���ּ� ��ü�� ����Ű�ڴٴ�
					// �ǵ�!!
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void fire()
	{
		ship->fire();	// �̹� �����Ǿ� �ִ� ��ü�� ����� ����ϰ�
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ��� �߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.fire();

	LeftMissile lm(&ss); // lm ��ü�� �̹� �����ϴ� "ss" ��ü�� ����� �߰��ϴ�
						 // ��Ȱ�� �ϴ� ��ü �Դϴ�.
	lm.fire();
}

