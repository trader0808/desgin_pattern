// 1_������1-1.cpp     1�� �����ؼ� �ּ� ����������

//������1.cpp - 3page
#include <iostream>

class Base
{
public:
//	Base() { }
	Base(int a) { }
	~Base() { }
};

class Derived : public Base
{
public:
	// ����� �ڵ�		// �����Ϸ��� ������ �ڵ�
//	Derived() {}		// Derived() : Base(){}
//	Derived(int a) {}	// Derived() : Base(){}

	// 1. ��� Ŭ������ ����Ʈ �����ڰ� ���ų�
	// 2. �ǵ������� ���Ŭ������ �ٸ� �����ڸ� ȣ���Ϸ���
	// => ����ڰ� ��������� ȣ���� �־�� �մϴ�.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}


	~Derived() 	{}
};

int main()
{

}

// 9:30 �п� �����մϴ�.