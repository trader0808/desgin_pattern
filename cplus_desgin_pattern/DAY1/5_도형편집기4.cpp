#include <iostream>
#include <vector>

// 5. ������
// => ������ ǥ������ ��Ȳ�� ����(���� ��ü) �ٸ��� �����ϴ°�
// => OCP �� �����ϴ� ���� ���� �ڵ� ��Ÿ��!!
// => �׻� �������� ���� ����ϼ���!!

class Shape
{
	int color;	
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }


	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};




class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)       v.push_back(new Rect);
		else if (cmd == 2)	v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	// ������(Polymorphism)
							// => ������ ǥ������ ��Ȳ�� ����(���� ��ü)
							//    �ٸ��� �����ϴ� ��

			// ��ü���� ���Ư¡ : ĸ��ȭ, ���, ������
		}
	}
}
