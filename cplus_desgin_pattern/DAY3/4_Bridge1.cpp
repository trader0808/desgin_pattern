// 6_Bridge1 - 90 page
#include <iostream>

// 다양한 MP3 제품의 규칙을 담은 인터페이스
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
	// => 구체(concrete) 에 의존하지 말고, 인터페이스에 의존해라!!
	// => 인터페이스를 사용하면 확장성 있는 디자인이 된다는 의미!

//	void Use(IPod* p) // 한가지 제품만 사용가능
	void Use(IMP3* p) // 다양한 MP3 제품 사용가능
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


