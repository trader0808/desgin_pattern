// protected �������� �ǵ� : �ڽ��� ��ü�� ����� ������(�߻����� ����)
//						�Ļ� Ŭ������ ��ü�� ����� �ֵ���(��ü���� ����)
//						�ϰڴٴ� �ǵ��� ���� �ڵ�

// ��ü(concrete) : ������ ���Ͽ��� �߻�(abstract)�� �ݴ븻�� ���˴ϴ�.

class Animal
{
//public:
//private:
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}
};
int main()
{
	// ������ ������ ��� ��� ������
	Animal a;	// error
	Dog    d;	// ok
}



