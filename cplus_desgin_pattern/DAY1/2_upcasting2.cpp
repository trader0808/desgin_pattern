// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// Upcasting Ȱ�� #1
	std::vector<Dog*>    v1; // Dog ��ü�� �����ϴ� �����̳�!!
	std::vector<Animal*> v2; // ����(���� ��� Ŭ������ ����ϴ� Ÿ��)�� ���尡��
						     // Animal �� ���� �Ļ��� ��� Ŭ������ ��ü��
							// ���尡��

}