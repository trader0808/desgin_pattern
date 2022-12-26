// 6_Bridge1 - 90 page
#include <iostream>

// �پ��� MP3 ��ǰ�� ��Ģ�� ���� �������̽�
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void Play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
	// DIP ( Dependency Inversion Principle )
	// => ��ü(concrete) �� �������� ����, �������̽��� �����ض�!!
	// => �������̽��� ����ϸ� Ȯ�强 �ִ� �������� �ȴٴ� �ǹ�!

//	void Use(IPod* p) // �Ѱ��� ��ǰ�� ��밡��
	void Use(IMP3* p) // �پ��� MP3 ��ǰ ��밡��
	{
		p->Play();
		p->Stop();
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


