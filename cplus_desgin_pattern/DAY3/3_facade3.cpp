#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;




class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		WSACleanup();
	}
};

class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket �۾��� å������ Ŭ����
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};

// TCP ������ �������
// => ���̺귯�� ������ ��� Ŭ������ ����ؼ�
// => ��� ������ ���ľ� �˴ϴ�

// �̷� ������ �ϳ��� �Լ��� �����ϴ� ������ ������ �������̽��� �����մϴ�.
// => "Facade" ����

class TCPServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM }; 
public: 
	void Start(const char* sip, short port)
	{
		IPAddress addr(sip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	// ���̺귯���� ���� ����� �ڵ� �Դϴ�.
	TCPServer server;
	server.Start("127.0.0.1", 4000);



}