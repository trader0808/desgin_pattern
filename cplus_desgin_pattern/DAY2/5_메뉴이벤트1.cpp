// �޴� �̺�Ʈ1.cpp     �޴�5�� �����ؿ�����

#include "PopupMenu.h"

class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		// ���⼭ � �۾��� �����ϸ�
		// ��� �޴��� ������ �۾��� �ϰ� �˴ϴ�.
		// �޴� ���ý� �ؾ��� ���� �� �޴� ���� �޶�� �մϴ�.
	}
};
int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new MenuItem("FHD", 11));
	root->add_menu(new MenuItem("UHD", 12));

	// ���� �����Ϸ��� ?
	root->command();
}





