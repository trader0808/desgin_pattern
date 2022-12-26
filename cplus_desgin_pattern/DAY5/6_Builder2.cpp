// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

// �౸ ���ӿ��� � ���� �����ص�, ĳ���Ͷ�� ������ ��ü�� �����
// "������ ����"�մϴ�. ������ �� "����"�� ����� �ٸ��ϴ�.

struct IBuilder
{
	virtual void makeHat() = 0;
	virtual void makeUniform() = 0;
	virtual void makeShoes() = 0;
	virtual Character getResult() = 0;

	virtual ~IBuilder() {}
};

// ĳ���͸� ����� Ŭ����
class Director
{
	IBuilder* builder = nullptr;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	Character construct()
	{		
		// ĳ���͸� ����� ������ "����" �մϴ�.
		builder->makeHat();
		builder->makeUniform();
		builder->makeShoes();

		return builder->getResult();
	}
};

// ������ ĳ���� ����
class Korean : public IBuilder
{
	Character c;
public:
	virtual void makeHat() override     { c += Hat("��\n"); }
	virtual void makeUniform() override { c += Uniform("�Ѻ�\n"); }
	virtual void makeShoes() override   { c += Hat("¤��\n"); }
	virtual Character getResult() override { return c; }
};

class American : public IBuilder
{
	Character c;
public:
	virtual void makeHat() override { c += Hat("�߱�����\n"); }
	virtual void makeUniform() override { c += Uniform("�纹\n"); }
	virtual void makeShoes() override { c += Hat("����\n"); }
	virtual Character getResult() override { return c; }
};

int main()
{
	American a;
	Korean k;

	Director d;
//	d.setBuilder(&k);  // <== ���� ���� �����, ������ ����!!!
	d.setBuilder(&a);

	Character c = d.construct();
	std::cout << c << std::endl;

}