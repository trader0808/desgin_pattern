#include <iostream>
#include <mutex>

// CRTP : Curiously Recurring Template Pattern
// => ��� Ŭ�������� �̷��� ������� �Ļ� Ŭ������ �̸��� ����Ҽ�
//    �ְ� �ϴ� ����
// => ��� Ŭ������ ���ø����� �����
//    �Ļ� Ŭ���� ���鶧 ��ӹ����鼭 �ڽ��� Ŭ���� �̸���
//    ��� Ŭ���� ���ø� ���ڷ� �����ϴ� ���

// class Mouse : public Singleton< Mouse >


template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* pinstance;    //<==== T
	static std::mutex mtx;
public:

	static T& getInstance()   //<==== T
	{
		std::lock_guard<std::mutex> g(mtx); 

		if (pinstance == nullptr)
			pinstance = new T;  // <==== T

		return *pinstance;
	}
};
template<typename T> std::mutex Singleton<T>::mtx;
template<typename T> T* Singleton<T>::pinstance = nullptr;


// Mouse �� ���� ����� �̱����� ����ϰ� �ʹ�.
class Mouse : public Singleton< Mouse  >
{
public:
};

int main()
{
	Mouse& c1 = Mouse::getInstance();
}









