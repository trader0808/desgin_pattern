// 3_�����Լ�2-2
#include <iostream>

// ��� ��� Ŭ������ �Ҹ��ڴ� "�ݵ�� �����Լ�" �̾�� �մϴ�.
// => ����. ��� ������� �����Լ� �ƴ� protected �Ҹ��ڷ� �ذ��ϱ⵵ �մϴ�.
// => Base ���ο� �ٸ� �����Լ��� �Ѱ��� ���µ�, �Ҹ��� ������
//    �����Լ� ���� ����� ������带 �����ϱ� ����

class Base
{
	// �ǵ� : Base* ��ä �δ� delete ������ ����� �ǹ�.
	//       delete �ÿ� ������ ����.
protected:
	~Base() {}
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p = new Derived;	

//	delete p;	// error
	delete static_cast<Derived*>(p);	// ok


}
