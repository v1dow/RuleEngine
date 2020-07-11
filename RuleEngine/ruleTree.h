#ifndef RULETREE_H
#define RULETREE_H

//#include "func.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct TNode {
	string element;
	vector<TNode*>* children;
	TNode* parent;

	TNode(string ac)
	{
		element = ac;
		children = new vector<TNode*>();
		parent = nullptr;
	}
};

class ruleTree
{
	TNode* root;

public:
	ruleTree();
	ruleTree(string ac);
	~ruleTree();
	void FreeMem(TNode* root);
	TNode* Find(TNode* node, string ac);
	bool isEqual(TNode* node1, TNode* node2);
	void SetChild(string parent, string child);
	void SetChild(string parent, TNode* child);
	void SetChildren(string parent, vector<string>* children);
	void SetChildren(string parent, vector<TNode*>* children);
	vector<TNode*>* GetChildren();
	void removeChild(string parent, string child);
	void removeChildren(string parent, vector<string>* children);
	TNode* GetRoot();

	void tranversal(TNode* root);
	void tranversal();
};

#endif // !RULETREE_H
#pragma once
