
// STL �� ����
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;

	Alloc ax; // �޸� �Ҵ��
			  // ������ vector �� ��� ��� �Լ������� �޸� �Ҵ�/������ �ʿ��ϸ�
			  // �� �Ҵ�⸦ ����ؾ� �մϴ�.
public:
	void resize(int n)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 

		buff = ax.allocate(n); // ��Ģ 1. �޸� �Ҵ��� �ݵ��
								//       "allocate" �� �ʿ� �մϴ�.
		ax.deallocate(buff, n); // ��Ģ 2. "deallocate" �� �־�� �մϴ�.
	}
};
// cppreference.com �� �����ؼ�.. ������ �� �˻�â�� "std::vector" �˻��� ������





