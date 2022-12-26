#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	virtual Rect* clone() override { return new Rect(*this); }

};



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	virtual Circle* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;

public:
	void Register(int key, Shape* sample)
	{
		prototype_map[key] = sample;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = prototype_map.find(type);

		if (ret != prototype_map.end())
		{
			p = ret->second->clone(); // ���纻 ��ü ����
		}

		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// �Ʒ� �ڵ�� �ᱹ ���忡 Ŭ������ ��� �ϴ� �ǹ� �Դϴ�.
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);


	// ���忡 "Ŭ����" �� �ƴ϶� ���� ���Ǵ� "��ü" �� ����� ���ô�.
	Rect* redRect = new Rect;	// ������ ũ�� 5 �簢���̶�� ����
	Rect* blueRect = new Rect;	
	Circle* redCircle = new Circle;

	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, redCircle);

	// �����ϴٰ� �Ʒ� �Լ� ������ ������
//	factory.ShowRegisteredSample(); // ��ϵ� ��� �ߺ� ��ü�� �����ش�
									// 1. redRect
									// 2. blueRect
									// 3. redCircle







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




