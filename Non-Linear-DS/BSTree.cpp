#include "BSTree.h"
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
BSTNode<T>::BSTNode()
{
	left = right = NULL;
}

template <class T>
BSTNode<T>::BSTNode(T val)
{
	value = val;
	left = right = NULL;
}

template <class T>
BSTree<T>::BSTree(void)
{
	root = NULL;
}

template <class T>
bool BSTree<T>::contains(T val)
{
	BSTNode<T>* tmp = findNode(val);
	return (tmp != NULL);
}

template <class T>
BSTNode<T>* BSTree<T>::findNode(T val)
{
	BSTNode<T>* temp = root;
	

	while (temp != NULL)
	{
		if (temp->value == val)
		{
			return temp;
		}

		if (temp->value > val)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}

	return temp;
}

template <class T>
void BSTree<T>::insert(T val)
{
	assert(!contains(val));
	BSTNode<T>* nodeToBeInserted = new BSTNode<T>(val);
	if (root == NULL)
	{
		root = nodeToBeInserted;
	}
	else
	{
		BSTNode<T>* temp = root;
		while (true)
		{
			if (temp->value > val)
			{
				//left
				if (temp->left == NULL)
				{
					temp->left = nodeToBeInserted;
					break;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				//right
				if (temp->right == NULL)
				{
					temp->right = nodeToBeInserted;
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
		}

	}

}

template <class T>
void BSTree<T>::traverse(Order order)
{
	if (order == INORDER)
		inOrder(root);
	else if (order == PREORDER)
		preOrder(root);
	else
		postOrder(root);
}

template <class T>
void BSTree<T>::inOrder(BSTNode<T>* node)
{
	if (node != NULL)
	{
		//left
		inOrder(node->left);
		//node
		cout << node->value << endl;
		//right
		inOrder(node->right);
	}
}

template <class T>
void BSTree<T>::preOrder(BSTNode<T>* node)
{
	if (node != NULL)
	{
		cout << node->value << endl;
		preOrder(node->left);
		preOrder(node->right);
	}
}

template <class T>
void BSTree<T>::postOrder(BSTNode<T>* node)
{
	if (node != NULL)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->value << endl;
	}
}

template <class T>
BSTNode<T>* BSTree<T>::findParent(T val)
{
	BSTNode<T>* parent = NULL;
	BSTNode<T>* node= root;

	while (node != NULL)
	{
		if (node->value == val)
		{
			break;
		}

		parent = node;
		if (node->value > val)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	return parent;
}

template <class T>
BSTNode<T>* BSTree<T>::findMin(BSTNode<T>* start)
{
	BSTNode<T>* minNode = start;
	while (minNode->left != NULL)
	{
		minNode = minNode->left;
	}

	return minNode;
}
template <class T>
BSTNode<T>* BSTree<T>::findMax(BSTNode<T>* start)
{
	BSTNode<T>* maxNode = start;
	while (maxNode->right != NULL)
	{
		maxNode =maxNode->right;
	}

	return maxNode;
}


template <class T>
void BSTree<T>::remove(T val)
{
	assert(contains(val));

	BSTNode<T>* n = findNode(val);

	if ((n->left == NULL) && (n->right == NULL)) //deleting a leaf node
	{
		if (n == root)
		{
			root = NULL;
		}
		else
		{
			BSTNode<T>* parent = findParent(val);
			if (val < parent->value)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		delete n;
	}
	else if ((n->left == NULL) && (n->right != NULL))
	{
		BSTNode<T>* parent = findParent(val);
		if (n == root)
		{
			root = n->right;
		}
		else
		{
			if (val < parent->value)
				parent->left = n->right;
			else
				parent->right = n->right;
		}
		delete n;
	}
	else if ((n->left != NULL) && (n->right == NULL))
	{
		BSTNode<T>* parent = findParent(val);
		if (n == root)
			root = n->left;
		else
		{
			if (val < parent->value)
				parent->left = n->left;
			else
				parent->right = n->left;
		}
		delete n;
	}
	else
	{
		BSTNode<T>* minNode = findMin(n->right);
		BSTNode<T>* parent = findParent(minNode->value);

		n->value = minNode->value;

		if (parent == n)
			parent->right = minNode->right;
		else
			parent->left = minNode->right;

		delete minNode;
	}
}

template <class T>
void BSTree<T>::deleteBST(BSTNode<T>* node)
{
	if (node == NULL)
		return;

	BSTNode<T>* currentTreeNode = node;
	BSTNode<T>* leftTreeNode = node->left;
	BSTNode<T>* rightTreeNode = node->right;
	delete(currentTreeNode);
	deleteBST(leftTreeNode);
	deleteBST(rightTreeNode);
}
template <class T>
int BSTree<T>::getLevel(T val) {
	int count = 0;
	if (findNode(val) == NULL)
		return -1;
	else {
		BSTNode <T>* tmp = root;
		while(tmp!=NULL){
		if (val > tmp->value) {
			tmp = tmp->right;
			count++;
		}
		else if (val < tmp->value) {
			tmp = tmp->left;
			count++;
		}
		else {
			return count;
		}

		}
	}
}
template <class T>
BSTree<T>::~BSTree(void)
{
	deleteBST(root);
}