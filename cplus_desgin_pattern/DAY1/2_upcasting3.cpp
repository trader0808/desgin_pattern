// upcasting3.cpp
class Animal 
{
public: 
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

// Upcasting Ȱ�� #2. ������ ó���ϴ� �Լ� �����.
//void NewYear(Dog* pDog)	// Dog ��ü�� ������ �ִ� �Լ�
void NewYear(Animal* p)		// ��� ������ ������ �ִ� �Լ�. 
{
	++(p->age); 
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











