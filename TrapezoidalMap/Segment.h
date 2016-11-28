#ifndef SEGMENT_H

#define SEGMENT_H

#include "Point.h"

class Segment
{
public:
	Point _leftPoint;
	Point _rightPoint;

	inline Segment() {}
	inline Segment(Point left, Point right) { _leftPoint = left; _rightPoint = right; }
	inline Segment(float x1, float y1, float x2, float y2) { _leftPoint = Point(x1, y1); _rightPoint = Point(x2, y2); }

	float get_slope();
	bool get_point_on_segment(float x, Point *result);
	bool get_point_on_segment(float x, float *xr, float *yr);

	void render();
};

#endif
