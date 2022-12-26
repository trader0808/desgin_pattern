// bind1.cpp
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ...

void f4(int a, int b, int c, int d)
{
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4); // f4�� 4�� �Լ� �Դϴ�.

	// std::bind() : M���Լ��� N �� �Լ��� �����ϴ� ����(��, M > N)
	// ����       : std::bind(M���Լ��ּ�, M�� ����)

	std::bind(&f4, 1, 2, 3, 4) ( ); // �ᱹ f4(1,2,3,4)
	//<--����� �ٽ� �Լ�----->|		// "4���Լ�" => "0���Լ�" �κ���

	std::bind(&f4, 5, _1, 9, _2) (6, 3);// f4(5, 6, 9, 3) �� ���
										// "4���Լ�" => "2���Լ�"

	std::bind(&f4, _3, 2, _1, _2 )(7, 9, 3); // f4(3, 2, 7, 9) �� ���
										// "4���Լ�" => "3���Լ�"�� ����
}

// Currying ����
// => ���� �Լ��� ���ڸ� ������ ���ο� �Լ��� ����� ����
// => �Լ��� ���(Functional Language) �� ��ǥ���� ������ ���

// Python : functools.partial() �� �̷� ���� �ϴ� ���� �Դϴ�.

