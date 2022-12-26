#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// AddRef/Release 호출을 자동으로 해주는 스마트포인터 도입
template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr)    : obj(p)      { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	// 스마트포인터의 핵심 : -> 와 * 를 연산자 재정의 해서
	//						객체지만 포인터 처럼 사용가능하게
	T* operator->() { return obj; }
	T& operator*() { return *obj; }


};
















ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");

	printf("Create함수주소 : %p\n", f);
	return f();
}

int main()
{
	AutoPtr<ICalc> p1 = ReloadProxy();
	AutoPtr<ICalc> p2 = p1;

	int n = p1->Add(1, 2);

}





