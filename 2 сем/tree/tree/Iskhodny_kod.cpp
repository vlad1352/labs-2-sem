#include <iostream>
#include <ctime>
#include "Tree.h"
using namespace std;
void main(){
	srand(time(NULL));
	int tmp;
	Tree tree;
	for (int i = 0; i < 31; i++){
		tree.push(1+rand() % 15);
		//tree.push(((i+6)%12), "Hi");
		//tree.push(4, "Hi");
	}/*for (int i = 0; i < 3; i++){
		tree.push(5, "Hi");
	}for (int i = 0; i < 4; i++){
		tree.push(6, "Hi");
	}*/
	tree.show();
	cout << endl;
	cout << endl;
	cout << endl;
	tree.Blns();
	tree.show();
	cout << endl;
	//tree.find(4);
	cout << endl;
	//tree.delel(5);
	//tree.delel(5);
	tree.delel(10);
	cout << endl;
	tree.show();
	cout << endl;
	tree.find(5);
	tree.delbr(5);
	//cout << endl;
	tree.show();
	cout << endl;
	tree.Del_Tree();
	cout << "\nsucces\n";
	system("pause");
}