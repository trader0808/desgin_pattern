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
		printf("%s 쓰기\n", s.c_str());
	}
};

// 실제 입출력을 담당하는 클래스 : FileStream, PipeStream, NetworkStream

// 이제 입출력 Stream 객체에 기능을 추가하는 다양한 Decorator를 제공합니다.

class ZipDecorator : public Stream
{
	Stream* stream; // 핵심 : 실제 입출력 객체를 가리킬 포인터
					//       포함을 사용한 기능의 추가!!!
public:
	ZipDecorator(Stream* s) : stream(s) {}

	virtual void write(const std::string& s) override
	{
		std::string data = s + " 압축됨";

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
		std::string data = s + " 암호화됨";

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




