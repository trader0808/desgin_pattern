// 8_�޸��� - 178
#include <iostream>


// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.

	// ��� 1. DrawLine �Լ� ���ڷ� ���� �Ӽ� ����
	// => windows API gdi+ ���
	g.DrawLine(0, 0, 100, 100, red, dash, 10);
	g.DrawLine(0, 0, 200, 200, blue, dash_dot, 20);

	// ��� 2. Graphics ��ü�� �Ӽ��� �����ϴ� ���
	// => IOS �� cocoa ���̺귯�� ���
	g.SetStrokeColor(red);
	g.SetStrokeStyle(dash);
	g.SetStrokeWidth(10);

	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200);
}









