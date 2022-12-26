#include <iostream>
#include <list>
#include <vector>
#include <deque>

// stack ����, ���� �����̳ʸ� "���ø� ����"�� �����Ҽ� �ְ� �մϴ�.

template<typename T, typename C = std::deque<T> > class stack
{
	C c;
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop()			  { c.pop_back(); }
	inline T& top()              { return c.back(); }
};

#include <stack> // �� �ȿ� �ִ� C++ǥ�� stack �� �� ó�� ������� �ֽ��ϴ�.
				// ���� "stack adapter" ��� �� ����մϴ�
int main()
{
//	std::stack<


	stack<int> s1;  // ���������� std::deque �� ����

	stack<int, std::list<int>>   s2;  // list �� stack ó�� ����ϰڴٴ°�
	stack<int, std::vector<int>> s3;

	s1.push(10);
}
