//������1.cpp - 3page
#include <iostream>

// ��ӿ����� ������ ȣ���� ��Ȯ�� ����
// => �����Ϸ��� �Ļ� Ŭ������ �����ڿ��� ��� Ŭ���� �����ڸ� ȣ���ϴ� �ڵ带
//    �߰��� �ذ�
// => �����Ϸ��� �׻� "��� Ŭ������ ����Ʈ �����ڸ� ȣ��" �ϵ��� �ڵ� ����

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:						
	// ����� �ڵ�		// �����Ϸ��� ������ �ڵ�
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()  <<== �ٽ��� �����Ϸ��� ����
	{												// �ڵ�� �׻� ��� Ŭ������
													// ����Ʈ �����ڸ� ȣ���Ѵٴ°�
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// �Ҹ��ڴ� "~Derived()" �� ���� �Ʒ� �κп� ��� Ŭ���� �Ҹ��� ȣ�� �ڵ� �߰�
		// ~Base();
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);  // call Derived::Derived(5)
}
