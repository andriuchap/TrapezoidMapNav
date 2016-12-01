#ifndef SEARCH_TREE_H

#define SEARCH_TREE_H

#include "Query.h"

class TrapezoidalMap;

class SearchTree
{
public:

	SearchTree();
	SearchTree(TrapezoidalMap* map);
	~SearchTree();

	Query* do_search(Point* pt);

private:

	Query* root;
	
};

#endif
