#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// �ڽ��� ��ü�� ����� "static ��� �Լ�"�� ���� �����ϰ� 
	// Ȱ��ɼ� �ֽ��ϴ�.
	static Shape* Create() { return new Rect; }
};

// Rect ��ü�� ����� 2���� ���
// 1. Rect* r1 = new Rect;
// 2. Rect* r2 = Rect::Create();

// �Լ� ���ڿ� ���� �ٸ� ������ ��ü�� ������� �մϴ�.
// => ��, �̷��� ������� �������� ����
// => �̷��� ������� ������ Ŭ���� �̸��� �𸣹Ƿ� "new ??" �Ҽ� �����ϴ�.
void make_shape(Shape*(*f)() )
{
	Shape* p = f(); // ���ڿ� ���� �ٸ� ���� ����
					// MFC, QT, wxWidget ���� ���̺귯������ �� �����
					// "���� ����" �̶�� �ҷ����ϴ�.
}

// ��� 1. ���ڿ��� Ŭ���� �̸��� �˷��ָ� ��� ?
// => C++ �� Ŭ���� �̸��� ���ڿ��� �˾Ƶ� ��ü�� �����Ҽ� ����.
// => C#, swift ���� ����
//make_shape("Rect");
//make_shape("Triangle");

// ��� 2. Ŭ�����̸��� ������ ���� Ŭ������ ��ü�� ����� ��ӵ� �Լ���
// ������ ?? "�ᱹ Ŭ������ ������ �Ͱ� ���� ȿ�� �ƴұ� ?"
make_shape(&Rect::Create);
make_shape(&Triange::Create);









class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* Create(int type)
	{
		Shape* p = nullptr;
		if (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7) 
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}



		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




