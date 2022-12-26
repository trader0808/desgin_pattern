// 메뉴 이벤트1.cpp     메뉴5번 복사해오세요

#include "PopupMenu.h"

class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		// 여기서 어떤 작업을 직접하면
		// 모든 메뉴가 동일한 작업을 하게 됩니다.
		// 메뉴 선택시 해야할 일을 각 메뉴 마다 달라야 합니다.
	}
};
int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new MenuItem("FHD", 11));
	root->add_menu(new MenuItem("UHD", 12));

	// 이제 시작하려면 ?
	root->command();
}





