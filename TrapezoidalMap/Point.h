#ifndef POINT_H

#define POINT_H

class Point
{
public:
	float _x;
	float _y;

	Point(float x, float y) { _x = x; _y = y; }
	Point() { _x = 0; _y = 0; }

	void render();

	Point& operator=(const Point &p) { this->_x = p._x; this->_y = p._y; return *this; }

private:
	const float POINT_HALF_SIZE = 2.f;
};

#endif
