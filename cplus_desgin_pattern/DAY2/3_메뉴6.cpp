#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class InvalidOperation : std::exception {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title; }

	virtual void command() = 0;

	// BaseMenu �� �Ʒ� ó�� �����Ѵٸ�.
	// 
	// root->get_sub_menu(0)->add_item( ....) ó�� ��밡���մϴ�.
	// ��, "root->get_sub_menu(0)" �� Popup �� �ƴϸ� ���� �߻�

	virtual void add_menu(BaseMenu*) { throw InvalidOperation(); }
	virtual BaseMenu* get_sub_menu(int idx) { throw InvalidOperation(); }
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

			v[cmd - 1]->command();
		}


	}

	BaseMenu* get_sub_menu(int idx)	{ return v[idx];}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	
	MenuItem* mi1 = new MenuItem("����", 11);

	root->add_menu(pm1);
	root->add_menu(mi1);

	// ���� �޴��� ��� get_sub_menu() �� ������ ���ô�.
//	root->get_sub_menu(0); // ok

	root->get_sub_menu(0)->add_menu(new MenuItem("HD",  21));
	root->get_sub_menu(0)->add_menu(new MenuItem("FHD", 22));

//	root->get_sub_menu(1)->add_menu(new MenuItem("�űԸ޴�", 31)); // ����!!

	// ���� �����Ϸ��� ?
	root->command();
}





