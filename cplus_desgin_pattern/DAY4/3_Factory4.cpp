#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

// ShapeFactory �� ��ġ�� ��������
class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> creator_map;

public:
	void Register(int key, CREATOR create)
	{
		creator_map[key] = create;
	}


	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = creator_map.find(type);

		if (ret != creator_map.end())
		{
			p = (ret->second)();
		}

		return p;
	}
};

// ���忡 ������ ����ϴ� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(type, f);
	}
};

// ���������� �����ڰ� ���� ����Ǵ��� ������ ������
// AutoRegister ar(1, &Rect::Create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }


	// static ��� ����Ÿ�� ���� �����Ǵ��� ������ ������
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);

// Rect::ar �� ������ => main �Լ��� ����Ǳ��� �� �ѹ� ȣ��˴ϴ�.
// 
// new Rect() => Rect ������ ȣ��
// new Rect() => Rect ������ ȣ��

// ��, 
// 1. Rect �����ڴ� "��ü�� ���鶧 ���� ȣ��" - �ν��Ͻ� ������
// 2. Rect::ar �� �����ڴ� "Rect" Ÿ�Կ� ���� ���ʿ� �ѹ� ȣ��
//    => C#�� static ������ �Դϴ�.
//    => C++ �� �̹����� ���, static ����� ������ ȿ���� �����





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);







int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);



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





// ���� C# �ڵ� 
/*
class Car
{
	public Car() {}			// instance ������ - ��ü�� ���鶧 ���� ȣ��
	static public Car() {}  // static ������ - ���ʿ� 1ȸ�� ȣ��
};
*/