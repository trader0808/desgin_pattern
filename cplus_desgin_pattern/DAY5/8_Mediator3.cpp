#include <iostream>
#include <conio.h>
using namespace std;

// �������� �������̽�
struct IMediator
{
	virtual void ChangeState() = 0;
	virtual ~IMediator() {}
};

class CheckBox
{
	bool state;

	IMediator* pMediator; // ��� ������(Colleague)�� �����ڸ� �˾ƾ� �մϴ�.
public:
	void SetMediator( IMediator* p ) { pMediator = p; }

	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState();
							pMediator->ChangeState(); }

	bool GetCheck()       { return state; }
	virtual void ChangeState() {}
};

class RadioBox
{
	bool state;

	IMediator* pMediator; // ��� ������(Colleague)�� �����ڸ� �˾ƾ� �մϴ�.
public:
	void SetMediator( IMediator* p ) { pMediator = p; }

	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState();
							pMediator->ChangeState(); }

	bool GetCheck()       { return state; }
	virtual void ChangeState() {}
};

// ������ Ŭ����
// �����ڴ� ��� ������(Collegue, ��� ��Ʈ��)�� �˰� �վ�� �մϴ�.
class LogInMediator : public IMediator
{
	CheckBox* c1;
	CheckBox* c2;
	RadioBox* r1;
	RadioBox* r2;
public:
	LogInMediator( CheckBox* a, CheckBox* b, RadioBox* c, RadioBox* d)
		: c1(a), c2(b), r1(c), r2(d)
	{
		c1->SetMediator(this);
		c2->SetMediator(this);
		r1->SetMediator(this);
		r2->SetMediator(this);
	}
	void ChangeState()
	{
		// ���� ��� �������� ���輳���� �̰��� ���ߵ˴ϴ�.
		if ( c1->GetCheck() && c2->GetCheck() &&
			 r1->GetCheck() && r2->GetCheck())
		{
			 cout <<"��ư Enable" << endl;
		}
		else
			cout << "��ư disable" << endl;
	}
};


int main()
{
	CheckBox c1, c2;
	RadioBox r1, r2;

	// Log In Dialog ���� �ִ� ��� ��Ʈ����
	// ���°� ����Ǹ� "������ m" �� �˷��޶�� ��
	LogInMediator m(&c1, &c2, &r1, &r2);
	_getch(); c1.SetCheck(true);
	_getch(); c2.SetCheck(true);
	_getch(); r1.SetCheck(true);
	_getch(); r2.SetCheck(true);
	_getch(); c1.SetCheck(false);
}









