#include <iostream>
#include <string>
#include <conio.h>


// Edit �� �Է� ���� ��ȿ���� Ȯ���ϴ� "Validation" ����� �־� ���ô�.

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();

		while (1)
		{
			
			char c = _getch();

			if (c == 13) // enter Ű
				break;

			if (isdigit(c))
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
	Edit e;	// �̼��� ȭ�鿡 edit ��Ʈ���� ��Ÿ���ٰ� ����..
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


