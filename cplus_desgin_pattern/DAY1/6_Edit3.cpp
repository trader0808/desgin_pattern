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



	std::string getData()
	{
		data.clear();

		while (1)
		{

			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))  )
				break;

			if ( pval == nullptr || pval->validate(data, c) ) // ���� ��ȿ�� Ȯ���� �ٸ���ü�� ����
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << "\n";
		return data;
	}
};





int main()
{
	Edit e;	
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


