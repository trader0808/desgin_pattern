#include <iostream>
#include <vector>


class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};
int main()
{	
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
		//	Rect rc;			// rc�� ������ ������ �ֽ��ϴ�. {} �����..
			Rect* p = new Rect; // ���Ҷ� ���� ��� ����Ϸ��� �� ����� �����մϴ�.
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)	// ���⼭ p�� Shape* �Դϴ�
				p->draw();		// error. �׷���, Shape �ȿ��� draw()�� �����ϴ�.
		}
	}
}
// �� �� �ڵ尡 ���� �ϱ�� ?
// �ذ�å�� ����� ?
// 1. Shape* Ÿ���� p�� Rect* �� Circle*�� ĳ��������!!
// => �׷���, Rect���� Circle ���� �˼� ����.
// => ����, dynamic_cast�� ���� ���������� ���� �ʴ� => ������ ���� �ð�

// 2. Shape ���� draw()�� ����!! <==== ��!!!


