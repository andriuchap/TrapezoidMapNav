#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include <vector>

const int POINT_HALF_SIZE = 3;

SDL_Window* window = NULL;
SDL_GLContext context;
//SDL_Renderer* renderer = NULL;

std::vector<SDL_Rect> rects;

std::vector<SDL_Point> points;

void drawPoint(SDL_Point p);

void drawLine(SDL_Point p1, SDL_Point p2);

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO) > 0)
	{
		printf("Error initing sdl, %s", SDL_GetError());
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	window = SDL_CreateWindow("TrapezoidalMap", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		printf("Couldnt create window, %s", SDL_GetError());
		return 2;
	}
	context = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, 800, 640);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 800, 640, 0, 0, 1);

	bool running = true;
	SDL_Event e;


	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_WINDOWEVENT)
			{
				if (e.window.event == SDL_WINDOWEVENT_CLOSE)
				{
					running = false;
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				points.push_back({ e.button.x, e.button.y });
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < points.size(); i++)
		{
			drawPoint(points[i]);
			if (i != 0 && (i % 2) == 1)
			{
				drawLine(points[i - 1], points[i]);
			}
		}

		SDL_GL_SwapWindow(window);

		SDL_Delay(1);
	}

	SDL_DestroyWindow(window);
	window = NULL;

	return 0;
}

void drawPoint(SDL_Point p)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(p.x-POINT_HALF_SIZE, p.y- POINT_HALF_SIZE);
	glVertex2i(p.x - POINT_HALF_SIZE, p.y + POINT_HALF_SIZE);
	glVertex2i(p.x + POINT_HALF_SIZE, p.y + POINT_HALF_SIZE);
	glVertex2i(p.x + POINT_HALF_SIZE, p.y - POINT_HALF_SIZE);
	glEnd();
}

void drawLine(SDL_Point p1, SDL_Point p2)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(p1.x, p1.y);
	glVertex2i(p2.x, p2.y);
	glEnd();
}