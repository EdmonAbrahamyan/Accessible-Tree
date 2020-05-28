#pragma once
#include <iostream>
using namespace std;

class List
{
	struct Node {
		int		info_;
		bool	isLeaf_;
		Node*	parent_;
		Node*	llink_;
		Node*	rlink_;

		Node(int info = 0, bool isLeaf = true, Node* parent = 0, Node* llink = 0, Node* rlink = 0) :
			info_(info), isLeaf_(isLeaf), parent_(parent), llink_(llink), rlink_(rlink) {}
	};

	static	void		clear(Node*& tree);
	static	void		print(const Node* tree);
	pair<Node*, int>	find(int pos)const;

public:
	List() : tree_(0) {};
	~List() { clear(tree_); }
	void	print()const { print(tree_); }

	int&	operator[](int pos) { return find(pos).first->info_; }


	void	insert(int pos, int element);	

	void	remove(int pos);

private:
	Node* tree_;
};