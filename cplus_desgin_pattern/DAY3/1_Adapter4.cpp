#include <iostream>
#include <list>
#include <vector>
#include <deque>

// private ��Ӱ� ������ ������ ���Դϴ�.
// => �޸𸮻�뷮, ����
// => ��� Ŭ���� �������̽� ������� ��..

// private ��� : ��� Ŭ������ �����Լ��� override �Ҽ� �ִ� �ɷ��� �ֽ��ϴ�.
// ����         : ����� �ƴϹǷ� �����Լ� override �ȵ˴ϴ�.

// ����� ���鿡�� "���� �޼���"���� ����Ѵٸ�
// private ��� ���� ������ ���� ��찡 �� �����ϴ�.


// private ��� : ��� Ŭ���� ����� ���� ������
//				  ��� ����� ���������ڸ� private �����ؼ� ���� �ްڴٴ°�
//				  ������ ����������(stack �� ���������δ� ���)
//				  �������̽��� ���� ���� �ʰڴ�(list �Լ��� �ܺ� ���� ����)
template<typename T> class stack1 : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T& top()			  { return std::list<T>::back(); }
};

template<typename T> class stack2
{
	std::list<T> c;	
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
	stack1<int> s1;
	stack2<int> s2;
	

	s1.push_front(10); // error. ������ private �̹Ƿ�
	s2.push_front(10); // error. ������ �Լ��� ����.
					// => ����� ���鿡���� "�Լ��� ����"�� �����ϴ�!
}
