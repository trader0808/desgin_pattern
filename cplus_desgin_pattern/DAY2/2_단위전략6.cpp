#include <iostream>
#include <vector>
#include <memory> // C++ ǥ�� �޸� �Ҵ��

int main()
{
	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	// => �Ʒ� ó�� ����, �޸� �Ҵ� ����� �����Ϸ��� ��� ������ �����ؾ� �մϴ�.
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;



	// 2. allocator ���
	// => �ǵ� : �޸� �Ҵ� ����� �����Ϸ��� "�Ҵ��" �� ���Ӱ� ����� �ȴ�.
	// =>       �Ҵ�⸦ ����ϴ� �ڵ�� ����� �ʿ� ����.

	std::allocator<int> ax;  // C++ ǥ�� �޸� �Ҵ��
//	MyAlloc<int> ax;  // ����ڰ� ���� �޸� �Ҵ��!!

	int* p = ax.allocate(10);	// int �� 10�� �Ҵ��� �޶�.
								// ǥ�� �Ҵ��� "new" ����ؼ� �Ҵ�

	ax.deallocate(p, 10);		// �޸� ����, 
								// ǥ�� �Ҵ��� "delete" ���


}