#include <iostream>

class Animal
{
public:
	// non-virtual : static binding, �����Ϸ��� ����Լ��� ȣ������ ����
	void cry1() { std::cout << "Animal Cry1" << std::endl; }

	// virtual : dynamic binding, ������ �ð����� �޸� ���� ���� ����
	//							  �����Ҷ� �Լ� ȣ�� ����.
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};
int main()
{
	Dog d;
	Animal* p = &d;

	// 1. ��� �Լ� ȣ���, static binding ����, dynamic binding ���� �����ؾ� �մϴ�.
	// 2. �����Ϸ��� "p�� Animal*" ��� �͸� �˰� �ֽ��ϴ�.
	// 3. ����, Animal Ŭ���� ������ ����, �� ��� �Լ��� �������� �ƴ��� �����մϴ�
	p->cry1();	// virtual �� �ƴϹǷ� ������ �Ҷ� "call Animal cry1" Ȯ��!!
	p->cry2();  // virtual �̹Ƿ� p�� �޸� ���� ���� �ڵ� ����
				// ����� ����� ���� ȣ��.
}

// godbolt.org : �پ��� ����� "������ڵ�(����)�� ���� �ִ� ����Ʈ