//1_����������1 - 94 page
#include <iostream>
#include <vector>

// ��� �׷����� ������ ��� Ŭ����(�������̽�)�� �ʿ� �Ѵ�.
struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};






class Table
{
	std::vector<IGraph*> v;
	int value; // table �� data ��
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// ��ϵ� ��� �׷����� �˷��ش�.
		for (auto p : v)
			p->Update(data);
	}
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);	// data �� �����Ǹ� ��ϵ� ���
							// Graph �� �뺸�Ѵ�.
		}
	}
};

//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};


class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << ")";

		std::cout << std::endl;
	}
};


int main()
{
	Table t;
	PieGraph pg; t.attach(&pg);
	BarGraph bg; t.attach(&bg);
	t.edit();
}





