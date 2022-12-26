#include <functional> 

class Dialog
{
public:
	void Close(int a) {}

	static void Close2(int a) {}
};
void foo(int a) {} 

int main()
{
	// �ٽ� 1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ������ ����.
	// �ٽ� 2. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ������ �ִ�.
	void(*f1)(int) = &foo;	// ok			
//	void(*f2)(int) = &Dialog::Close; // error. ��� �Լ��� this�� �߰��ȴ�.
	void(*f3)(int) = &Dialog::Close2; // ok.. 


	// �ٽ� 3. ��� �Լ��� �ּҸ� ��� "��� �Լ� ������" ����� ���
	void(Dialog::*f)(int) = &Dialog::Close;


	// �ٽ� 4. ��� �Լ� �����ͷ� ��� �Լ� ȣ���ϱ�
//	f(10); // error. f �� ��� �Լ��� ����Ű�Ƿ�, ��ü�� �־�� ȣ�Ⱑ���մϴ�.

	Dialog dlg;
//	dlg.f(10);	// error. Dialog ���� f ��� ����� ã�Ե˴ϴ�.
				// f��� ����� �����ϴ�.

	// "Pointer To Member" ��� ������(.*) �� ����ؾ� �մϴ�.
//	dlg.*f(10); // error. ������ �켱���� ����, 
				// .* ������ ���� ( �����ڰ� �켱������ �����ϴ�.


	(dlg.*f)(10);	// ok.. �� ǥ�����, ��� �Լ� �����͸� ������
					// ��� �Լ��� ȣ���ϴ� ǥ��� �Դϴ�
}






