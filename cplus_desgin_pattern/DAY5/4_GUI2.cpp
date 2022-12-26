#define USING_GUI
#include "cppmaster.h"

class Window
{
	int handle;
public:
	void Create(const char* title)
	{
		handle = ec_make_window(&msg_handler, title);
	}

	// �ٽ� : �Ʒ� �Լ��� static ��� �Լ��� �ؾ� �ϴ� ������ �ݵ�� ���� �ؾ� �մϴ�.
	// => ec_make_window �� C��� ��� �Լ� �ε�, 1��° ���ڷ� ���ڰ� 4���� �Լ���
	//    �䱸 �մϴ�.
	// => Ŭ���� ��� �Լ��� ���ڰ� "int 4��" �� �Լ��� �������
	//    static ��� �Լ� �ۿ� �����ϴ�
	// => static �� �ƴϸ� "this" �߰� �˴ϴ�.

	static int msg_handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN" << std::endl; break;
		}
		return 0;
	}

};

int main()
{
	Window w;
	w.Create("A");	// �̼��� �����찡 �����Ǿ�� �մϴ�.				 
					// ���콺 ������ "LBUTTON" ���;� �մϴ�.

	ec_process_message();
}
