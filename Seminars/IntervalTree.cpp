// Функтор Functor

tamplate<typename T, typename T1>
class IntervalTree
{
public:
	IntervalTree(size_t size, T neutral): neutral(neutral)
	{
		body.resize(4 * size, neutral);
	}
private:
	vector<T> body;
	T neutral;

	//res = T1()(res, body[l]); // Так быстрее, чем указатель на функцию (Подставляется в момент компиляции)
};


struct functor_add_int
{
public:
	int operator()(int x, int y){
		return x + y;
	}
};

int main()
{
	IntervalTree<int, functor_add_int> it(100, 0); // Способ 1
	IntervalTree<int , [](int x, int y) -> int { return x + y; }> it(100,0); // Способ 2
}