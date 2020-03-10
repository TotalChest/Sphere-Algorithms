#include <iostream>
#include <vector>
#include <cassert>


struct tree
{
	enum {CHILDREN = 4};
	tree *c[CHILDREN] {};
	bool end = false; // Только новый с++
};


tree* build_tree(std::vector<std::string> const & pat)
{
	tree *root = new tree;

	for(auto const & str: pat)
	{
		auto curr = root;

		for(auto c: str)
		{
			assert(c >= 'a' && c < 'a' + tree::CHILDREN); //Проверка на корректность символов

			if (curr->c[c - 'a'] == nullptr)
				curr->c[c - 'a'] = new tree;

			curr = curr->c[c - 'a'];
			assert (!curr->end); // Проверка на префиксность
		}

		//Прокерка: Если есть дети - ошибка префиксности
		for (int i = 0; i < tree::CHILDREN; ++i)
			assert(!curr->c[i]);

		curr->end = true;

	}

	return root;
}


bool check(const tree * root, const std::string & s)
{
	auto curr = root;

	for(auto c: s)
	{
		if(c < 'a' || c >= 'a' + tree::CHILDREN || curr->c[c - 'a'] == nullptr) //Последние проверится, толлько если первые два false
			return false;

		curr = curr->c[c - 'a'];

		if(curr->end) 
			curr = root;
	}

	return curr == root;

}


int main()
{
	std::string str;
	std::vector<std::string> pat(4);
	
	pat[0] = "abc";
	pat[1] = "cbba";
	pat[2] = "b";
	pat[3] = "ac";

	tree *node = build_tree(pat);

	std::cin >> str;

	std::cout << check(node, str);

	return 0;
}