#define USING_GUI
#include "cppmaster.h"

#include <map>

class Window;

// ������ ��ȣ�� Ű������ this �� �ڷᱸ���� �����ϴ� ���!!!
// => this�� �ڷᱸ���� ������, static ������� ����ϴ� �����
//    ���� �θ� ���˴ϴ�.
std::map<int, Window*> this_map;


class Window
{
	int handle;
public:

	void Create(const char* title)
	{
		handle = ec_make_window(&msg_handler, title);

		this_map[handle] = this;
	}


	static int msg_handler(int hwnd, int msg, int a, int b)
	{
		// ������ ��ȣ�� Ű������ �����ص� this�� ��������
		// static ��� �Լ������� ��� ��� ���� �����մϴ�.
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown(); break;  // this->OnKeyDown()
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};



//==================================================
// �� Ŭ������ ���̺귯�� ���� Ŭ���� �Դϴ�.
// ���� ���̺귯�� ����ڴ� "Window" ���� �Ļ� Ŭ������ ����
// �̺�Ʈ ó���� ���� ��ӵ� �����Լ��� ������ �մϴ�.
class MainFrame : public Window
{
public:
	virtual void OnLButtonDown() override
	{
		std::cout << "MainFrame OnLButtonDown" << std::endl;	
	}
};
int main()
{
	MainFrame w;
	w.Create("A");	

	ec_process_message();
}
