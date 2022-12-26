#define USING_GUI
#include "cppmaster.h"


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

// ������ ������(Proxy) �� ���� ����� �ɱ�� ?

// 1. Server ������ <== ����
// 2. Client ������


int main()
{
	// �Ʒ� ó�� ����� "Ŭ���̾�Ʈ�� Proxy"�� 
	// ���� �������� ����ϰ� �˴ϴ�.
	// "���ο� Proxy" �� ���� �Ǹ�
	// Ŭ���̾�Ʈ �ڵ尡 �����ǰ� �˴ϴ�.
	// Calc* pcalc = new Calc;

	// Ŭ���̾�Ʈ�� Proxy ���� ���� �������� ����ؾ� �մϴ�.

	ICalc* pcalc = new ? ? ? ; // ����
								// => "Calc" ��� Ŭ���� �̸�����
								//    ��ü ������ �ʿ�.!
								// => Proxy �� �������(.dll, .so) �� �����ؾ� �Ѵ�



	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





