#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter

// 1. STL �� list �� �̹� �ֽ��ϴ�.
// 2. �׷���, ����ڰ� stack �� �䱸 �մϴ�( stack �� ������, ���ٰ� ����)


// list �� ��� �Լ� �̸��� stack ó�� ���̵��� �����ϴ� Ŭ����(adapter)

// ����� ����� ����� : list �� ��� ����� stack �� �ܺ� �����ϰ� �ȴ�.
//						���� �����ο����� ���� ���ڴ�!!
//						stk.push_front(10) �� ���� ���;� �Ѵ�!!!
/*
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};
*/

// ������ ����� �����..
// ����Ŭ����(list)�� ����� stack �� �ܺ� �������� �ʴ´�.
// stack �� ���� �Լ��� �ܺ� ����ȴ�
template<typename T> class stack 
{
	std::list<T> c;	// �� Ÿ�� �Դϴ�. Ŭ���� ����� �Դϴ�.
//	std::list<T>* p;// �̷��� �Ǿ�� ��ü ����� �Դϴ�.

public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	
//	s.push_front(100); // ?? �̷��� ����Ҽ� �־�� �ұ�� ??
}


// ��ü ����� : �����ͳ� ������ ����.
// Ŭ���� ����� : ����̳�, �� Ÿ������ ����
//			=> ���            : ���� Ŭ������ �������̽��� �ܺο� ��� ����
//			=> �� Ÿ������ ���� : ���� Ŭ������ �������̽��� ���� ����