// 3_chain_of_responsibility.cpp			- 179 page

#include <iostream>

struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 1. �ڽ��� ���� �����Լ��� ȣ���ؼ� ó���� �õ�
		if (HandleRequest(problem) == true)
			return;

		// 2. �ڽ��� ó������ ���� ��� ���� ���� ��û�� �ٸ� ��ü�� ����
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};
// �� Handler �� å���� ���� ������ �⺻ ������ �����Ѱ�
// ���� ��û�� ó���ϴ� �پ��� Ŭ������ ���� �ϸ� �˴ϴ�.

class TenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "Start TenHandler" << std::endl;

		if (problem == 10)
		{
			std::cout << "Resolve!!! Problem" << std::endl;
			return true;
		}
		std::cout << "Finish TenHandler" << std::endl;
		return false;
	}
};

class OddHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "Start OddHandler" << std::endl;

		if (problem % 2 == 1)
		{
			std::cout << "Resolve!!! Problem" << std::endl;
			return true;
		}
		std::cout << "Finish OddHandler" << std::endl;
		return false;
	}
};

class More100Handler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "Start More100Handler" << std::endl;

		if (problem >= 100)
		{
			std::cout << "Resolve!!! Problem" << std::endl;
			return true;
		}
		std::cout << "Finish More100Handler" << std::endl;
		return false;
	}
};

int main()
{
	TenHandler h1;
	OddHandler h2;
	More100Handler h3;

	// Ten => Odd => More100
	h1.next = &h2;
	h2.next = &h3;

//	h1.Handle(10);
//	h1.Handle(120);
	h1.Handle(77);
}