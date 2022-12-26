// 5_�޴��̺�Ʈ4
#include "PopupMenu.h"

// ��� 3. �Լ� ������ ��� �޴� �̺�Ʈ ó��

class MenuItem : public BaseMenu
{
	int  id;

	void(*handler)() = nullptr;
public:
	void set_handler( void(*f)() ) { handler = f; }

	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		if (handler)
			handler();
	}
};

//
void f1() { std::cout << "f1" << std::endl; }


int main()
{
	MenuItem m("FHD", 11);

	m.set_handler(&f1); // �̺�Ʈ ó�� �Լ� ����

	m.command();
}





