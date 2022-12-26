#include <iostream>
#include <vector>


// 6. Refactoring ���� ���� ������ ��� �Դϴ�. �ǹ̸� ������ ������
// �����丵 : ���� �ڵ带 ���� ���� �����ϴ� �۾�
// 
// "Replace Conditional(���, if, switch) With Polymorphism(������, �����Լ�)"
// "����������5-1ó�� �Ǿ� �ִٸ� 5-2 ó�� �����϶�" �� �ǹ�!!
// �׻� ��� ���ٴ� �������� ���� ���� �ض�!


// 7. ������ ���� - 1994�� 4���� �����ڰ� ������ å�� ����!!!

// ��� ���� �ҽ��� �м��ؼ� �����ϴ� �ڵ� ��Ÿ�Ͽ� �̸��� ���ΰ�!!
// => 4���� ���ڰ� �ڵ带 ������� �ƴ϶�!! �̸��� �ο� �Ѱ�
// => 23���� �̸� �ο�!!


// 8. Prototype ���� : �ߺ��� �Ǵ� ��ü�� �����
//					   ���縦 ���� ��ü�� �����ϴ� ���
//						Clone() �����Լ�



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }

	// �ڽ��� ���纻�� ����� �����Լ��� �׻� �����ϰ� Ȱ��˴ϴ�.
	virtual Shape* clone()
	{
		Shape* p = new Shape(*this); // ��������ڷ� ���� ������ ��ü����
		return p;
	}
};




class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone() override 
	{
		return new Rect(*this); 		
	}
};



class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Circle" << std::endl; }
	
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

			// ��� 2. ������ ���
			// => �ٽ� : k��° ������ � �������� ���ʿ� ����.
			v.push_back(v[k]->clone()); // ������!!
			
		}
	}
}






