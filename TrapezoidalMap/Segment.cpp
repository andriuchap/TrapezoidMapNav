#include "Segment.h"
#include <SDL_opengl.h>

float Segment::get_slope()
{
	float dx = _rightPoint._x - _leftPoint._x;
	float dy = _rightPoint._y - _leftPoint._y;
	if (dx != 0.0f)
	{
		return dy / dx;
	}
	return 0.f;
}

bool Segment::get_point_on_segment(float x, Point *result)
{
	if (x < _leftPoint._x || x > _rightPoint._x)
	{
		return false;
	}
	float k = get_slope();
	float b = _leftPoint._y - k * _leftPoint._x;
	float y = k * x + b;
	result->_x = x;
	result->_y = y;
	return true;
}

bool Segment::get_point_on_segment(float x, float *xr, float *yr)
{
	Point result;
	if (get_point_on_segment(x, &result))
	{
		*xr = result._x;
		*yr = result._y;
		return true;
	}
	return false;
}

void Segment::render()
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2f(_leftPoint._x, 640 - _leftPoint._y);
	glVertex2f(_rightPoint._x, 640 - _rightPoint._y);
	glEnd();
	_leftPoint.render();
	_rightPoint.render();
}