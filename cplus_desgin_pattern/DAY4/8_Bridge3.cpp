// ������ ���� Ŭ����
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug; // �ڵ尡 �����Ǿ���
public:
	void print();
};


// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } 

//-----------------------------------------
// ����ڰ� ����ϴ� Ŭ����
// Point.h

// �ٽ� : ���漱�� ������ 
//       �����ͺ����� ���𰡴�
class PointImpl;

class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h" // ���⼭�� ��� �ʿ�

Point::Point() { impl = new PointImpl(); }
void Point::print() { impl->print(); }







// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


// PIMPL �̶�� C++ Idioms
// => Bridge ������ �����Ͻð� Ȱ��

// ���� 1. ������ �ð��� ��������.
//        => �����Ϸ� ��ȭ��!!

// ���� 2. �Ϻ��� ���� ����
//		=> ���� ����ڰ� �޴� �������
//		   ��� ����Ÿ ���� �ȵ�