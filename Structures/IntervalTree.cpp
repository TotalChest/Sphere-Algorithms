#include <vector>
#include <iostream>
// Дерево отрезков
// Тип элемтов - T, Функция - FUNC (Задается ляьбда выражением)

template<typename T, typename FUNC>
class IntervalTree
{
	std::vector<T> body; // Бинарная куча
	T neutral; // Нейтральный элемент
	unsigned int C; // Позиция в body, с которой начинается вставка элементов массивeа

	T private_func(unsigned int l, unsigned int r)
	{
		T Res = neutral;
		if (l & 1u) Res = FUNC()(Res, body[l++]);
		if (!(r & 1u)) Res = FUNC()(Res, body[r--]);
		if (r > l) Res = FUNC()(Res, private_func(l/2,r/2));
		return Res;
	}

public:

	IntervalTree(size_t size, T neutral): neutral(neutral)
	{
		unsigned int count = 0;
		body.resize(4 * size, neutral);
		C = 0;
		while(size)
		{
			count += size & 1;
			size >>= 1u;
			++C;
		}
		C = 1u << (count == 1 ? C-1 : C);
	}

	void insert(unsigned int i, T val)
	{
		body[C + i] = val;
		propagate(i);
	}

	void propagate(unsigned int index)
	{
		index = index + C;
		while(index > 1)
		{
			unsigned int neighbor_index;
			if(index & 1)
				neighbor_index = index - 1;
			else
				neighbor_index = index + 1;
			T parent = FUNC()(body[index], body[neighbor_index]);
			body[index/2] = parent;
			index /= 2;
		}
	}

	T func(unsigned int l, unsigned int r)
	{
		return private_func(l + C, r + C);
	}

	void print()
	{
		for(auto out: body)
			std::cout << out << std::endl;
	}
};

struct functor_max_int
{
public:
	int operator()(int x, int y)
	{
		return std::max(x, y);
	}
};

int main()
{
	IntervalTree<int, functor_max_int> it(10, -10000);
	for(int i = 0; i < 10; ++i)
	{
		it.insert(i, i);
	}
	std::cout << it.func(2,7) << std::endl;
}
	