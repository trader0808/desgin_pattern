#include <iostream>
#include <vector>

// 9. template method ����
//    => ��� Ŭ������ ������ ���� ��ü���� �帧�� ���� �Լ��� ����
//       (public, non-virtual)
//    => ���ؾ� �ϴ� �κи� ã�Ƽ� �����Լ��� ����(private �Ǵ� protected, virtual)

//    => �Ļ� Ŭ������ ��ü �帧�� ���� �����鼭��, ���ؾ��ϴ� �͸� ������ ��ȸ��
//       ������ �ְ� �ȴ�.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	// ���뼺�� �������� �и�
	// => ������ ���� �帧 ���ο� ���� �ִ� ���ؾ� �ϴ� �ڵ��
	//    �и��Ǿ�� �մϴ�.
	// => ���ϴ� ���� ã�Ƽ� �����Լ��� �и��ϼ���
protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape" << std::endl;
	}
public:
	void draw() 
	{
		std::cout << "mutex lock" << std::endl;
		std::cout << "graphic ��ü ����" << std::endl;

		draw_imp();		
		std::cout << "mutex unlock" << std::endl;
	}





	virtual Shape* clone()
	{
		Shape* p = new Shape(*this);
		return p;
	}
};




class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone() override
	{
		return new Rect(*this);
	}
};

class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Circle" << std::endl; }

	virtual Shape* clone() override
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






