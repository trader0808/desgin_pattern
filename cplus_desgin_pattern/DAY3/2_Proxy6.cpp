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
	ICalc* pcalc = ReloadProxy(); // �ᱹ DLL ���ο��� "new Calc" �մϴ�.

	int n = pcalc->Add(1, 2);


	delete pcalc; // �̷��� �ص� �ɱ�� ?? �����Ѱ��� ??
				// => �������� �ʽ��ϴ�..
				// 
				// DLL ���ο��� �Ҵ��� �޸𸮴�
				// DLL ���ο��� delete �ϴ� ���� ���� �����մϴ�.

}





