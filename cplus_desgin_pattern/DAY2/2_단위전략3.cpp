#include <iostream>

// ��� 2. ���ϴ� ���� �ٸ� Ŭ������!!
// ���� : ����ȭ ��å(PthreadLocker)�� �ٸ� Ŭ����(vector, stack, queue��)
//       ������ ��밡���ϴ�.

// ���� : ����ȭ ��å�� ���� lock/unlock �� �����Լ� �̴�. ������
//		  ���� ���� �ٸ� ����� ������ ??? 




// ����ȭ ��å�� ��ü �����ؾ� �ϹǷ� �������̽� ����
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};

template<typename T> class List
{
	ISync* psync = nullptr;
public:
	void set_sync_object(ISync* p) { psync = p; }

	void push_front(const T& a)
	{
		if (psync)
			psync->lock();
		//...... 
		if (psync)
			psync->unlock();

	}
};

// ���� �پ��� ȯ�濡 �´� �پ��� ����ȭ ��å�� �����ϸ� �˴ϴ�.
class PthreadLocker : public ISync
{
	// pthread_mutex_t mt;
public:
	virtual void lock()   { std::cout << "mutex lock" << std::endl; };
	virtual void unlock() { std::cout << "mutex unlock" << std::endl; };
};
List<int> st; 

int main()
{
	PthreadLocker locker;
	st.set_sync_object(&locker);

	st.push_front(10);
}





