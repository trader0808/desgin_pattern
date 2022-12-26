// 5_�޴��̺�Ʈ5 - 1�� �����ؿ�����.
#include "PopupMenu.h"
#include <functional> // std::bind(), std::function<>
using namespace std::placeholders;

class MenuItem : public BaseMenu
{
	int  id;
	using HANDLER = std::function<void()>;  // typedef�� �����ϴ�.

	std::vector< HANDLER > v;
public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr) 
		: BaseMenu(title), id(id) 
	{
		if ( h != nullptr )
			v.push_back(h);
	}

	void add_handler(HANDLER h) { v.push_back(h); }

	void command()
	{
		for (auto handler : v)
			handler();   // �ᱹ function Ÿ�԰�ü�̹Ƿ�
						 // �Լ�ó�� ()�� ȣ���ϸ� �˴ϴ�.
	}
};
//====================================================
void f0()       { std::cout << "f0" << std::endl; }
void f1(int id) { std::cout << "f1 : " << id << std::endl; }

class Dialog
{
public:
	void close() { std::cout << "Dialog Close" << std::endl; }

	static void foo() { std::cout << "Dialog foo" << std::endl; }
};
//-------------------------------------------------

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	// 1. f0�� "void()" ����̹Ƿ� std::bind()�ʿ� �����ϴ�.
	root->add_menu(new MenuItem("�޴�1", 11, &f0));

	// 2. ���ڰ� �ٸ� �Լ��� std::bind()�� "0���Լ�"�� ������ �մϴ�.
	root->add_menu(new MenuItem("�޴�2", 12, std::bind(&f1, 12)));
	root->add_menu(new MenuItem("�޴�3", 13, std::bind(&f1, 13)));

	// 3. ��� �Լ��� ��ü�� �ʿ� �մϴ�.
	Dialog dlg;
	root->add_menu(new MenuItem("�޴�4", 14, std::bind(&Dialog::close, &dlg)));

	// 4. static ��� �Լ��� ��ü ��� �˴ϴ�.
	root->add_menu(new MenuItem("�޴�5", 16, &Dialog::foo));


	MenuItem* m = new MenuItem("�޴�6", 17);
	root->add_menu(m);

	// 5. ���� ǥ���ĵ� �˴ϴ�.
	m->add_handler([]() { std::cout << "lambda" << std::endl; });

	// 6. �ϳ��� �޴��� ������ ��� �ص� �˴ϴ�.
	m->add_handler(&f0);
	

	root->command();
}





