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

int main()
{


	// ���Ͽ� ���� ��ȣȭ �ؼ� ���� ����� �䱸�Ҷ�..
	// �ּ��� �������� ������ ���ô�.

	// ��� 1. �����͸� ���� ��ȣȭ �ϰ� write ����.
	// => ������ �ؾ� �Ѵٸ� �Ź� ��ȣȭ �ڵ带 �ۼ��ؾ� �ϹǷ� �����ϴ�.

	// ��� 2. FileStream �� �Ļ� Ŭ������ ���� encrypt_write()
	//		   ��� �Լ��� ��������.
	// => PipeStream, NetworkStream �� ��� Ŭ�������� ������ �۾����ؾ��մϴ�
	// => ��ȣȭ ����� ������,, �������� �ְ� �˴ϴ�.


	// ��� 3. ��� ��Ʈ�� Ŭ������ ��� Ŭ������ Stream �� �߰� ����.
	// => ��ȣȭ ����, �����ؼ� ���� ����� �ʿ��ϴٸ� 
	//    �� Stream �� �߰� ???  
	// => �䱸 ������ ���涧 ���� Stream ����. OCP �� �����Ҽ� ����!!

	// ��� 4. Decorator ������ �������..

	FileStream fs("a.txt");
	fs.write("hello world"); // ���Ͽ� ���� ����

	EncryptDecorator ed(&fs);
	ed.write("hello world"); // 1. ����Ÿ�� ��ȣȭ �ϴ� ��� ������
							 // 2. ���� ��� fs.write() ����

	ZipDecorator zd(&ed);
	zd.write("hello world"); // 1. ���� ��� ����
							 // 2. ed.write() ����
}