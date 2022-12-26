#include <iostream>
#include <vector>

class NotImplemented : public std::exception {}; // ���ܸ� ���� Ŭ����.
						// ����� ���� �̷��Ը� ���� �����ϴ�.
						// �̸� ��ü�� ������ �ϰ� �ֽ��ϴ�.

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

	// �����Լ�     : ���������� ������ �⺻ ������ �����ϰڴٴ� �ǵ�!
	// ���������Լ� : �ݵ�� ������ �ؾ� �Ѵٰ�, ������ ��Ű�� ��

protected:
	virtual void draw_imp() = 0;


public:
	// clone()�� ���� �����Լ��� �����ϴ�. 
	// �׷���, �Ʒ� ó�� �ϱ⵵ �մϴ�.(Python ���...)
	// 1. ������ ���ϰ�, ��뵵 ���ϸ� ok
	// 2. ������ ���ϰ�, ����ϸ� ���� �߻�
	// 2. ������ �ϰ�,   ����ϸ� ok. 
	virtual Shape* clone()
	{
		throw NotImplemented();
	}

	// �Ʒ� �Լ��� ���� �����Լ��� ������
	// => ���̸� ���Ҽ� ����(�Ǵ� ���� �ȵ�) �� �ǹ� �ϴ� -1�� ��ȯ
	//    �ϴ� ���鵵 �ֽ��ϴ�.
	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw Rect" << std::endl; }

	// �����Լ� �����ǽ� ��ȯ Ÿ�Ժ��氡���մϴ�
	// => ��, ��Ӱ����� Ÿ�����θ�!!
	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};

// Rect* p1 = new Rect;
// ?     p2 = p1->clone();
// p2�� Shape* �� �޴� ���� ���ұ�� ?
//      Rect*  �� �޴� ���� ���ұ�� ?  => ���մϴ�. Rect �� �߰��� ������ٰ���
// ����� ���忡��!!



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






