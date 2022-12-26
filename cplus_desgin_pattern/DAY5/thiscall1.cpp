#include <iostream>
// �ٽ� 1. ��� �Լ��� ������ �ϸ� "��ü�ּ�(this)" �� �߰��˴ϴ�.
// �ٽ� 2. static ��� �Լ��� ������ �ϸ� "��ü�ּ�(this)" �� �߰��ȵ˴ϴ�.

class Point
{
	int x, y;
public:
	void set(int a, int b)	// void set( Point* this, int a, int b)
	{						// { 	
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;
	}		

	static void foo(int n)
	{
		x = n;		// this->x = n �� �Ǿ�� �ϴµ�
					// static ��� �Լ� �ȿ����� "this" �� ����.
					// �׷���, error!
	}

};
int main()
{
	// static ��� �Լ��� ��ü ���� ȣ�� ����
	Point::foo(10); // ������ �Ǿ "call Point::foo(10)"

	Point p1, p2;

	p1.set(10, 20); // set(&p1, 10, 20) �� ����˴ϴ�.
}



