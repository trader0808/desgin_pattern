// ���� - ���� ������ ������ ���� �ϼ���

// ���� ���� 5�� : 
// => singleton, builder, abstract factory, factory method, prototype


// ���� ���� 7�� :
// => ����� ������ ����ϴ� 2����  ����    : composite, decorator
// => �������� ����ؼ� ������ �ذ��ϴ� ���� : adapter, bridge, facade, proxy
// => �Ӽ��� �����ϸ� ����                 : flyweight


// ���� ���� 11�� : 
// => ���ϴ� ���� �и� : template method, strategy, state
// => undo/redo       : command
// => ��ü�� ����/���� : memento
// => ����, �湮       : iterator, visitor
// => 1:N ����, 1�� ��ȭ�� N�� �뺸 : observer

// => ��û�� ���� ���� ����            : chain of responsibility
// => M:N �� ������ ���踦 1:N ���� ���� : mediator
// 
// => �����Ϸ� ���鶧 ����ϴ� ����(������ ������) : interpret

//=========================================================
// SOLID
// SRP : Single Responsibility Principle
// => �ϳ��� Ŭ������ �ϳ��� å�Ӹ�

// OCP : Open Close Principle

// LSP : Liskov Substitution Principle
// => ��� Ŭ������ ���Ǵ� �ڸ����� �Ļ� Ŭ������ ������ �־�� �Ѵ�.
// => ��� Ŭ���� ����� �Ļ� Ŭ������ ���� ���� ����(�Ʒ�ó�� �������ؼ� ���� �߻�)
void foo(std::list<int>* p) {}

class MyList : public std::list<int>
{
public:
	void push_back(int n) { throw 1; }
};
MyList s;
foo(&s); // �ݵ�� �Ǿ�� �մϴ�.
//====================================
// ISP : Interface Segregation Principle
// => �������̽��� ��ü�� ���� �и��Ǵ� ���� ����.
// ���� �� ���� ���� ?
struct IStream					// 1��
{
	virtual void Read() = 0;
	virtual void Write() = 0;
};

// 2��
struct IReadStream	
{
	virtual void Read() = 0;
};
struct IWriteStream
{
	virtual void Read() = 0;
};



// DIP : Dependency Inversion Principle
// => ��ü�� �������� ����, �߻�(�������̽�)�� �����ض�

void useCamera(ICamera* p)  {} // good
void useCamera(HDCamera* p) {} // bad