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

// "���������� �ý���" ���� "Rect", "Circle" �ܿ�
// ���ڿ��� �ʿ��ϰ� �Ǿ���..
// ������ �ִ� TextView : show()�� ���
// ���������� �䱸����   : draw()�� ����ؾ� �ϰ� Shape�� ���� ��ӹ޾ƾ� �Ѵ�


// Adapter ���� : ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ�
//				  �ý����� �䱸�ϴ� ���·� �������ִ� ����

// "�������̽��� ����ġ" �� �ذ��ϴ� ����.


// TextView �� �������̽�(�Լ��̸�)�� �����ؼ� ���������⿡��
// ����Ҽ� �ְ� �غ���
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// show() �Լ� �̸��� draw() �̸����� �����ϴ� ��Ȱ
	virtual void draw() override
	{
		TextView::show();
	}
};


int main()
{
	std::vector<Shape*> v;

	v.push_back(new Text("hello"));

	v[0]->draw(); // �ᱹ : TextView::show() �� ���
}








