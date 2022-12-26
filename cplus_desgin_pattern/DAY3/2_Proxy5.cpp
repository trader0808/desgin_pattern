#define USING_GUI
#include "cppmaster.h"

// Proxy5.cpp

// Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// ICalc.h       : �������̽��� ��� ���
// CalcProxy.dll : Proxy ������ ��� ���� ���

#include "ICalc.h"

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
						// => linux : dlopen()
						// => window: LoadLibrary()
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");
						// => linux : dlsym()
						// => Window: GetProcAddress()
	printf("Create�Լ��ּ� : %p\n", f); 
	return f(); // �ᱹ "Create()"  ȣ��
}

int main()
{
	ICalc* pcalc = ReloadProxy();

	std::cout << pcalc->Add(10, 20) << std::endl;
	std::cout << pcalc->Sub(10, 20) << std::endl;
}





