#include <iostream>

// ���� ����(tightly coupling) vs ���� ����( loosely coupling )

// ���� ���� : �ϳ��� Ŭ������ �ٸ� Ŭ�������� Ŭ�����̸��� ���� ���
//			   ��ü �Ұ����� ������ ������

// ���� ���� : �ϳ��� Ŭ������ �ٸ� Ŭ�������� ��� Ŭ������ �߻� Ŭ���� �̸�
//			  (�������̽�) �� ����ؼ� ����.
//			  ��ü ������, Ȯ�强 �ִ�, ������ ������


//=====================================
// �߻� Ŭ���� vs �������̽� 

// ���� ���̽� : ���Ѿ� �ϴ� ��Ģ(���������Լ�) �� �ִ� ���
// �߻� Ŭ���� : ���Ѿ� �ϴ� ��Ģ(���������Լ�) + �ٸ� ����� �ִ� ���

// Java, C# : interface, abstract ��� ������ Ű���� ����
// C++ ������ Ű���� �����ϴ�. �׳�, ���� �����Լ� ������ �����մϴ�.

//==========================================


// ����̳� ī�޶� ���� ������ ����..
// ī�޶�� ī�޶� ����� ���̿� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.

// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ� �Ǿ�� �Ѵ�." ��� ��������
//        "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�" ��� ǥ�� �մϴ�.

// �������̽� ���鶧 "class" ���ٴ� "struct" �� �ϴ� ��찡 �����ϴ�.
// => ���������� �� ǥ������ �ʾƵ� public �̹Ƿ�
struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {}   // �������̽��� ���������δ� �ᱹ ��� Ŭ�����Դϴ�.
							// �Ҹ��ڴ� �ݵ�� �����Լ��̾�� �մϴ�
};			








// ���� ��Ģ�� �������Ƿ� ī�޶� ��� 
// ī�޶� ����ϴ� �ڵ带 ����� �ֽ��ϴ�.
// ��Ģ ��θ� ����ϸ� �˴ϴ�.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// ��� ī�޶�� ��Ģ�� ���Ѿ� �մϴ�.
class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);

	UHDCamera uhc;
	p.UseCamera(&uhc);

}





