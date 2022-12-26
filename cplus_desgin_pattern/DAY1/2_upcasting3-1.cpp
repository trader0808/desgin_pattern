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
	// p->color = 10; // error. p�� Animal* !!

	// static_cast : ������ �ð�(static) ĳ��Ʈ. p�� ����Ű�� ���� ���� Dog ����
	//				 �������� �ʰ�, ĳ����. 
	//				=> p�� ����Ű�� ���� Dog ��� Ȯ���� �������� ����ؾ��Ѵ�
	// Dog* pDog = static_cast<Dog*>(p);

	// dynamic_cast : ����ð�(dynamic) ĳ��Ʈ.
	//				  ����ð��� p�� ����Ű�� �޸𸮸� ������..
	//				  ��ü�� ���� Dog �϶��� ����..
	//				  Dog�� �ƴϸ� 0 ��ȯ
	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	
}











