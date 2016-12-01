#include "Segment.h"
#include <SDL_opengl.h>

float Segment::get_slope()
{
	float dx = _rightPoint->_x - _leftPoint->_x;
	float dy = _rightPoint->_y - _leftPoint->_y;
	if (dx != 0.0f)
	{
		return dy / dx;
	}
	return 0.f;
}

float Segment::get_point_on_segment(float x)
{
	if (x < _leftPoint->_x || x > _rightPoint->_x)
	{
		return -1.0f;
	}
	float k = get_slope();
	float b = _leftPoint->_y - k * _leftPoint->_x;
	float y = k * x + b;
	return y;
}

Segment::~Segment()
{
	free();
}

void Segment::render()
{
	glBegin(GL_LINES);
	glColor3f(1.f, 1.f, 1.f);
	glVertex2f(_leftPoint->_x, 640 - _leftPoint->_y);
	glVertex2f(_rightPoint->_x, 640 - _rightPoint->_y);
	glEnd();
	_leftPoint->render();
	_rightPoint->render();
}

void Segment::free()
{
	delete _leftPoint;
	_leftPoint = nullptr;
	delete _rightPoint;
	_rightPoint = nullptr;
}