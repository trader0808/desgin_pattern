#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class FileStream
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
		printf("%s ����\n", s.c_str() );
	}
};

int main()
{
	// C ���� �ڿ��� ���� �����ؾ� �ϹǷ� �����ϰ�, �����մϴ�.
//	FILE* f = fopen("a.txt", "wt");
//	if (��� �߻�) return 0;
//	fclose(f);


	// C++�� �����ڿ� �Ҹ��ڷ� �ڿ������� �ϰ� �ǹǷ� ���ϰ�, �����մϴ�.
	FileStream f("a.txt");

	f.write("hello world");

	// f�� �Ҹ��ڰ� ������ �����ϰ� �ݾ� �ݴϴ�.
}