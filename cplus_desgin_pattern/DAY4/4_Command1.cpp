#include <iostream>
#include <vector>
#include <stack>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// C ��� : ���α׷��� �⺻�� "�Լ�"
// => �޴� ���ý� �ؾ��� ���� �Լ��� �ۼ�
// => "�ؾ��� ��" �� �ۼ��Ѵ�.

// C++ ��� : ���α׷��� �⺻�� "Ŭ����"
// => �޴� ���ý� �ؾ��� ���� Ŭ������ �ۼ�
// => "�ؾ��� �� + ��ҵ��� + ��Ÿ ���" ���� ��� �����Ҽ� �ִ�.


// Command ����
// => ����� ĸ��ȭ �ؼ� "����� ����/���/����" �� �����ϰ� �Ѵ�.
// => ����� �ڷ� ������ �����ϰų�, �Լ� ���ڷ� ���޵� �����ϴ�.


//----------------------------------------------------------
// ��� ����� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� �޴��� ���� ��ɰ�ü
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new Rect); }
	virtual bool can_undo() override { return true; }

	virtual void undo() override
	{
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}
};

class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new Circle); }
	virtual bool can_undo() override { return true; }

	virtual void undo() override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override 
	{
		for (auto p : v) p->draw();
	}
	virtual bool can_undo() override { return true; }

	virtual void undo() override
	{
		system("cls");
	}
};



int main()
{
	std::vector<Shape*> v;

	ICommand* pcmd = nullptr;

	std::stack<ICommand*> cmd_stack;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pcmd = new AddRectCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);

		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);

		}
		else if (cmd == 0)
		{
			if (!cmd_stack.empty())
			{
				pcmd = cmd_stack.top();
				cmd_stack.pop();

				if (pcmd->can_undo())
					pcmd->undo();

				delete pcmd;		// redo �Ϸ��� delete ���� ����
									// redo_stack.push(pcmd) �ϸ� �˴ϴ�.
			}
		}
	}
}




