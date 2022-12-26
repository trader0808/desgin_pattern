#include <iostream>

// ��� 3. ���ϴ� ���� �ٸ� Ŭ������!!!
// => ��, �������̽� ��� ��ü�� �ƴ϶� template ���ڷ� ��ü

// Ŭ������ ����ϴ� Ư����å(����ȭ, Validation��)�� ���� ��å Ŭ������ 
// ��ü�ϴ� 2���� ���

//									����ð���ü����		����
// 1. �������̽��� �����ؼ� ��ü		O					�����Լ���� ������
// 2. ���ø� ���ڷ� ��ü				X					�ζ���ġȯ����.������.


// �������̽� ��� ��ü : strategy ����.  ������ ���� 23���� ���Ե� ���
// 
// ���ø� ���ڷ� ��ü  : policy base(��������)������
//						C++ ����� ���� ���..
//						������ ���� 23������ ���� �ȵ�.

// ����!! STL �� list �� �Ʒ�ó�� �Ǿ� ������ �ʽ��ϴ�.
// => STL list �� ����ȭ �ȵ˴ϴ�.
// => ���, STL �� �ٸ� �뵵�� "��������"�� ���� ����մϴ�.

// �Ʒ� �ڵ�� "webkit" �̶�� �������� ���� ���� ����ϰ� �ִ� ����Դϴ�.

template<typename T, typename ThreadModel = NoLock > class List
{
	ThreadModel locker;

public:
	void push_front(const T& a)
	{
		locker.lock();

		//...... 

		locker.unlock();
	}
};

// ���� List �� ������ �پ��� ����ȭ Ŭ������ �����մϴ�.
class NoLock
{
public:
	inline void lock() {}
	inline void unlock() {}
};

class PthreadLocker
{
	// pthread_mutex_t mt;
public:
	inline void lock()   { std::cout << "mutex lock" << std::endl; }
	inline void unlock() { std::cout << "mutex unlock" << std::endl; }
};
//-------------------------------------------------
List<int, NoLock> st; 

List<int, PthreadLocker> st2;


int main()
{
	st.push_front(10);
}




