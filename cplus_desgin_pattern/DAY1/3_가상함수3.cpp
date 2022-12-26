// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// �ٽ� 1. �����Լ� �����ǽ� 
	// => "virtual"�� �ٿ��� �ǰ� ���� �˴ϴ�.
	// => ������, ���̴� ���� �������� �����ϴ�.
	// virtual void foo() {}

	// �ٽ� 2. �����Լ� �����ǽ� ��Ÿ(�Ǽ�)�� ������
	// => ������ �ƴ� ���ο� �����Լ��� ��� �˴ϴ�.
	// => �̹����� �ʹ� �ɰ��ؼ� C++11 ���� "override" �� ���Խ��ϴ�.
	virtual void fooo() {}
	virtual void goo(double){}
};

class Derived2 : public Base
{
public:
	// �ٽ� 3. �����Լ� �����ǽ� �ǵ����̸� "override" ���̼���
	// => ���ο� �����Լ��� �ƴ϶�, �������ϰ� �ִٰ� �����Ϸ����� �˸��°�
	// => ��Ÿ �߻���, ������ ����.
	virtual void fooo()      override {} // error
	virtual void goo(double) override {} // error

};

int main()
{
}





