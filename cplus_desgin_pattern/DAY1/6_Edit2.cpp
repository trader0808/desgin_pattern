#include <iostream>
#include <string>
#include <conio.h>

// Validation ��å�� ����ڰ� ����(��ü)�Ҽ��־�� �Ѵ�.

// ��� 1. 

class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� ���� ���ؾ� �ϴ� �κ��� ã�´�.!!
	// => ���ؾ� �ϴ� �κ��� �����Լ��� �и��Ѵ�.
	virtual bool validate(char c)
	{
		return true;
	}

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13)
				break;

			if ( validate(c) ) // ���ؾ� �ϴ� ���� �����Լ� ȣ���!
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << "\n";
		return data;
	}
};

// ���� Validation ��å�� ��ü �Ϸ��� Edit �Ļ� Ŭ������ �����ؼ�
// validate �����Լ��� �������ϸ� �˴ϴ�.
class NumEdit : public Edit
{
public:
	virtual bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;	
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


