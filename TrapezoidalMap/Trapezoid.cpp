#include "Trapezoid.h"
#include <SDL_opengl.h>

Trapezoid::Trapezoid()
{
	leftp = nullptr;
	rightp = nullptr;

	top = nullptr;
	bottom = nullptr;

	upperLeft = nullptr;
	lowerLeft = nullptr;

	upperRight = nullptr;
	lowerRight = nullptr;
}

Trapezoid & Trapezoid::operator=(const Trapezoid & t)
{
	leftp = t.leftp;
	rightp = t.rightp;

	top = t.top;
	bottom = t.bottom;

	upperLeft = t.upperLeft;
	lowerLeft = t.lowerLeft;

	upperRight = t.upperRight;
	lowerRight = t.lowerRight;

	return *this;
}

Trapezoid::~Trapezoid()
{
	leftp = nullptr;
	rightp = nullptr;

	top = nullptr;
	bottom = nullptr;

	upperLeft = nullptr;
	lowerLeft = nullptr;

	upperRight = nullptr;
	lowerRight = nullptr;
}

void Trapezoid::render()
{
	float x1 = 0, y1 = 0;
	float x2 = 0, y2 = 0;
	float x3 = 0, y3 = 0;
	float x4 = 0, y4 = 0;

	if (bottom != nullptr)
	{
		if (leftp != nullptr)
		{
			y1 = bottom->get_point_on_segment(leftp->_x);
		}
		if (rightp != nullptr)
		{
			y2 = bottom->get_point_on_segment(rightp->_x);
		}
	}
	else
	{
		y1 = 0; y2 = 0;
	}
	if (top != nullptr)
	{
		if (rightp != nullptr)
		{
			y3 = top->get_point_on_segment(rightp->_x);
		}
		if (leftp != nullptr)
		{
			y4 = top->get_point_on_segment(leftp->_x);
		}
	}
	else
	{
		y3 = 640;
		y4 = 640;
	}
	if (rightp == nullptr)
	{
		x2 = 800;
		x3 = 800;
	}
	else
	{
		x2 = x3 = rightp->_x;
	}
	if (leftp == nullptr)
	{
		x1 = 0;
		x4 = 0;
	}
	else
	{
		x1 = x4 = leftp->_x;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS);

	//lower left
	glColor4f(.5f, 0.5f, 0.75f, 0.5f);
	glVertex2f(x1 + TRAPEZOID_BORDER_GAP, 640 - (y1 + TRAPEZOID_BORDER_GAP));
	// lower right
	glVertex2f(x2 - TRAPEZOID_BORDER_GAP, 640 - (y2 + TRAPEZOID_BORDER_GAP));
	//top right
	glVertex2f(x3 - TRAPEZOID_BORDER_GAP, 640 - (y3 - TRAPEZOID_BORDER_GAP));
	// top left
	glVertex2f(x4 + TRAPEZOID_BORDER_GAP, 640 - (y4 - TRAPEZOID_BORDER_GAP));

	glColor4f(.65f, 0.65f, 0.85f, 0.5f);
	glVertex2f(x1 + TRAPEZOID_INNER_GAP, 640 - (y1 + TRAPEZOID_INNER_GAP));
	glVertex2f(x2 - TRAPEZOID_INNER_GAP, 640 - (y2 + TRAPEZOID_INNER_GAP));
	glVertex2f(x3 - TRAPEZOID_INNER_GAP, 640 - (y3 - TRAPEZOID_INNER_GAP));
	glVertex2f(x4 + TRAPEZOID_INNER_GAP, 640 - (y4 - TRAPEZOID_INNER_GAP));
	glEnd();
}