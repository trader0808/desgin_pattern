#include <iostream>
#include <mutex>

// lock/unlock �� �����ϰ� �Ǹ� 
// "deadlock" �� ���ɼ��� �ֽ��ϴ�.

// �׻� �ڿ��� ������ ������/�Ҹ��ڸ� ����ؼ� �����ؾ� �մϴ�.
// "RAII" ��� �̸��� ���� ��� ( C++ �������� ���, C++ IDioms)
// => "Resource Acquision Is Initialization"
// => �ڿ��� ȹ��(mtx.lock) �ϰ� �Ǵ� ���� (�ڿ� ������ü��) �ʱ�ȭ �ɶ� �̴�.

// => ���ۿ��� "C++IDioms" ��� �˻� �غ�����.. 1��° ��ũ.. 

// ������ ���� : �� ������ ��ü���� ������ ���
// IDioms     : �� Ư¡�� ����� �ڵ� ��ũ���� ��Ī�ϴ� ���
//				(C++ IDioms, Java Idioms ��)


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};



class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* pinstance;
	static std::mutex mtx;
public:

	static Cursor& getInstance()
	{
		std::lock_guard<std::mutex> g(mtx); // C++11 ǥ�ؿ� �̹� lock_guard�� 
											// �ֽ��ϴ�.

	//	lock_guard<std::mutex> g(mtx); // �����ڿ��� "mtx.lock()" ����
										// �Ҹ��ڿ��� "mtx.unlock()"
										// �ٽ� : �Ʒ� �ڵ忡�� ���ܰ� �߻��ص�
										//	      catch �� �̵��ϱ� ����
										//	      g�� �Ҹ��ڴ� ȣ����� ����
										//	      ����Ǯ��(stack unwinding)
//		mtx.lock();

		if (pinstance == nullptr)
			pinstance = new Cursor;
		
//		mtx.unlock();

		return *pinstance;
	}
};
std::mutex Cursor::mtx;
Cursor* Cursor::pinstance = nullptr;







int main()
{
	Cursor& c1 = Cursor::getInstance();
}









