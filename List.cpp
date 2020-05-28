#include "List.h"
#include <iostream>
using namespace std;

void
List::clear(Node*& tree)
{
	if (tree == 0) return;

	if (!tree->isLeaf_) {
		clear(tree->llink_); 
		clear(tree->rlink_);
	}
	delete tree;
	tree = 0;
}

void
List::print(const Node* tree)
{
	if (tree == 0) return;

	if (tree->isLeaf_) {
		cout << tree->info_ << endl;
		return;
	}
	print(tree->llink_);
	print(tree->rlink_);
}

pair<List::Node*, int>
List::find(int pos)const
{
	if (tree_ == 0)
		return make_pair(tree_, pos);

	Node* ptr = tree_;
	while (!ptr->isLeaf_)
		if (pos <= ptr->info_)
			ptr = ptr->llink_;
		else 
		{
			pos -= ptr->info_;
			ptr = ptr->rlink_;
		}

	return make_pair(ptr, pos);
}

void
List::insert(int pos, int element)
{
	if (pos < 1) 
		return;
	if (!tree_) 
	{ 
		tree_ = new Node(element); 
		return; 
	}
	Node* Ptr = tree_;
	while (!(Ptr->isLeaf_)) 
	{
		if (pos > Ptr->info_) 
		{
			pos -= Ptr->info_;
			Ptr = Ptr->rlink_;
		}
		else {
			++(Ptr->info_);
			Ptr = Ptr->llink_;
		}
	}
	Node* newNode = new Node(element, true, Ptr);
	Node* oldNode = new Node(Ptr->info_, true, Ptr);
	Ptr->info_ = 1; 
	Ptr->isLeaf_ = false;
	if (pos > 1) 
	{ 
		Ptr->rlink_ = newNode; 
		Ptr->llink_ = oldNode; 
	}
	else 
	{ 
		Ptr->llink_ = newNode; 
		Ptr->rlink_ = oldNode; 
	}
}

void
List::remove(int pos)
{
	if (pos < 1 || !tree_) return;
	pair<List::Node*, int> rPair = find(pos);
	if (rPair.second > 1) return;
	if (rPair.first == tree_)
	{
		delete tree_; 
		tree_ = nullptr; 
		return; 
	}

	Node* rNode = rPair.first;
	Node* parent = rNode->parent_;
	Node* tmp;
	if (parent->rlink_ == rNode) 
		tmp = parent->llink_;
	else 
		tmp = parent->rlink_;
	parent->info_ = tmp->info_;
	parent->llink_ = tmp->llink_;
	parent->rlink_ = tmp->rlink_;
	parent->isLeaf_ = tmp->isLeaf_;
	if (tmp) 
	{ 
		delete tmp; 
		tmp = nullptr; 
	}
	delete rNode;
	rNode = parent;


	while (rNode->parent_) 
	{
		if (rNode == rNode->parent_->llink_)
			--(rNode->parent_->info_);
		rNode = (rNode->parent_);
	}
}