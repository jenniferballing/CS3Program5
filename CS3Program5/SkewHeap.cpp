#include "SkewHeap.h"


SkewHeap::SkewHeap(string n)
{
	name = n;
}
void SkewHeap::insert(ItemType & i)
{
	if (root == NULL)
	{
		root = new Node(i, NULL, NULL);
	}
	else if (i.priority > root->element.priority)
	{
		Node* newRoot = new Node(i, root, NULL);
		root = newRoot;
	}
	else
	{
		Node* newNode = new Node(i, NULL, NULL);
		Node* returned = merge(newNode, root);
	}	
	size++;
}
ItemType SkewHeap::deleteMax()
{
	Node* oldRoot = root;	
	Node* returned = merge(root->right, root->left);
	//root = NULL;
	return oldRoot->element;
}

Node* SkewHeap::merge(Node*a, Node*b)
{
	if (a == NULL)return b;
	if (b == NULL) return a;
	
	if (a->element.priority >= b->element.priority)
	{
		Node *temp = a->right;
		a->right = a->left;
		a->left = merge(b, temp);
		return a;	
	}
	else
	{
		return merge(b, a);
	}
}
void SkewHeap::merge(PQ *h)
{
	Node* merged = merge(h->root, this->root);
}
string SkewHeap::toString(int printSize)const
{
	if (printSize > size)printSize = size;
	string tree = name + " current size = " + to_string(size);
	string i = "  ";
	tree += treeString(root, i);
	return tree;
}
string SkewHeap::treeString(Node *i, string indent)const
{
	string left, right;
	if (i == NULL) return "";
	else
	{
		Node * parent;
		parent = findParent(i, root);
	}

	if (i->left != NULL)left = "\n" + treeString(i->left, indent + "   ");
	else left = "";
	if (i->right != NULL)right = "\n" + treeString(i->right, indent + "   ");
	else right = "";

	return "\n" + right + indent + i->element.word + left + "\n";
}
Node* SkewHeap::findParent(Node* child, Node* root) const
{
	if (root == NULL) return NULL;
	if (root->left == child || root->right == child) return root;
	return	findParent(child, root->right);
	return findParent(child, root->left);
}

SkewHeap::~SkewHeap()
{
}
