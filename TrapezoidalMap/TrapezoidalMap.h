#ifndef TRAPEZOIDAL_MAP_H

#define TRAPEZOIDAL_MAP_H

#include <vector>
#include "Trapezoid.h"
#include "SearchTree.h"

class TrapezoidalMap
{
private:

	//std::vector<Point> points;
	std::vector<Segment*> segments;
	std::vector<Trapezoid*> trapezoids;

public:

	TrapezoidalMap();
	~TrapezoidalMap();

	void add_segment(Point* pt1, Point* pt2, SearchTree* tree);
	void render();

	Segment* get_segment(int i);
	Trapezoid* get_trapezoid(int i);
};

#endif