// 3_�߻����丮 - 147
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
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};

int main(int argc, char** argv)
{
	// �� System �� ��Ʈ�� Ŭ������ ����
	// ������ ��� Ŭ������ �ʿ� �ϴ�.
	IButton* btn;

	if (strcmp(argv[0], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// �׷���, ���α׷����� "��ư�� �ѹ��� ����� �ɱ� ????"
	// ��Ʈ���� ���鶧 ���� ��ó�� �����Ҽ��� �����ϴ�.
	// => Style ��, ��Ʈ���� ����� "����"�� �ʿ� �մϴ�.
}








