#include "PopupMenu.h"

// ��� 2. ���ϴ� ���� �ٸ� Ŭ������!!!
// => �޴� ���ý�, �������̽��� ��ӵ� �Լ��� ȣ��
// => java, �ȵ���̵��� "������" ���
// => ��ü���� ���� ���� �θ� ���Ǵ� ���

// Ư¡ : ������ �޴��� �Ѱ��� �Լ����� ó���ϰ� �Ǵ� ��찡 ��������
//        Ŀ�ٶ� switch-case �� ����� �ȴ�.


// �޴� �̺�Ʈ�� ó���ϰ� ���� ��� Ŭ������
// �ݵ�� �Ʒ� �������̽��� �����ؾ� �Ѵ�.

struct IMenuListener
{
	virtual void on_command(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
	int  id;
	IMenuListener* ps = nullptr;
public:
	void set_listener(IMenuListener* p) { ps = p; }

	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		if (ps != nullptr)
			ps->on_command(id);
	}
};
//=========================================
// ���� ���α׷��� �����ϴ� �پ��� Ŭ������ �߿��� �޴��� ó���ϰ� �ʹٸ�
// ��ӵ� ��Ģ�� ���Ѿ� �մϴ�.
class Camera : public IMenuListener
{
public:
	// ....�پ��� �����...

	virtual void on_command(int id) override
	{
		std::cout << "Camera ��ü�� �޴� �̺�Ʈ ó��" << std::endl;

		// ���ʰ��� �޴��� �̰����� ó���ϰ� �ȴٸ�
		// "�Ŵ��� switch ~ case" �� ������ �˴ϴ�.
		switch (id)
		{
		case 11: break;
		case 12: break;
		}
		_getch();
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	MenuItem* m1 = new MenuItem("FHD", 11);
	MenuItem* m2 = new MenuItem("UHD", 12);

	root->add_menu(m1);
	root->add_menu(m2);

	// �� �޴��� �̺�Ʈ�� ó���� ��ü�� ����
	Camera* cam = new Camera;
	m1->set_listener(cam);
	m2->set_listener(cam);


	root->command();
}





