#include<iostream>
#include "BSTree.cpp"

using namespace std;

int main()
{
	int value;
	cout << "Testing BST" << endl;
	BSTree<int> B;
	B.insert(100);
	B.insert(200);
	B.insert(90);
	B.insert(150);
	B.insert(125);
	B.insert(88);
	B.insert(99);
	B.insert(210);
	//B.remove(100);
	B.traverse(INORDER);
	cout << "Enter Value to Find Level Of Node" << endl;
	cin >> value;
	if (B.getLevel(value) == -1)
		cout << "Value Doesn't Exist" << endl;
	else 
	cout<<"level of Node With Value "<<value<<" is "<<B.getLevel(value);
	return 0;
}