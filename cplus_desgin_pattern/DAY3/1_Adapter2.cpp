#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.

// TextView : ���ڿ��� �����ߴٰ� ȭ�鿡 �̻ڰ� ����ϴ� Ŭ����
class TextView
{
	// font����, ũ����� ����
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};

//==========================================




class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

//==========================================================
// ������� ����
// Ŭ���� ����� : Ŭ������ �������̽��� ����
// ��ü   ����� : ��ü��  �������̽��� ����

// �Ʒ� �ڵ�� "Ŭ���� �����" �Դϴ�.
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	virtual void draw() override
	{
		TextView::show();
	}
};

// ��ü �����. 
class Text2 :  public Shape
{
	TextView* txtView;		// �ٽ� : ���� Ŭ������ ���� ����� �ƴ϶�!
							//       ������ �Ǵ� ������ ����.
							// �ܺο� �̹� ������� ��ü�� ����Ű�ڴٴ�
							// �ǵ�!!!
public:
	Text2(TextView* tv) : txtView(tv) {}

	virtual void draw() override
	{
		txtView->show();
	}
};




int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : Ŭ����!!
						  // tv       : ��ü
	tv.show();	// ���� tv �� show() �� ���


	
	// �̹� ���� ������� tv ��ü�� v�� ������ ������� ?
//	v.push_back(&tv); // error. �������̽� ����ġ!!

	v.push_back( new Text2(&tv) ); // ok.. ��ü ����͸� ����ؼ�
									// �������̽� ����

}

// TextView �� �������̽�(show) �� ���������� �䱸(draw)�� �����Ҷ�

// Ŭ���� ����� : TextView �� ���� ��ӹ��� Ŭ������ ����
// ��ü   ����� : TextView �� ����(������ �Ǵ� ����) �� Ŭ������ ����

// ��� : Ŭ������ ��ȭ(��� �߰�)
// ���� : ��ü�� ��ȭ(��� �߰�)

// Decorator : ��ü�� �������̽��� �����ѵ�, ����� �߰��Ǵ� ��
//				zd.write() => ����߰���  fs.write() ȣ��
// 
// Adapter   : ��ü�� �������̽� ����!!


// decorator ��  adapter ������ ������ ���ϼ��ֽ��ϴ�.
// ������, �ǵ��� ��Ȯ�� �ٸ��ϴ�. => �׻� �ǵ��� �߿�!






