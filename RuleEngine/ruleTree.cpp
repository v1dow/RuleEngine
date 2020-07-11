#include "ruleTree.h"

ruleTree::ruleTree()
{
	root = NULL;
}

ruleTree::ruleTree(string ac)
{
	root = new TNode(ac);
	if (root == NULL)
		return;
}

ruleTree::~ruleTree()
{
	if (root == NULL)
		return;
	FreeMem(root);
}

void ruleTree::FreeMem(TNode* node)
{
	if (node == NULL)
		return;
	if (node->children != NULL)
	{
		for (auto it = node->children->begin(); it != node->children->end(); it++)
			FreeMem(*it);
	}
	delete node;
	node = NULL;
}

TNode* ruleTree::Find(TNode* node, string ac)
{
	if (node->element == ac)
		return node;
	if (node->children->empty())
		return NULL;
	else {
		for (auto it = node->children->begin(); it != node->children->end(); it++)
		{
			TNode* tmp = Find(*it, ac);
			if (tmp == NULL)
				continue;
		}
	}
}

bool ruleTree::isEqual(TNode* node1, TNode* node2)
{
	if (node1->element == node1->element)
		return true;
	return false;
}

void ruleTree::SetChild(string parent, string child)
{
	if (root == NULL)
		return;
	TNode* node = new TNode(child);
	TNode* tmp = Find(root, parent);
	tmp->children->push_back(node);
	node->parent = tmp;
}

void ruleTree::SetChild(string parent, TNode* child)
{
	if (root == NULL)
		return;
	TNode* tmp = Find(root, parent);
	tmp->children->push_back(child);
	child->parent = tmp;
}

void ruleTree::SetChildren(string parent, vector<string>* children)
{
	for (int i = 0; i < children->size(); i++)
	{
		SetChild(parent, children->at(i));
	}
}

void ruleTree::SetChildren(string parent, vector<TNode*>* children)
{
	for (int i = 0; i < children->size(); i++)
	{
		SetChild(parent, children->at(i));
	}
}

vector<TNode*>* ruleTree::GetChildren()
{
	return this->GetRoot()->children;
}

void ruleTree::removeChild(string parent, string child)
{
	vector<TNode*>* children = Find(root, parent)->children;
	for (auto it = children->begin(); it != children->end(); it++)
	{
		if (isEqual(*it, Find(root, child)))
			FreeMem(*it);
	}
}

void ruleTree::removeChildren(string parent, vector<string>* children)
{
	for (int i = 0; i < children->size(); i++)
	{
		removeChild(parent, children->at(i));
	}
}

TNode* ruleTree::GetRoot()
{
	return this->root;
}

void ruleTree::tranversal(TNode* root) {
	vector<TNode*>* nodes = root->children;
	for (int i = 0; i < nodes->size(); ++i) {
		if (nodes->at(i)->children->size() > 0)
			tranversal(nodes->at(i));
		else
			cout << nodes->at(i)->element << ",";
	}
	cout << root->element << ",";
}

void ruleTree::tranversal() {
	this->tranversal(this->root);
}