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

void Trapezoid::render()
{
	float x1, y1 = 0;
	float x2, y2 = 0;
	float x3, y3 = 0;
	float x4, y4 = 0;

	if (bottom != nullptr)
	{
		if (leftp != nullptr)
		{
			bottom->get_point_on_segment(leftp->_x, &x1, &y1);
		}
		if (rightp != nullptr)
		{
			bottom->get_point_on_segment(rightp->_x, &x2, &y2);
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
			top->get_point_on_segment(rightp->_x, &x3, &y3);
		}
		if (leftp != nullptr)
		{
			top->get_point_on_segment(leftp->_x, &x4, &y4);
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
	if (leftp == nullptr)
	{
		x1 = 0;
		x4 = 0;
	}

	glBegin(GL_QUADS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//glColor3f(.5f, 0.5f, 0.75f);
	//lower left
	glColor4f(.5f, 0.5f, 0.75f, 0.25f);
	glVertex2f(x1 + TRAPEZOID_BORDER_GAP, 640 - (y1 + TRAPEZOID_BORDER_GAP));
	// lower right
	glVertex2f(x2 - TRAPEZOID_BORDER_GAP, 640 - (y2 + TRAPEZOID_BORDER_GAP));
	//top right
	glVertex2f(x3 - TRAPEZOID_BORDER_GAP, 640 - (y3 - TRAPEZOID_BORDER_GAP));
	// top left
	glVertex2f(x4 + TRAPEZOID_BORDER_GAP, 640 - (y4 - TRAPEZOID_BORDER_GAP));

	glColor4f(.65f, 0.65f, 0.85f, 0.25f);
	glVertex2f(x1 + TRAPEZOID_INNER_GAP, 640 - (y1 + TRAPEZOID_INNER_GAP));
	glVertex2f(x2 - TRAPEZOID_INNER_GAP, 640 - (y2 + TRAPEZOID_INNER_GAP));
	glVertex2f(x3 - TRAPEZOID_INNER_GAP, 640 - (y3 - TRAPEZOID_INNER_GAP));
	glVertex2f(x4 + TRAPEZOID_INNER_GAP, 640 - (y4 - TRAPEZOID_INNER_GAP));
	glEnd();
}