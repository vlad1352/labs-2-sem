#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Node 
{
public:
	int value;
	char name[20];
	Node *left = nullptr, *right = nullptr, *root = nullptr;;
	Node (int inf, Node *parent) 
	{	
		this->value = inf;			
		this->left = nullptr;
		this->right = nullptr;
		this->root = parent;
	}
private:
};
class Tree{
public:
	Tree(){};
	~Tree(){
		Del_Tree();
	}
void push(int item){
	Node *current = rootTree;
	Node *parent=nullptr;
	while (current != nullptr){
		if (item >= current->value){
			parent = current;
			current = current->right;

		}
		else if (item < current->value){
			parent = current;
			current = current->left;
		}
	}
	if (parent != nullptr){
		if (item >= parent->value){
			parent->right = new Node(item, parent);
		}
		else if (item < parent->value){
			parent->left = new Node(item, parent);
		}
	}
	else 
		rootTree = new Node(item, parent);	
	size++;
	el.push_back(item);
	
}
void show(){
	int p = 0;
	Node *current = rootTree;
	if (current == nullptr)
		return;
	cout << current->value;
	if (current->left != nullptr)
		show(current->left, p + 1);
	cout << endl;
	if (current->right != nullptr)
		show(current->right, p + 1);
}
void show(Node *current, int p){
	cout << '\t';
	cout << current->value;
	if (current->left != nullptr)
		show(current->left, p + 1);
	if (current->right != nullptr){
		cout << endl;
		for (int i = 0; i < p; i++)
			cout << '\t';
		show(current->right, p + 1);
	}
}
void Del_Tree(){
	Del_Tree(&rootTree);
	rootTree = nullptr;
	cout << "\nTree is cleaned\n";
}
void Del_Tree(Node **t) {
	if ((*t) != nullptr)  {
		Del_Tree((&(*t)->left)); 			
		Del_Tree((&(*t)->right));
		delete *t;
		*t = nullptr;
	}
}
void Blns(){
	for (int i = 0; i < el.size(); i++){
		for (int j = i; j< el.size(); j++){
			if (el[i]>el[j]){
				swap(el[i], el[j]);
			}
		}
	}
	Node **kek = &rootTree;
	Blns(kek, 0, el.size(), el, nullptr);
}
void Blns(Node **current, int n, int k, vector<int> a, Node *par) {
	if (n == k) {
		current = nullptr;
		return;
	}
	else {
		int m = (n + k) / 2;
		*current = new Node(a[m], par);
		Blns(&(*current)->left, n, m, a, *current);
		Blns(&(*current)->right, m + 1, k, a, *current);
	}
}
void find(int ser){
	Node **current = &rootTree;
	Node *biba = find(&(*current), ser);
	current = &biba;
	if ((*current)!=nullptr)
		cout << "Value " << (*current)->value << " does exist " << endl;
	else cout <<"Value " << ser<< " does not exist " << endl;
}
Node *find(Node **current, int ser ){
	if (*current == nullptr)
		return nullptr;
	if (ser == (*current)->value)
		return *current;
	else
		if (ser<(*current)->value)
			return find(&((*current)->left), ser);
		if (ser>(*current)->value)
			return find(&((*current)->right), ser);
}
void delel(int del){
	Node *tmp;
	tmp = find(&rootTree, del);
	if (tmp == nullptr){
		cout << "Such element does not exist\n";
		return;
	}
	else {
		int swop = 0;
		while ((tmp)->left != nullptr && (tmp)->right != nullptr){
			tmp = delel(tmp, swop);
			swop++;
		}
	}
	if ((tmp)->root->right == tmp){
		(tmp)->root->right = nullptr;
		delete tmp;
		tmp = nullptr;
	}
	else if ((tmp)->root->left == tmp){
		(tmp)->root->left = nullptr;
		delete tmp;
		tmp = nullptr;
	}
		int k = 0;
		for (int i = 0; i < this->el.size(); i++){
			if (el[i] == del)
				k = i;
				break;
		}
		this->el.erase(el.begin()+k);
		el.shrink_to_fit();
		cout << "If "<<del<<" was, it was deleted";
}
void delel(int del, Node *fromthis){
	Node *tmp;
	tmp = find(&fromthis, del);
	if (tmp == nullptr)
		return;
	else {
		int swop = 0;
		while ((tmp)->left != nullptr && (tmp)->right != nullptr)
		{	
			tmp = delel(tmp, swop);
			swop++;
		}
	}
	if ((tmp)->root->right == tmp){
		(tmp)->root->right = nullptr;
		delete tmp;
		tmp = nullptr;
	}
	else if ((tmp)->root->left == tmp){
		(tmp)->root->left = nullptr;
		delete tmp;
		tmp = nullptr;
	}
	//current = nullptr;
	int k = 0;
	for (int i = 0; i < this->el.size(); i++){
		if (el[i] == del)
			k = i;
		break;
	}
	if (el.size()>0)
	el.erase(el.begin() + k);
	el.shrink_to_fit();
}
Node *delel(Node *current, int k){
	if (current->left != nullptr && k == 0){
		swap(current->value, current->left->value);
		return current->left;
	}
	if (current->right != nullptr){
		swap(current->value, current->right->value);
		return current->right;
	}
	else  if (current->left != nullptr){
		swap(current->value, current->left->value);
		return current->left;
	}
	else return current;
}

void delbr(int ser){
	Node *br = find(&rootTree ,ser);
	if (br == rootTree){
		Del_Tree(&rootTree);
		cout << "\nCause such element was in a root of a tree\n";
		return;
	}
	Node *tmp = br;
	if (br != nullptr){
		Node *br1 = br->left, *br2 = br->right;
			while (br1 != nullptr){
				delel(br1->value, br1);
				br1 = br->left;
			}
			while (br2 != nullptr){
				delel(br2->value, br2);
				br2 = br->right;
			}
			delel(tmp->value, tmp);
			br = nullptr;
	}
	else
		cout << "No branch with such element" << endl;
	
}

private:
	Node *rootTree = nullptr;
	int size = 0;
	vector<int> el;
};
