#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>




// �پ��� ����� Stream Ŭ������ ������ �������� �����ϱ� ����
// �������̽��� ���� �մϴ�.
struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}
	
	// write �ܿ���, read(), is_open(), close(), flush() ��
	// �⺻ ����� �Լ��� ����� ���!!
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello world");


	// �پ��� ����� Stream Ŭ������ ������ ���ô�.
//	PipeStream ps("my_named_pipe");
//	ps.write("hello, world");


//	NetworkStream ns("100.100.200.200", 4000);
//	ns.write("hello, world");
}