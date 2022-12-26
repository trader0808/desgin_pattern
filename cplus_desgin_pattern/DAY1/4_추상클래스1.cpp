// 1_�߻�Ŭ����1.cpp - 10page

// �߻� Ŭ���� : ���� �����Լ��� �Ѱ� �̻� �ִ� Ŭ����.
// Ư¡        : ��ü�� ����� ����, ��, ������ ������ ����
// �ǵ� : �Ļ� Ŭ������ Ư�� �Լ�(Draw) �� �ݵ�� ������ �Ѵٰ�
//       "����" �ϴ� ��

class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw() = 0; // ���� ���� �Լ�(pure virtual function)
							 // Ư¡ : �����ΰ� ����, "=0" ���� ǥ��
							 
};
class Rect : public Shape
{
	// �ٽ� : Draw�� �����θ� �������� ������ Rect�� �߻� Ŭ���� �̴�.
	//       Draw�� �����θ� �����ϸ� Rect�� �߻��� �ƴϴ�.
public:
	virtual void Draw() override {}
};
int main()
{
	Shape  s;  // error.
	Shape* p;  // ok. 
	Rect  r;   // ok. 
}
