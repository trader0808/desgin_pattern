#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"



template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

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

#include <memory>	// C++ ǥ�� ����Ʈ ������(shared_ptr)�� ���ؼ�..
/*
template<typename T> class shared_ptr
{
	T* obj;
public:
	~shared_ptr() { delete obj; }
};
*/

int main()
{
	{
		std::shared_ptr<int> p1(new int); // �������Ͽ��� new �߽��ϴ�.

	}	// <= �̼��� p1�� �Ҹ��ڿ��� delete �մϴ�.
		//    �������Ͽ��� new �� ���� �������� �ʿ��� delete �ϰ� �˴ϴ�.


	{
		std::shared_ptr<ICalc> p2(ReloadProxy() );
						// => �̹� ����Ǿ� �ִ� DLL ������ Create()ȣ��
						// => "new" �� ���� �ڵ尡 ����Ǿ �޸� �Ҵ�
						// => �׷���, new �� ���� �ڵ����� �����Ϸ����� �ٸ�������
	}	//<= p2 �Ҹ��� delete !!
		//   �׷���, ���� ���������� delete ����� DLL ������ new �����
		//   ȣȯ ���� ������ ����(�����Ϸ��� �ٸ���)

	{
		AutoPtr<ICalc> p3(ReloadProxy()); 

	}	// <== p3�� �Ҹ��ڰ� "delete" �ϴ°� �ƴ�...
		// <== DLL ������ Release() �� ȣ��..
		//     ���� delete �� DLL ���ο���
		//     new, delete �� ��� DLL ���ο��� �ϹǷ� ����

}





