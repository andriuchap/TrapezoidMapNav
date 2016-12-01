#ifndef TRAPEZOID_H

#define TRAPEZOID_H

#include "Point.h"
#include "Segment.h"

class Trapezoid
{
public:
	Point *leftp;
	Point *rightp;
	Segment *top;
	Segment *bottom;

	Trapezoid *upperLeft;
	Trapezoid *lowerLeft;
	Trapezoid *upperRight;
	Trapezoid *lowerRight;

	Trapezoid();

	~Trapezoid();

	Trapezoid& operator=(const Trapezoid &t);

	void render();
private:
	const float TRAPEZOID_BORDER_GAP = 2.0f;
	const float TRAPEZOID_INNER_GAP = 4.0f;
};

#endif
