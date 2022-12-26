#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��� �޴��� ������ ��� Ŭ����
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title; }

	// ��� �޴��� ���õɼ� �ִ�.
	// ��� �Ļ� Ŭ����(�޴�)�� ������ Ư¡�� �ݵ�� ��� Ŭ�������� �־���Ѵ�.
	virtual void command() = 0;

};




class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " �޴� ���õ�" << std::endl;

		_getch(); 
	}
};


class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}


	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls"); 

			std::size_t sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
			}
			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				return;       


			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command(); // ������!!
									// � ������ �޴����� ������ �ʿ� ����.
		}


	}
};




int main()
{
	MenuItem m1("�Ұ����", 11);
	MenuItem m2("��ġ���",   12);

	PopupMenu pmkimbam("����");
	pmkimbam.add_menu(&m1);
	pmkimbam.add_menu(&m2);

	MenuItem m3("���", 21);

	PopupMenu pm("������ ���� �޴�");
	pm.add_menu(&pmkimbam); // �ٽ�!!!
	pm.add_menu(&m3);

	pm.command();	
}




