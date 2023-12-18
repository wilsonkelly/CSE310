//Name: Wilson Kelly
//CSE310 - Summer
//BST.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
	class node
	{
	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};

	
public:
	node* root;
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void TREE_INSERT(int );
	void POSTORDER_TREE_WALK(node*);
	void PREORDER_TREE_WALK(node*);
	//below returns node 
	BinarySearchTree::node* TREE_MINIMUM(node*);
	BinarySearchTree::node* TREE_MAXIMUM(node*);
	BinarySearchTree::node* TREE_SUCCESOR(node*);
	void INORDER_TREE_WALK(node*);
	void TRANSPLANT(node*, node*);
	void TREE_DELETE(node*);
	BinarySearchTree::node* TREE_SEARCH(node*, int );
};

void BinarySearchTree::TREE_INSERT(int d) {
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	z->key = d;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void BinarySearchTree::INORDER_TREE_WALK(node* x) {
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}
}

void BinarySearchTree::POSTORDER_TREE_WALK(node* x) {
	if (x != NULL)
	{
		if (x->left) POSTORDER_TREE_WALK(x->left);
		if (x->right) POSTORDER_TREE_WALK(x->right);
		cout << " " << x->key << " ";
	}
}

void BinarySearchTree::PREORDER_TREE_WALK(node* x) {
	if (x != NULL)
	{
		cout << " " << x->key << " ";
		if (x->left) PREORDER_TREE_WALK(x->left);
		if (x->right) PREORDER_TREE_WALK(x->right);
	}
}

BinarySearchTree::node* BinarySearchTree::TREE_MINIMUM(node* x) {
	while (x->left != NULL) {
		x=x->left;
	}
	cout << x->key;
	return x;
}

BinarySearchTree::node* BinarySearchTree::TREE_MAXIMUM(node* x) {
	while (x->right != NULL) {
		x=x->right;
	}
	cout << x->key;
	return x;
}

BinarySearchTree::node* BinarySearchTree::TREE_SUCCESOR(node* x) {
	node* y;
	if(x->right != NULL) {
		return TREE_MINIMUM(x->right);
	}
	y=x->parent;
	while(y != NULL && x==y->right) {
		x=y;
		y=y->parent;
	}
	//cout << y->key;
	return y; //this will return null, so prepare for that
}

void BinarySearchTree::TRANSPLANT(node* u, node* v) {
	if(u->parent==NULL) {
		root=v;
	}
	else if(u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	if(v!=NULL) {
		v->parent = u->parent;
	}
}

void BinarySearchTree::TREE_DELETE(node* z) {
	node* y;
	if(z->left==NULL) {
		TRANSPLANT(z,z->right);
	}
	else if(z->right==NULL){
		TRANSPLANT(z,z->left);
	}
	else {
		y=TREE_MINIMUM(z->right);
		if (y->parent!=z) {
			TRANSPLANT(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		TRANSPLANT(z,y);
		y->left=z->left;
		y->left->parent=y;
	}
}

BinarySearchTree::node* BinarySearchTree::TREE_SEARCH(node* x, int k) {
	if (x==NULL || k==x->key) {
		return x;
	}
	if (k<x->key) {
		return TREE_SEARCH(x->left, k);
	}
	else {
		return TREE_SEARCH(x->right, k);
	}
}

int main()
{
	BinarySearchTree bst;
	char choice;
	int key;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree " << endl;
		cout << " ----------------------------- " << endl;
		cout << " a. Insert " << endl;
		cout << " b. Post Order Traversal " << endl;
		cout << " c. Pre Order Traversal" << endl;
		cout << " d. Find Min " << endl;
		cout << " e. Remove Min " << endl;
		cout << " f. Successor " << endl;
		cout << " g. Delete " << endl;
		cout << " h. In-Order Traversal " << endl;
		cout << " i. Find Max " << endl;
		cout << " j. Remove Max " << endl;
		cout << " k. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 'a': cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 'b': cout << endl;
			cout << " Post Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.POSTORDER_TREE_WALK(bst.root);
			break;
		case 'c': cout << endl;
			cout << " Pre Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.PREORDER_TREE_WALK(bst.root);
			break;
		case 'd': cout << endl;
			cout << " Find Min " << endl;
			cout << " -------------------" << endl;
			bst.TREE_MINIMUM(bst.root);
			break;
		case 'e': cout << endl;
			cout << " Remove Min " << endl;
			cout << " -------------------" << endl;
			if(bst.root) {
				bst.TREE_DELETE(bst.TREE_MINIMUM(bst.root));;
			}
			else {
				cout << " tree is empty " << endl;
			}
			break;
		case 'f': cout << endl;
			cout << " Successor " << endl;
			cout << " -------------------" << endl;
			if (bst.TREE_SUCCESOR(bst.root)) {
				cout << " succesor is displayed " << endl;
			}
			else {
				cout << " root has the largest key in the tree" << endl;
			}
			break;
		case 'g': cout << endl;
			cout << " Delete " << endl;
			cout << " -------------------" << endl;
			if(bst.root) {
				bst.TREE_DELETE(bst.root);
			}
			else {
				cout << " tree is empty " << endl;
			}
			break;
		case 'h': cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 'i': cout << endl;
			cout << " Find Max " << endl;
			cout << " -------------------" << endl;
			bst.TREE_MAXIMUM(bst.root);
			break;
		case 'j': cout << endl;
			cout << " Remove Max " << endl;
			cout << " -------------------" << endl;
			if(bst.root) {
				bst.TREE_DELETE(bst.TREE_MAXIMUM(bst.root));;
			}
			else {
				cout << " tree is empty " << endl;
			}
			break;
		case 'k': system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}