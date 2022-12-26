#include <iostream>
#include <vector>

class NotImplemented : public std::exception {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }



public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		std::cout << "graphic ��ü ����" << std::endl;

		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}


protected:
	virtual void draw_imp() = 0;


public:
	virtual Shape* clone()
	{
		throw NotImplemented();
	}


	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Rect" << std::endl; }

	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};


class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Circle" << std::endl; }

	virtual Circle* clone() override
	{
		return new Circle(*this);
	}
};



int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// ������ �� ����

		// 1. ��ü�� ���� ������ OCP �� �����ϵ��� �Ҽ� ������?
		// => ���ο� ������ �߰��Ǿ �Ʒ� �ڵ尡 ����(�߰�)���� �ʵ���!!
		// => �߻� ���丮 ������ ����ϸ� �˴ϴ�(����ϳ� ���� �˴ϴ�.)

		// 2. Undo/Redo ����� �������� ��� �ؾ� �ұ� ??
		// => Command ������ �˸� �˴ϴ�.
		// => ����Ͽ� ���� �����մϴ�.

		if (cmd == 1)       v.push_back(new Rect);
		else if (cmd == 2)	v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());

		}
	}
}






