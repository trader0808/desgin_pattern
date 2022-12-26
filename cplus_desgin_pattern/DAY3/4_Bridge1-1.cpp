#include <iostream>

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

// ������ ���� ������(IMP3, IPod��)
// ���� Ŭ���̾�Ʈ�� ����ϴ� Ŭ����(MP3, Brdge)�� �и��ؼ�
// ��ȣ �������� update �� �����ϰ� �Ѵ�.

class MP3
{
	IMP3* engine;
public:
	MP3(IMP3* p = nullptr) : engine(p)
	{
		if (engine == nullptr)
			engine = new IPod;
	}
	
	// ���� ����� ������ ���������� �����մϴ�.
	void Play() { engine->Play(); }
	void Stop() { engine->Stop(); }

	void PlayOneMinute()
	{
		Play();
		// 1�� �ִٰ�
		Stop();
	}
};
//==================================
// ���� ����ڴ� "MP3" �� ����ؾ� �մϴ�.
class People
{
public:
	void Use(MP3* p) 
	{
		p->Play();
		p->Stop();

		// �׷���, ����ڰ� �䱸������ ���� ����ȴ�.
		// "1�й̸����" ����� �䱸 �Ѵ�.
	}
};





int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


