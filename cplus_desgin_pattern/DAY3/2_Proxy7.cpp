#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");

	printf("Create�Լ��ּ� : %p\n", f);
	return f();
}

int main()
{
	ICalc* pcalc = ReloadProxy(); 

	pcalc->AddRef(); // ��Ģ 1. Proxy �����͸� ������ ������� ����

	ICalc* p2 = pcalc;
	p2->AddRef();	 // ��Ģ 2. Proxy ������ �����ϸ� ������� ����

	int n = pcalc->Add(1, 2);


	// ��Ģ 3. �� �����͸� ����Ŀ��� ������� ����
	p2->Release();

	std::cout << "========" << std::endl;
	pcalc->Release();	// �̼��� ������� "0" �ǹǷ� �ı�!

}





