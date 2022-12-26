// bind1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...

void f4(int a, int b, int c, int d)
{
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}

void f1(int a) {}
void f2(int a, int b) {}

class Dialog
{
public:
	void close(int a, double d) { std::cout << "Dialog Close" << std::endl; }
};

int main()
{
	// �Լ� �����ʹ� �������� �����մϴ�
//	void(*f)(int) = &f1; // ok
//	f(10);			     // f1(10)
//	f = &f2; // error. f2�� ���ڰ� 2�� �Դϴ�.

	// C++11 ���ʹ� std::function<> ����ϼ���
	std::function<void(int)> f;

	f = &f1;
	f(10);  // ok. f1(10)

	
	// �ٽ� : function �� std::bind()�� ����� ������ ���ο� �Լ��� ������
	// �ֽ��ϴ�.
	// f = &f2; // error

	f = std::bind(&f2, _1, 7);
	f(10); // f2(10, 7)


	f = std::bind(&f4, 7, 3, _1, 9 );
	f(6); // f4(7, 3, 6, 9) ������ �غ�����

	// �ᱹ "f" ���� ���ڰ� "int �Ѱ�" �̻��� ��� ������ �Լ��� 
	// ������ �ֽ��ϴ�. std::bind() ���п�.

	// ��� �Լ� �ּҸ� ��� ���
	// => ��� �Լ��� ȣ���Ϸ��� ��ü�� �ʿ� �մϴ�.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, _1, 3.4);

	f(10); // dlg.close(10, 3.4) �� �ǹ�!
}





