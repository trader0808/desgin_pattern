#define USING_GUI
#include "cppmaster.h"

// Proxy ���� : ���� ����� �����ڸ� ����� ����
// remote proxy : ������ ������ ���� ������

// ���� 
// 1. "1", "2" �� �ƴ� "Add", "Sub" �� ����Ҽ� �ִ�.
// 2. ���� ����ϴ� ���꿡 ���� ĳ�� ���� ����
// 3. Client �� ��ȭ ���� ������ ���� update ����.


// Proxy : �Լ� ȣ��(Add) �� ����ڵ�(1)�� �����ؼ� ������ ����
// 
// Stub  : ������ ����ڵ�(1) �� �ٽ� �Լ�ȣ��(Server.Add) �� ����

// ���� "proxy-stub" ��� �̶�� �մϴ�. 
// server�� �ִ� "handler" �Լ��� stub �Դϴ�.



// ������ "���" �ϴ� Ŭ������ ���� �մϴ�. 

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc");  }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* pcalc = new Calc;

	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





