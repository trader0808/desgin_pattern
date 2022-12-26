#include <iostream>

// ��� ��� Ŭ������ �Ҹ��ڴ� "�ݵ�� �����Լ�" �̾�� �մϴ�.

class Base
{
public:
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived;	// ��ü ����. ������ ȣ��
//	delete p;					// ��ü �ı�. �Ҹ��� ȣ��.

	Base* p = new Derived;	// ��ü ����. ������ ȣ��

	delete p;	// �̼���, �Ҹ��ڸ� ȣ���ؾ� �ϴµ�. �Ҹ��ڵ� �Լ��̴�.!!
				// 1. static binding ����, dynamic binding ������ �����ؾ� �Ѵ�.
				// 2. p�� Base* �̹Ƿ� "Base Ŭ���� ������ ����, �Ҹ��ڰ� 
				//    �������� ����
				// ������ �ƴϸ� : ������ Ÿ���� ~Base() ȣ��
				// �����̸�      : �޸� ������ ȣ��.


}	
