#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct tree
{
	int inf;
	tree *left;
	tree *right;
}*root;

tree *list(int info)
{
	tree *t = new tree;
	t->inf = info;
	t->left = t->right = NULL;
	return t;
}

void add_list(tree *root, int info)
{
	tree *prev, *t;
	bool find = true;
	t = root;
	while (t && find)
	{
		prev = t;
		if (info == t->inf)
		{
			find = false;
			cout << "Повторяющийся ключ\n";
		}
		else
		{
			if (info < t->inf) t = t->left; 
			else t = t->right;
		}
		if (find)
		{
			t = list(info);
			if (info < prev->inf) prev->left = t;
			else prev->right = t;
		}
	}
}

/*void view_tree(tree *root, int p)
{
	cout << '\t';
	cout << root->inf;
	if (root->left != nullptr)
		view_tree(root->left, p + 1);
	if (root->right != nullptr) 
	{
		cout << endl;
		for (int i = 0; i < p; i++)
			cout << '\t';
		view_tree(root->right, p + 1);
	}
}*/

void View_Tree(tree *p, int level)
{
	string str;
	if (p) 
	{
		View_Tree(p->right, level + 1);		// Правое поддерево
		for (int i = 0; i < level; i++) str = str + "    ";
		cout << str << p->inf << endl;
		View_Tree(p->left, level + 1); 			// Левое поддерево
	}
}


tree *dell_tree(tree *p)
{
	if (p == NULL) return NULL;
	dell_tree(p->left);
	dell_tree(p->right);
	delete(p);
	p = NULL;
	return NULL;
}
	
int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "\nЧто хотите сделать \n1 - Создать корень\n2 - Добавить элемент \n3 - Просмотреть \n4 - Выход \n";
		int kod; cin >> kod;
		switch (kod)
		{
		case 1:
		{
			cout << "Введите корень" << endl;
			int k; cin >> k;
			root = list(k);
		} break;
		case 2:
		{
			cout << "Введите количество элементов  " << endl;
			int q; cin >> q;
			for (int i = 0; i < q; i++)
			{
				cout << "Введите элемент  " << endl;
				int k;  cin >> k;
				add_list(root, k);
			}
		} break;
		case 3:
		{
			View_Tree(root, 0);
		}break;
		case 4:
		{
			return 0;
		}break;
		default:
		{
			cout << "Введите правильно " << endl;
		}
		}
	}
	
	
}

