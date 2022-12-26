#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��ü���� ���α׷����� ��� ���� "��ü"�̴�.

class MenuItem
{
	std::string title;
	int  id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " �޴� ���õ�" << std::endl;

		_getch(); // �ƹ�Ű�� ���������� ���
	}
};


class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* p) { v.push_back(p); }

	// �˾� �޴��� �����Ҷ�!!
	void command()
	{
		while (1)
		{
			system("cls"); // ȭ�� �����

			std::size_t sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
			}
			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) // ���� �޴� ���ý�
				return ;       // �Ǵ� break


			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;


			// ���õ� �޴� ����
			v[cmd - 1]->command();
		}


	}
};




int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	PopupMenu pm("������ ���� �޴�");
	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();	// �˾� �޴��� �����Ҷ� �ؾ� ������ ������ ������ ?
					// 1. ���
					// 2. ���
					// 3. ����
					// �޴��� �����ϼ��� >>
}




