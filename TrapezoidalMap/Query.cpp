#include "Query.h"
#include <stdio.h>

Query::Query()
{
	query_type = QT_Face;

	face = nullptr;
	segment = nullptr;
	point = nullptr;

	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

Query* Query::evaluate(Point *pt)
{
	switch (query_type)
	{
	case QT_Point:
		if (point != nullptr)
		{
			if (pt->_x < point->_x)
			{
				printf("Going left!\n");
				return (left != nullptr) ? left->evaluate(pt) : nullptr;
			}
			else
			{
				printf("Going right!\n");
				return (right != nullptr) ? right->evaluate(pt) : nullptr;
			}
		}
		break;
	case QT_Segment:
		if (segment != nullptr)
		{
			float y = segment->get_point_on_segment(pt->_x);
			if (y != -1.0f)
			{
				if (pt->_y < y)
				{
					printf("Going down!\n");
					return (left != nullptr) ? left->evaluate(pt) : nullptr;
				}
				else
				{
					printf("Going up!\n");
					return (right != nullptr) ? right->evaluate(pt) : nullptr;
				}
			}
		}
		break;
	case QT_Face:
		printf("Found you!\n");
		return this;
		break;
	}
	return nullptr;
}