template<typename T> class List
{
	// �پ��� ��� ����Ÿ��..
public:
	void push_front(const T& a)
	{
		// mutex lock
		//...... list �� ���ʿ� �߰��ϴ� �ڵ�
		// mutex unlock
	}
};
List<int> st; // ���������� ��Ƽ�����忡 �������� �ʽ��ϴ�.

int main()
{
	// mutex lock
	st.push_front(10);
	// mutex unlock
}




