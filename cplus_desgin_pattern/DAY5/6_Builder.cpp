// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

// ĳ���͸� ����� Ŭ����
class Director
{
public:
	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		Character c;
		c = c + Hat("�߱�����");
		c = c + Uniform("�Ķ���Ƽ����");
		c = c + Shoes("�ȭ");
		return c;
	}
};
int main()
{
	Director d;
	Character c = d.construct();
	std::cout << c << std::endl;

}