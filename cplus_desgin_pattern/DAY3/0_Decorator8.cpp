#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}

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

// ���� ������� ����ϴ� Ŭ���� : FileStream, PipeStream, NetworkStream

// ���� ����� Stream ��ü�� ����� �߰��ϴ� �پ��� Decorator�� �����մϴ�.

class ZipDecorator : public Stream
{
	Stream* stream; // �ٽ� : ���� ����� ��ü�� ����ų ������
					//       ������ ����� ����� �߰�!!!
public:
	ZipDecorator(Stream* s) : stream(s) {}

	virtual void write(const std::string& s) override
	{
		std::string data = s + " �����";

		stream->write(data);
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream; 
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	virtual void write(const std::string& s) override
	{
		std::string data = s + " ��ȣȭ��";

		stream->write(data);
	}
};


int main()
{
	FileStream fs("a.txt");
	fs.write("hello world"); 

	EncryptDecorator ed(&fs);
	ed.write("hello world"); 
	

	ZipDecorator zd(&ed);
	zd.write("hello world"); 
	
}




