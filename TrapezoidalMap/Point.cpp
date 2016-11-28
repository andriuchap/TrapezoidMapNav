#include "Point.h"
#include <SDL_opengl.h>

void Point::render()
{
	glBegin(GL_QUADS);
	glColor3f(1.f, 0.f, 0.f);
	glVertex2f(_x-POINT_HALF_SIZE, 640 - (_y - POINT_HALF_SIZE));
	glVertex2f(_x - POINT_HALF_SIZE, 640 - (_y + POINT_HALF_SIZE));
	glVertex2f(_x + POINT_HALF_SIZE, 640 - (_y + POINT_HALF_SIZE));
	glVertex2f(_x + POINT_HALF_SIZE, 640 - (_y - POINT_HALF_SIZE));
	glEnd();
}