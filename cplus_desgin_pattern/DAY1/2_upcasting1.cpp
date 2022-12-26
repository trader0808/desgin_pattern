class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d;		// ok..
	int* p2 = &d;		// error.

	// �ٽ� 1. ��� Ŭ���� �����ͷ� �Ļ�Ŭ���� �ּҸ� ������ �ִ�.
	Animal* p3 = &d;	// ok.. upcasting
	Animal& r = d;      // ok.


	// �ٽ� 2. ��� Ŭ���� �����ͷδ� ��� Ŭ���� ����� �����Ҽ� �ִ�.
	// => ���� : ��� ���ٽ�, �����Ϸ��� �׻� ��ü(������)�� Ÿ�Ը����� 
	//           ���� ���ɿ��θ� �Ǵ��ϹǷ�
	//			 p3�� Animal* �̸� p3�δ� Animal ����� ���� ����.
	//			(���ɰ� �������� ���� ������ �ð��� ���� Ȯ���ϴ� �ϱ� ����
	//			 static type check ���)
	p3->age = 10;   // ok
//	p3->color = 10; // error

	// �ٽ� 3. Animal* �� p3�� �Ļ� Ŭ���� ���� ����� �����Ϸ���
	//        => ĳ���� �ϸ� �˴ϴ�.
	static_cast<Dog*>(p3)->color = 10;
	// => ��, �� ��� p3�� ����Ű�� ���� Dog��� Ȯ���� �־�� �մϴ�.
	// => ���ٸ�, dynamic_cast�� ����� ����


}












