#include <iostream>
#include <vector>

// �Ŀ� ����Ʈ ���� ���α׷��� ����� ���� ������ ���ô�.

// 1. ��� ������ Ÿ��ȭ �ϸ� ���մϴ�

// 2. ��� ������ ������ ��� Ŭ������ �ִٸ� ��� ������ �ϳ��� 
//    �����̳�(vector)�� �����Ҽ� �ִ�.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// �������Ÿ, �����ڴ� ����(int left, top, right, bottom��)
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};
int main()
{
//	std::vector<Rect*> v; // Rect �� ���� ����
	std::vector<Shape*> v; // ��� ������ ���� ����
}


