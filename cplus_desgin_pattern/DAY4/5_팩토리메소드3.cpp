// 5_���丮�޼ҵ�
#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXEdit" << std::endl; }
};
//--------------------------------------
// �� System �� ��Ʈ���� �̸��� �˷��ִ� ����ü�� ���� ����
struct Window
{
	using Button = WinButton;  // typedef WinButton Button; �ǹ�
	using Edit   = WinEdit;
};

struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;
};

template<typename T>
class Dialog
{
public:
	void init()
	{
		IButton* btn = new typename T::Button;
		IEdit* edit = new  typename T::Edit;

		// btn->Move(); edit->Move();
		btn->Draw();
		edit->Draw();
	}
};
int main(int argc, char** argv)
{
//	Dialog<Window> dlg;
	Dialog<OSX> dlg;
	dlg.init();
}








