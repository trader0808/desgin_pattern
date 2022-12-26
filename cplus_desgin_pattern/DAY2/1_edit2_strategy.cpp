#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� �ڵ带 �и��ϴ� 2���� ���

// 1. ���ϴ� ���� �����Լ��� !! => template method ����
// 2. ���ϴ� ���� �ٸ� Ŭ������ => strategy ����.

// ��� Validation ��å�� �Ʒ� �������̽��� �����ؾ� �Ѵ�.

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};
// �ֹ� ��� ��ȣ : 931   1    Ȯ��



class Edit
{
	std::string data;

	IValidator* pval = nullptr; // ���� ��ȿ���� Ȯ���Ҷ� ����� ��ü
public:
	void setValidate(IValidator* p) { pval = p; }



	std::string get_data()
	{
		data.clear();

		while (1)
		{

			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->iscomplete(data)))
				break;

			if (pval == nullptr || pval->validate(data, c)) // ���� ��ȿ�� Ȯ���� �ٸ���ü�� ����
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << "\n";
		return data;
	}
};


// ���� Edit ���� ����� �پ��� "validation ��å�� ����"
// Ŭ������ �����ϸ� �˴ϴ�.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}

	virtual bool iscomplete(const std::string& s) override
	{
		return s.size() == limit;
	}
};


int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidate(&v);	// edit �� validation ��å ����

	LimitDigitValidator v2(15);
	e.setValidate(&v2); // �����ϴ� validation ��å��ü
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


// ���ϴ� ���� �ٸ� Ŭ������
// => strategy
// => validation ��å�� �ٸ� �Էµ�����
//    ��밡��.
// => validation ��å�� ����ð��� �����Ҽ� �ִ�

// Edit �� Validation ��å ��ü����
// => Strategy ����(���ϴ� ���� �ٸ� Ŭ������)�� ����.

// ������, ������������ draw_imp() �� ����
// => �簢���� �׸��� ����� "Rect" �� ����ϸ� �ǰ�
//    ����ð��� ��ü�� �ʿ� ����.
// => ����� ����� �ǹǷ� private ���ٵ� ���ϴ�.
// => "template method(���ϴ°� �����Լ���)�� ����."