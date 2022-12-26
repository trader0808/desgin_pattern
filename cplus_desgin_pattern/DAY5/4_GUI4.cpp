#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;

std::map<int, Window*> this_map;


class Window
{
	int handle;

	Window* parent = nullptr;		// �θ� ������� �Ѱ� �Դϴ�
	std::vector<Window*> child_vec; // �ڽ� ������� ������ �Դϴ�.

public:
	
	void AddChild(Window* child)
	{
		child_vec.push_back(child);
		child->parent = this;

		// C �Լ��� �����츦 �ڽ�������� ����
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
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown(); break; 
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};



//==================================================

class MainFrame : public Window
{
public:
	virtual void OnLButtonDown() override
	{
		std::cout << "MainFrame OnLButtonDown" << std::endl;
	}
};

class ImageView : public Window
{
public:
	virtual void OnLButtonDown() override
	{
		std::cout << "ImageView OnLButtonDown" << std::endl;
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







