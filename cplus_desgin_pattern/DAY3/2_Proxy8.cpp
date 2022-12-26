#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// AddRef/Release ȣ���� �ڵ����� ���ִ� ����Ʈ������ ����
template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr)    : obj(p)      { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	// ����Ʈ�������� �ٽ� : -> �� * �� ������ ������ �ؼ�
	//						��ü���� ������ ó�� ��밡���ϰ�
	T* operator->() { return obj; }
	T& operator*() { return *obj; }


};
















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
	AutoPtr<ICalc> p1 = ReloadProxy();
	AutoPtr<ICalc> p2 = p1;

	int n = p1->Add(1, 2);

}





