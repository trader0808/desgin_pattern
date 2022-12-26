#include <iostream>
// upcasting3.cpp
class Animal
{
public:
	virtual ~Animal() {} // ��� ��� Ŭ������ �Ҹ��ڴ� �����Լ� �̾�� �մϴ�
	int age;
};
class Cat : public Animal
{
};
class Dog : public Animal
{
public:
	int color;
};

void NewYear(Animal* p)
{
	++(p->age);

	// ������ ���� �䱸������ �����..
	// p�� Dog�� ����Ű�� ���� �����ϰ� �ʹ�

	// ���Լ��� ���ڰ� "Animal*" �� ����Ǿ��ٴ� ����
	// => �� �Լ� �ȿ����� ��� ������ ������ �۾��� �ϰڴٴ� ��
	// => ���ο� �䱸������ ����� ���ο� �Լ��� ���弼��
}

void NewYear(Dog* p)
{
	// ���� NewYear�� �ٽ� ȣ���ؼ� ������ �۾��� ���� ����
	NewYear(static_cast<Animal*>(p));

	// �߰� �䱸���� ����
	p->color = 10;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);

}











