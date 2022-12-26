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



// ��� ������ ���Ѿ� �ϴ� ��Ģ�� ��ũ�η� �����մϴ�.

#define DECLARE_SHAPE(classname)					\
	static Shape* Create() { return new classname; }\
	static AutoRegister ar;

#define REGISTER_SHAPE(key, classname)		\
	AutoRegister classname::ar(key, &classname::Create);

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect)




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	DECLARE_SHAPE(Circle)
};
REGISTER_SHAPE(2, Circle)


class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	DECLARE_SHAPE(Triangle)
};
REGISTER_SHAPE(3, Triangle)





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


