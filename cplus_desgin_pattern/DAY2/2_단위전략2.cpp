#include <iostream>
// list �� �տ� �ִ� �ڵ�� ������ ������
// ����ȭ ���δ� ���Ҽ� �־�� �Ѵ�.
// 
// ��� 1. ���ϴ� ���� �����Լ���!! - template method

// Ư¡(����) : ����ȭ ���� �ڵ带 ThreadSafeList �� �����ϰ� �ִ�.
//             vector, stack, queue � �����ϰ� ������ �ϸ�
//				����ȭ ���� �ڵ��� �ߺ��� �߻��Ѵ�!


template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		lock();
		//...... 
		unlock();
	}
	virtual void lock() {}
	virtual void unlock() {}
};

// List �� ����ȭ ��å�� �����Ϸ��� �Ļ� Ŭ������ ����
// lock/unlock �� ������ �Ѵ�.!
template<typename T> class ThreadSafeList : public List<T>
{
	// pthread_mutex_t mtx;
public:
	virtual void lock() override
	{
		std::cout << "mutex lock" << std::endl;
	}
	virtual void unlock() override
	{
		std::cout << "mutex unlock" << std::endl;
	}
};

//List<int> st; 
ThreadSafeList<int> st;

int main()
{
	st.push_front(10);
}




