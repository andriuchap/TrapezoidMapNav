#ifndef TRAPEZOIDAL_MAP_H

#define TRAPEZOIDAL_MAP_H

#include <vector>
#include "Trapezoid.h"

class TrapezoidalMap
{
private:

	//std::vector<Point> points;
	std::vector<Segment> segments;
	std::vector<Trapezoid> trapezoids;

public:

	TrapezoidalMap();

	void add_segment(Point pt1, Point pt2);
	void add_segment(float x0, float y0, float x1, float y1);
	void render();
};

#endif