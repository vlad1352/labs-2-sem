#include <conio.h>
#include <iostream>

struct node
{
	int info;                          
	node *l, *r;                        
};

using namespace std;

node *tree = NULL;                      

void push(int a, node **t)
{
	if ((*t) == NULL)                   
	{
		(*t) = new node;               
		(*t)->info = a;                 
		(*t)->l = (*t)->r = NULL;       
		return;                         
	}
	if (a > (*t)->info) push(a, &(*t)->r);
	else push(a, &(*t)->l);        
}

void print(node *t, int u)
{
	if (t == NULL) return;                  
	else 
	{
		print(t->r, ++u);                   
		for (int i = 0; i < u; ++i) cout << "  ";
		cout << t->info << endl;            
		u--;
	}
	print(t->l, ++u);                       
}

node* Del_Info(node *root, int key, int n)
{
	node *Del, *Prev_Del, *R, *Prev_R;
	Del = root;
	Prev_Del = NULL;
	while (Del != NULL && Del->info != key)
	{
		Prev_Del = Del;
		if (Del->info > key)  Del = Del->l;
		else Del = Del->r;
	}
	if (Del == NULL) 
	{				
		cout << "NOT Key!";
		return root;
	}
	if (Del->r == NULL) R = Del->l;
	else
		if (Del->l == NULL) R = Del->r;
		else
		{
			Prev_R = Del;
			R = Del->l;
			while (R->r != NULL)
			{
				Prev_R = R;
				R = R->r;
			}
			if (Prev_R == Del)  R->r = Del->r;
			else {
				R->r = Del->r;
				Prev_R->r = R->l;
				R->l = Prev_R;
			}
		}
	if (Del == root) root = R;			
	else if (Del->info < Prev_Del->info) Prev_Del->l = R;				
		 else	Prev_Del->r = R;	
	delete Del;
	return root;
}

void Make_Blns(node **p, int n, int k, int a[]) 
{
	if (n == k) 
	{
		*p = NULL;
		return;
	}
	else 
	{
		int m = (n + k) / 2;
		*p = new node;
		(*p)->info = a[m];
		Make_Blns(&(*p)->l, n, m, a);
		Make_Blns(&(*p)->r, m + 1, k, a);
	}
}

int get(node *p, int n, int c = 0)
{
	if (n == c)  return 1;
	return ((p->l) ? get(p->l, n, c + 1) : 0) + ((p->r) ? get(p->r, n, c + 1) : 0);
}

void lvl(node *root) {
	int t = 0, l = 0;
	while ((l = get(root, t++)) != 0) {
		printf("lvl(%d) = %d\n", t, l);
	}
}

int n, a[111], w = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "Что хотите сделать\n1 - создать дерево\n2 - просмотреть дерево\n3 - Удаление узла по ключу\n4 - сбалансировать\n5 - задание\n6 - выход\n";
		int k; cin >> k;
		switch (k)
		{
		case 1:
		{
			int s;
			cout << "введите количество элементов  ";
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				cout << "ведите число  ";
				cin >> s;
				a[w] = s;
				w++;
				push(s, &tree);
			}
			int r;
			for (int i = 0; i < w - 1; i++)
			{
				for (int j = i + 1; j < w; j++)
				{
					if (a[i] > a[j])
					{
						r = a[i];
						a[i] = a[j];
						a[j] = r;
					}
				}
			}

		}break;
		case 2:
		{
			cout << "ваше дерево\n";
			print(tree, 0);
		}break;
		case 3:
		{
			cout << "Введите ключ который хотите удалить  ";
			int key; cin >> key;
			Del_Info(tree, key, n);
		}break;
		case 4:
		{
			Make_Blns(&tree, 0, w, a);
		}break;
		case 5:
		{
			lvl(tree);

		}break;
		case 6:
		{
			return 0;
		}break;
		default:
		{
			cout << "Введите правильно";
		}
		}
	}
}