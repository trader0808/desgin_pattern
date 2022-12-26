#include <iostream>
#include <vector>
#include <string>

// main �Լ��� �������� �ʵ��� File/Folder �ϼ��� ������
// ������ ���Ŭ������ "Item" ���� �ϼ���.

class Item
{
	std::string name;
public:
	Item(const std::string& name) 
		: name(name) {}

	virtual ~Item() {}

	// ����/���� ��� ũ��� ���Ҽ� �ִ�
	virtual int get_size() = 0;
};

class File : public Item 
{
	int size;
public:
	File(const std::string& name, int size)
		: Item(name), size(size) {}

	virtual int get_size() override { return size; }
};

class Folder : public Item
{
	std::vector<Item*> v; // �ٽ�
public:
	Folder(const std::string& name) 
		: Item(name) {}

	void add_item(Item* p) { v.push_back(p); }

	virtual int get_size() override
	{
		int size = 0;
		for (auto p : v)
			size += p->get_size();

		return size;
	}
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->add_item(fo1);
	root->add_item(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->add_item(f1);
	root->add_item(f2);

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->get_size() << std::endl; // 20
	std::cout << fo1->get_size() << std::endl; // 10
	std::cout << root->get_size() << std::endl; // 30
}


// ��ü���� ���α׷����� "���α׷��̶� ?"

// 1. ��ü�� �����ϰ�
// 2. ��ü���� ���踦 �����ϰ�
// 3. ��ü���� �޼����� �ְ� �޴� �����̴�(��� �Լ��� ȣ���Ѵٴ� �ǹ�)

// 4. ���α׷��� �⺻ ������ "�Լ�" �� �ƴ� "Ŭ����" �̴�.

// Composite ����
// => ��ü�� ���� ���踦 ��Ÿ���� ����

// => ���հ�ü(PopupMenu, Folder)�� ������ü(MenuItem, File) �� �ƴ϶� 
//    ���հ�ü �ڽŵ� �����Ѵ�.
//		=> ���հ�ü�� ������ü�� ������ ��� Ŭ������ �ʿ� �ϴ�.


// => ���հ�ü�� ������ü�� ������ �����ϴ�.(command(), get_size())
//		=> ���Ͻ� �ϴ� �Լ��� "��� Ŭ����"�� �־�� �Ѵ�.


// => ��ü�� ���� ���谡 "tree ����"�� ���� �Ǵ� ����










