#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map< std::string, std::vector<HANDLER> > notif_map;
public:

	void add_observer(const std::string& key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}

	void post_notification_with_name(const std::string& key, void* hint)
	{
		for (auto h : notif_map[key])  // notif_map[key] �� �ᱹ vector
		{
			h(hint);
		}
	}

};



void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	// IOS ���߿� ���Ǵ� "cocoa" ���̺귯������ �뺸���Ͱ� �ֽ��ϴ�.
	NotificationCenter nc;

	nc.add_observer("LOWBATTERY", &foo);
	nc.add_observer("LOWBATTERY", std::bind(&goo, _1, 0) );

	// ���͸� ����ʿ��� ���͸��� ����������
	nc.post_notification_with_name("LOWBATTERY", (void*)30);


	// ���� ���� : poco ��� C++ ��Ʈ��ũ ���¼ҽ� �� �Ʒ� ���� ����� �ֽ��ϴ�.
	// 
	// 1. �켱���� �ο��� ������
	/*
	nc.add_observer("DISCONNECT_WIFI", &f1, PRIORITY_1);
	nc.add_observer("DISCONNECT_WIFI", &f2, PRIORITY_3);
	nc.add_observer("DISCONNECT_WIFI", &f3, PRIORITY_2);

	// 2. ��Ƽ ������ ������ ������
	nc.add_observer("DISCONNECT_WIFI", &f4, PRIORITY_1, NEW_THREAD);
	nc.add_observer("DISCONNECT_WIFI", &f5, PRIORITY_2);
	*/
}




