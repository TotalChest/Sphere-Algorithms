#include <iostream>

class Set
{
		using T = unsigned char;
		T * body;
		size_t max_elem;
	public:
		Set(size_t max) : max_elem(max)
		{
			body = new T[(max + 7) / 8];
			for(int i = 0; i < (max + 7) / 8; i++)
				body[i]=0;
		}
		
		~Set()
		{
			delete[] body;
		}
		
		bool insert(size_t elem)
		{
			if (elem > max_elem)
				return false;
			body[elem >> 3] |= (1 << (elem & 7));
			return true;
		}
		
		bool erase(size_t elem)
		{
			if (elem > max_elem)
				return false;
			body[elem >> 3] &= ~(1 << (elem & 7));
			return true;
		}
		
		bool in(size_t elem)
		{
			if (elem > max_elem)
				return false;
			return (bool)(body[elem >> 3] & (1 << (elem & 7)));
		}
		
		int size()
		{
			int count = 0;
			for(int i = 0; i < (max_elem + 7) / 8; i++)
				for(int j = 0; j< 8; j++)
					count += (body[i] >> j) & 1;

			return count;
		}	
		
};

int main(void)
{
	Set my_set(80);
	my_set.insert(20);
	my_set.insert(75);
	my_set.insert(18);
	my_set.insert(7);

	my_set.erase(20);

	std::cout << my_set.in(7) << my_set.in(40) << my_set.in(20) << std::endl;
	std::cout << my_set.size() << std::endl;
	return 0;
}
