#include "SearchTree.h"

#include "TrapezoidalMap.h"

SearchTree::SearchTree()
{
	root = nullptr;
}

SearchTree::SearchTree(TrapezoidalMap* map)
{
	root = new Query();
	root->query_type = QT_Face;
	// At the start the tree only has a single trapezoid
	// So we assume that the passed map is the starting map
	// Will have to generate a search tree if the tree is not the starting one after all
	root->face = map->get_trapezoid(0);
	root->left = nullptr;
	root->right = nullptr;
}

SearchTree::~SearchTree()
{
	delete root;
	root = nullptr;
}

Query* SearchTree::do_search(Point* pt)
{
	if (root != nullptr)
	{
		return root->evaluate(pt);
	}
	return nullptr;
}