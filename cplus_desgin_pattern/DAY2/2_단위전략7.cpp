#include <iostream>
#include <vector>

// STL �����̳ʰ� ����Ҽ� �ִ� ����� ���� �޸� �Ҵ�� �����
// => 1. allocate/deallocate �� �ݵ�� ������ �մϴ�.
// => 2. �߰��� 3���� ����� �� �ʿ� �մϴ�.(�������� �ڵ��..)
template<typename T> 
class log_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);
		
		printf("allocate : %d cnt, %p\n", sz, p);

		return static_cast<T*>(p);
	}

	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate : %d cnt, %p\n", sz, p);
		free(p);
	}

	// ���������� �Ʒ� 3���� �ʿ� �մϴ�.
	log_alloc() {}
	typedef T value_type;

	template<typename U> log_alloc(const log_alloc<U>&) {}
};
int main()
{
	std::vector<int, log_alloc<int> > v;

	std::cout << "=================" << std::endl;

	v.resize(5);
	std::cout << "=================" << std::endl;

	v.resize(10);
	std::cout << "=================" << std::endl;
}

