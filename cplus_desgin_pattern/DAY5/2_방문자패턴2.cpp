#include <iostream>
#include <list>
#include <vector>

// �湮���� �������̽�
// => �湮�ڴ� �Ѱ��� ��Ҹ� �湮���� �˴ϴ�.
template<typename T> struct IVisitor
{
	virtual void visit(T& value) = 0;
	virtual ~IVisitor() {}
};

// �湮�� ���(list)�� �������̽�
template<typename T> struct IAcceptor
{
	virtual void Accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

//-------------------------------------------------------
// �湮�� ��ü�� �ٽ� 
// => �湮�ϴ� ��� �Ѱ��� ���� ������ �����ϴ� Ŭ����
// => "�湮 �ϴ� ���" ==> "���� ���� ����" �Դϴ�.

// ��Ҹ� 2��� �ϴ� �湮��
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) { value = value * 2; }
};

//==========================
// STL list �� �湮�� ������ ������� �ʽ��ϴ�.
// std::list �� ��� �޾Ƽ� �湮�� ������ ������ ���ô�.

template<typename T> 
class MyList : public std::list<T>, public IAcceptor<T>
{
public:
	using std::list<T>::list; // ������ ���


	// list �� �湮�ڰ� ���������� �ؾ� ������ �Ʒ� �Լ����� ����
	virtual void Accept(IVisitor<T>* visitor)
	{
		for (auto& e : *this) // *this �� ���� "list" �Դϴ�.
			visitor->visit(e);
	}
};





template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) { std::cout << value << std::endl; }
};

template<typename T> class ZeroVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& value) { value = 0; }
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;	
	s.Accept(&tv);			

	ShowVisitor<int> sv;	
	s.Accept(&sv);

	ZeroVisitor<int> zv; // ��� ��Ҹ� 0���� ����� �湮��
	s.Accept(&zv);

	s.Accept(&sv);
}





