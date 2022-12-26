// CalcProxy.cpp 
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Proxy ����ڴ� DLL �ȿ� �ִ� Proxy �� Ŭ���� �̸��� �𸣰�,
// �� �ʿ䵵 ����, ����ص� �ȵ˴ϴ�.

// �̸� ��ӵ� �Լ��� Proxy ��ü�� ������ �ݴϴ�.
extern "C" __declspec(dllexport)
ICalc * Create()
{
	return new Calc;
}

// Proxy �� Update �Ǿ ���ο� ���� ����� ���͵�
// �ݵ�� "Create" �� �־�� �մϴ�.



// 1. "������ ���۹�ư" ��������
// 2. "Visual Studio ����" ã������
// 3. �������� "������ ���������Ʈ(Develop command prompt) �����ϼ���"

// ������ C++ �����Ϸ�     : g++
// visual C++ �����Ϸ��̸� : cl.exe 

// D:          => ����̺� �̵�
// cd ������    => ���� ������ �̵�

// cl CalcProxy.cpp /LD /link user32.lib  gdi32.lib kernel32.lib 

// => CalcProxy.dll �����Ǹ� �˴ϴ�.
// => "/LD" �� "DLL" �� ���� �ɼ��Դϴ�.

