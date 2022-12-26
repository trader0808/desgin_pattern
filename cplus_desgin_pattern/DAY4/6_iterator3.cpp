#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

//=============================================
// �ٽ� 1. ��� �ݺ��ڴ� ������ �����ؾ� �Ѵ�. - �ݺ����� �������̽� �ʿ�
// => �Ʒ� �̸����� C#�� �ݺ���, "�ٴ�" �� �ݺ��ڿ� �����ϴ�.
template<typename T> struct IEnumerator
{
	virtual T& GetObject() = 0;
	virtual bool MoveNext() = 0;
	virtual ~IEnumerator() {}
};

// �ٽ� 2. ��� �����̳ʴ� ���� ������� �ݺ��ڸ� ������ �־�� �Ѵ�.
// => �����̳��� �������̽�
template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};

//=======================================
// slist �� �ݺ��ڸ� ����� ���ô�.
template<typename T>
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current;
public:
	slist_enumerator(Node<T>* p = nullptr) : current(p) {}

	virtual T& GetObject() override { return current->data; }

	virtual bool MoveNext() override
	{
		current = current->next;
		return current;
	}

};

//slist_enumerator<int> p1(300����);
//int n = p1.GetObject();
//p1.MoveNext();







// ��� �����̳ʴ� ��ӵ� ������� �ݺ��ڸ� ������ �־�� �մϴ�.
template<typename T> 
struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	virtual IEnumerator<T>* GetEnumerator()
	{
		return new slist_enumerator<T>(head);
	}
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	//==========================
	IEnumerator<int>* p1 = s.GetEnumerator();

	do
	{
		std::cout << p1->GetObject() << std::endl;
	} while (p1->MoveNext());
}


// �� �ڵ尡 �������� ��ü���� �����ο����� "�ݺ���" �Դϴ�.
// => C#, java, swift, python ���� ��� �� �ڵ�� ���� �մϴ�.
// => "�ٴ�(C++)"�� �ݺ��ڵ� ���� ���� ����

// ���� 1. s.GetEnumerator() �� ��ȯ�ϴ� �ݺ��ڴ� "new"�� �����ߴ�.
//         => ����Ŀ��� �ݵ�� delete �Ǿ�� �Ѵ�.
//		   => �Ǵ�, ����Ʈ ������ ���

// ���� 2. GetObject()/MoveNext() �� �����Լ� �Դϴ�.
//		   => �����Լ� ȣ���� ������尡 �ֽ��ϴ�.(�����ϴ�.)

// ���� 3. raw array �� �����̳� �Դϴ�.
//        raw array �� ���� ����� �ٸ��ϴ�.
//        => raw array �� �����͸� ����ؼ� ++p �� �̵��ϰ�, *p �� �������





