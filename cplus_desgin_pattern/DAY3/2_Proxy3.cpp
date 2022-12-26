#define USING_GUI
#include "cppmaster.h"


// RPC : Remote Procedure Call. �ٸ� ���μ����� �Լ��� ȣ���ϴ� ��
//		 java ������ "RMI(Remote Method Invocation)"


// ������ ������(Proxy)�� ����� �������� �����ϱ� ����
// �������̽� ����

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;

	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* pcalc = new Calc;

	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





