#include <iostream>
#include <vector>


struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};




// ������ ���(Table) �� �ٷ�� ����Ÿ�� ���¿� ������� 
// ������ ������ �⺻ ������ �����մϴ�.

// ������ ������ �⺻ ������ �����ϴ� ��� Ŭ������ �����մϴ�.
// => ������ ���Ͽ��� �� Ŭ������ "Subject" ��� �մϴ�.

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{	
		for (auto p : v)
			p->Update(data);
	}
};

class Table : public Subject
{
	int value; 
public:
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);	
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





