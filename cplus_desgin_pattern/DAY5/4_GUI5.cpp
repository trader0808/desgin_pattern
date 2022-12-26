#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;

std::map<int, Window*> this_map;


class Window
{
	int handle;

	Window* parent = nullptr;		
	std::vector<Window*> child_vec; 

public:

	void AddChild(Window* child)
	{
		child_vec.push_back(child);
		child->parent = this;

		ec_add_child(this->handle, child->handle);
	}





	void Create(const char* title)
	{
		handle = ec_make_window(&msg_handler, title);

		this_map[handle] = this;
	}


	static int msg_handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->HandleLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown(); break;
		}
		return 0;
	}

	// �Ʒ� �Լ��� "å���� ��" ������ �ٽ� �����Դϴ�.
	// => chain_of_responsiblity1.cpp �ҽ��� Handler::Handle �� �����մϴ�.

	void HandleLButtonDown()
	{
		// 1. �ڽ��� ���� ��û�� ó���� �õ�
		if (OnLButtonDown() == true)	// ��û�� ó���� ���
			return;						// ��û ó�� ����!

		// 2. ��û(LBUTTONDOWN)�� ó������ ���� ���
		// �θ� �����찡 �ִٸ� �θ� ������� ����
		if (parent != nullptr)
			parent->HandleLButtonDown(); // ����! OnLButtonDown�� �ƴմϴ�.
	
	}




	virtual bool OnLButtonDown() { return false; }
	virtual bool OnKeyDown() { return false; }
};





//==================================================

class MainFrame : public Window
{
public:
	virtual bool OnLButtonDown() override
	{
		std::cout << "MainFrame OnLButtonDown" << std::endl;
		return true;
	}
};

class ImageView : public Window
{
public:
	virtual bool OnLButtonDown() override
	{
		std::cout << "ImageView OnLButtonDown" << std::endl;
		return true;
	}
};


int main()
{
	MainFrame w;
	w.Create("A");

	ImageView iv;
	iv.Create("image view");

	w.AddChild(&iv);

	ec_process_message();
}







