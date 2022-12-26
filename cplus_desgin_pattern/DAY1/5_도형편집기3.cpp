#include <iostream>
#include <vector>


// 3. ��� ������ ������ Ư¡(draw) �� �ݵ�� ��� Ŭ����(Shape)
//    ���� �־�� �մϴ�.
//    => �׷���, Shape* �� ��� ������ ���� ���������� 
//       �ش� Ư¡�� ��밡���մϴ�.
//    => ������ ������ �ƴ� ������ ����

// 4. ��� Ŭ���� ��� �Լ��� �Ļ� Ŭ������ ������ �ϱ� �Ǵ� ����
//    �ݵ�� �����Լ��� ���� �Ǿ�� �մϴ�.


class Shape
{
	int color;	// ��� ������ ���� �ִ�
public:
	virtual ~Shape() {}

	// �Ʒ� �Լ����� �Ļ� Ŭ������ ������ �� �ʿ� �����ϴ�.
	// => virtual �� �� �ʿ� �����ϴ�.
	int  get_color()      { return color; }
	void set_color(int c) { color = c; }

	// ������ ������ ���ϴ� ����� ���� ���� �ٸ��ϴ�.
	// => �Ļ�Ŭ������ �������ϰ� �˴ϴ�.
	// => virtual �̾�� �մϴ�.
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
				p->draw();		
		}
	}
}
