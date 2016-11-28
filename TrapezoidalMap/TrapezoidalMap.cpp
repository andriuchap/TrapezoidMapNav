#include "TrapezoidalMap.h"


TrapezoidalMap::TrapezoidalMap()
{
	trapezoids.push_back(Trapezoid());
}

void TrapezoidalMap::add_segment(Point pt1, Point pt2)
{
	Segment seg;
	if (pt2._x > pt1._x)
	{
		seg._leftPoint = pt1;
		seg._rightPoint = pt2;
	}
	else
	{
		seg._leftPoint = pt2;
		seg._rightPoint = pt1;
	}
	segments.push_back(seg);
}

void TrapezoidalMap::add_segment(float x0, float y0, float x1, float y1)
{
	add_segment(Point(x0, y0), Point(x1, y1));
}

void TrapezoidalMap::render()
{
	for (int i = 0; i < trapezoids.size(); i++)
	{
		trapezoids[i].render();
	}
	for (int i = 0; i < segments.size(); i++)
	{
		segments[i].render();
	}
}