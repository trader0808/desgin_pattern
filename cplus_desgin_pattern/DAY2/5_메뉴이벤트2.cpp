#include "PopupMenu.h"

// ��� 1. ���ϴ� ���� �����Լ���
// => �� �޴� �Ѱ���, Ŭ���� �Ѱ�(MenuItem �Ļ� Ŭ����)�� ������ �Ѵ�.
// => �޴��� �������� Ŭ������ ��������.

// => ���� Ŭ������ �ʹ� ���� ����� Ư¡�� �ִ�.

class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		// �޴� ���ý� �������� �ؾ��� ���� �ִٸ� 
		// ���⼭ �����۾��� �ϰ�
		// �ٽ� �����Լ� ȣ��.!
		do_command();
	}

	virtual void do_command() {}
};

class FHDMenu : public MenuItem
{
public:
//	FHDMenu(const std::string& title, int id) : MenuItem(title, id) {}

	// �� �����ڴ� ���޹��� ���ڸ� ��� Ŭ������ �����⸸ �մϴ�.
	// �� ���, C++11 ���ʹ� �Ʒ� ó���ϼ���
	// "������ ���" �̶�� ����
	using MenuItem::MenuItem;  // MenuItem �� ��� �����ڸ� ����� �޶�.   

	virtual void do_command() override
	{
		std::cout << "FHD�� �����ϴ� �ڵ�" << std::endl;
		_getch();
	}
};

class UHDMenu : public MenuItem
{
public:
	using MenuItem::MenuItem;

	virtual void do_command() override
	{
		std::cout << "UHD�� �����ϴ� �ڵ�" << std::endl;
		_getch();
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new FHDMenu("FHD", 11));
	root->add_menu(new UHDMenu("UHD", 12));
	
	root->command();
}





