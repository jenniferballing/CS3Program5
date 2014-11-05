#ifndef SKEWHEAP_H
#define SKEWHEAP_H
#include "PQ.h"

class SkewHeap: public PQ
{
public:
	SkewHeap(string);
	Node* merge(Node*, Node*);
	void merge(PQ *h);
	string toString(int size)const;
	void insert(ItemType&);
	string treeString(Node *, string)const;
	Node* findParent(Node *, Node*)const;
	ItemType deleteMax();
	~SkewHeap();
private:
	//Node* root;
	string name;
};
#endif
