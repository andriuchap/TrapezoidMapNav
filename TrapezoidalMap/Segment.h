#ifndef SEGMENT_H

#define SEGMENT_H

#include "Point.h"

class Segment
{
public:
	Point* _leftPoint;
	Point* _rightPoint;

	inline Segment() { _leftPoint = nullptr; _rightPoint = nullptr; }
	inline Segment(Point* left, Point* right) { _leftPoint = left; _rightPoint = right; }
	inline Segment(float x1, float y1, float x2, float y2) { _leftPoint = new Point(x1, y1); _rightPoint = new Point(x2, y2); }
	inline ~Segment();

	float get_slope();
	float get_point_on_segment(float x);

	void render();

	void free();
};

#endif
