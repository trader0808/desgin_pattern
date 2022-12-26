#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age)
		: name(name), age(age)
	{
	}
};
// 1. People ���� �Ļ��� Student ����� ������
// 2. �й�(int id) �� ��� ����Ÿ�� �߰��ϼ���
// 3. ������ ���弼��

class Student : public People
{
	int id;
public:
	// �����ڸ� �Ʒ�ó�� ����� �ȵ˴ϴ�.
	// ����� �ڵ�				// �����Ϸ��� ������ �ڵ�
//	Student(int id) : id(id) {} // Student(int id) : People(), id(id) {} 

	// ��� Ŭ������ People �� ����Ʈ �����ڰ� �����Ƿ�
	// �ݵ�� "�̸��� ���̸� ����"�ؾ��մϴ�.
	Student(const std::string& name, int age, int id)
		: People(name, age), id(id) {}
};

int main()
{
	// Student ��ü ������ ������
	Student s("kim", 20, 99);
}







