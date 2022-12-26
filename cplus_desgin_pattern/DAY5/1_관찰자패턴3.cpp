#include <iostream>
#include <vector>

class Subject;

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}

	// �����ڵ�(Graph) �� �ڽ��� ������ ���������� �˾ƾ� �մϴ�.
	Subject* subject = nullptr;
};



class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p) 
	{
		v.push_back(p); 

		p->subject = this;
	}

	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

// �ٽ� : ������ ���(Table)�� �ٷ�� ����Ÿ�� �����ϰ� �ִ� ���.
class Table : public Subject
{
	int value;

	int income[12] = { 1,3,5,7,9,2,4,6,8,10,11,12 }; // ���� ����
public:

	int* get_income() { return income; }


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
	// ������ ����� ����Ǹ� �Ʒ� �Լ��� ȣ��˴ϴ�.
	void Update(int n) override
	{
		// ���� Table �� �����ؼ� ����� ����Ÿ�� �ٽ� �о
		// ȭ�鿡 ����ϸ� �˴ϴ�.

//		int* income = subject->get_income(); // error
											// subject �� "Subject*" �̹Ƿ�
											// ĳ���� �ʿ�
		int* income = static_cast<Table*>(subject)->get_income();

		std::cout << "Bar Graph : ";

		for (int i = 0; i < 12; i++)
			std::cout << income[i] << ", ";

		std::cout << std::endl;
	}
};






class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		int* income = static_cast<Table*>(subject)->get_income();

		std::cout << "Pie Graph : ";

		for (int i = 0; i < 12; i++)
			std::cout << income[i] << ", ";

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





