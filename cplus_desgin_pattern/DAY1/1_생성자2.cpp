// 1_������2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// ��ü�� �����ϰ� ����ϰ� �Ϸ���
	// �׻� �����ڷ�.. ��� ����Ÿ�� �ʱ�ȭ �ϴ� ���� �����ϴ�.
	People(const std::string& name, int age)
		: name(name), age(age)
	{
	}
};
int main()
{
//	People p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? 
				// (�ʱ�ȭ ���� ���� ��ü)
				// error

	People p2("kim", 20); // ok.. ��� ����� ���鶧 
						// �ʱ�ȭ �Ǿ�� �Ѵ�.
}


