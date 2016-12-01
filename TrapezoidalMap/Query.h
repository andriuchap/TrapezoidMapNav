#ifndef QUERY_H

#define QUERY_H

#include "Trapezoid.h"

enum QueryType
{
	QT_Point,
	QT_Segment,
	QT_Face
};

class Query
{
public:
	QueryType query_type;

	Trapezoid* face;
	Segment* segment;
	Point* point;

	Query* parent;

	Query* left;
	Query* right;
	
	Query();

	Query* evaluate(Point* pt);

};

#endif
