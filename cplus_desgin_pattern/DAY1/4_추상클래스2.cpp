//1_�߻�Ŭ����2.cpp
#include <iostream>

// OCP
// ��� Ȯ�忡�� ���� �ְ�(Open, Ŭ������ ���߿� �߰��Ǿ)
// �ڵ� �������� ���� �־��(Close, ���� �ڵ�� �������� �ʵ���)
// ������ �϶�� ��Ģ

// Open Close Principle( ���� ����� ��Ģ )

// ��ü ���� S/W ������ 5�� ��Ģ : SRP, OCP, LSP, ISP, IDP ( SOLID )


class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};


class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);
}





