#pragma once
enum Order
{
	INORDER = 0,
	PREORDER = 1,
	POSTORDER = 2,
	XOrder = 3
};

template <class T>
class BSTNode
{
public:
	T value;
	BSTNode<T>* left, * right;
	BSTNode();
	BSTNode(T val);
};

template <class T>
class BSTree
{
	BSTNode<T>* root;

public:
	BSTree(void);
	~BSTree(void);

	bool contains(T val);
	BSTNode<T>* findNode(T val);
	void insert(T val);
	//Function to return level of the node
	int getLevel(T val);
	void traverse(Order order);
	void inOrder(BSTNode<T>* node);
	void preOrder(BSTNode<T>* node);
	void postOrder(BSTNode<T>* node);
	BSTNode<T>* findParent(T val);
	BSTNode<T>* findMin(BSTNode<T>* start);
	void remove(T val);
	void deleteBST(BSTNode<T>* node);
};