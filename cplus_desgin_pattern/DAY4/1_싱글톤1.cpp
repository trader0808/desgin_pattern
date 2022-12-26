// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� 
// 1. ���� �Ѱ��� ��ü�� �����ϴ� ��.
// 2. ���α׷��� ��𿡼��� ���� �Ѱ��� ��ü�� ������ ������� ���ٰ����Ѱ�          

// => "���� �Ѱ� �ְ�, ������ ������� ����" �ϴ� ���� �ᱹ �������� �� �����մϴ�.
// => ���������� ���� �ڵ�� �ƴմϴ�.
// => �̱��� ���Ͽ� ���� "����" �� ���� ���� �մϴ�.


// �Ʒ� �ڵ�� "���� �Ѱ��� ��ü" �� "static ��������" �Դϴ�.
// => effective-c++ å�� ������ scott-meyer �� ó�� ��������ϴ�.
// => "meyer's singleton" �̶�� �մϴ�.

// => �پ��� �̱��� ���߿� "�ּ��� �ڵ�"�� �˷��� �ֽ��ϴ�.



class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}


	// ��Ģ 2. ���� �����ڿ� ���Կ����ڸ� �����Ϸ��� ������ ���ϰ� �Ѵ�.
	Cursor(const Cursor&) = delete; // ������ �޶�!

	Cursor& operator=(const Cursor&) = delete; 
								// => ���� ������ ������ ����������
								//    ���� �����ڵ� ����


	// ��Ģ 3. ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ� static ��� �Լ�
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c1, c2; // error. private ������
//	Cursor c3 = c1; // ���� �����ڵ� ����Ҽ� ���� �ؾ� �մϴ�.
}









