#include "TrapezoidalMap.h"


TrapezoidalMap::TrapezoidalMap()
{
	trapezoids.push_back(new Trapezoid());
}

void TrapezoidalMap::add_segment(Point* pt1, Point* pt2, SearchTree *tree)
{
	Segment* seg = new Segment();
	if (pt2->_x > pt1->_x)
	{
		seg->_leftPoint = pt1;
		seg->_rightPoint = pt2;
	}
	else
	{
		seg->_leftPoint = pt2;
		seg->_rightPoint = pt1;
	}
	segments.push_back(seg);
	Query* q = tree->do_search(pt1);
	std::vector<Trapezoid*> intersectedTrapezoids;
	intersectedTrapezoids.push_back(q->face);
	Trapezoid* j = q->face;
	while (j != NULL && (j->rightp != NULL &&
		j->rightp->_x < pt2->_x))
	{
		float y = seg->get_point_on_segment(j->rightp->_x);
		if (j->rightp->_y > y)
		{
			j = j->lowerRight;
		}
		else
		{
			j = j->upperRight;
		}
		if (j != nullptr)
		{
			intersectedTrapezoids.push_back(j);
		}
	}
	if (intersectedTrapezoids.size() == 1)
	{
		Trapezoid* t = intersectedTrapezoids[0];
		trapezoids.erase(trapezoids.begin());

		Trapezoid* t1 = new Trapezoid();
		t1->leftp = t->leftp;
		t1->top = t->top;
		t1->rightp = pt1;
		t1->bottom = t->bottom;

		Trapezoid* t2 = new Trapezoid();
		t2->leftp = pt1;
		t2->top = t->top;
		t2->rightp = pt2;
		t2->bottom = seg;

		Trapezoid* t3 = new Trapezoid();
		t3->leftp = pt1;
		t3->top = seg;
		t3->rightp = pt2;
		t3->bottom = t->bottom;

		Trapezoid* t4 = new Trapezoid();
		t4->leftp = pt2;
		t4->top = t->top;
		t4->rightp = t->rightp;
		t4->bottom = t->bottom;

		trapezoids.push_back(t1);
		trapezoids.push_back(t2);
		trapezoids.push_back(t3);
		trapezoids.push_back(t4);

		delete t;
		t = nullptr;
	}
}

void TrapezoidalMap::render()
{
	for (int i = 0; i < trapezoids.size(); i++)
	{
		trapezoids[i]->render();
	}
	for (int i = 0; i < segments.size(); i++)
	{
		segments[i]->render();
	}
}

Segment* TrapezoidalMap::get_segment(int i)
{
	if (i >= 0 && i < segments.size())
	{
		return segments[i];
	}
	return nullptr;
}

Trapezoid* TrapezoidalMap::get_trapezoid(int i)
{
	if (i >= 0 && i < trapezoids.size())
	{
		return trapezoids[i];
	}
	return nullptr;
}

TrapezoidalMap::~TrapezoidalMap()
{
	for (int i = 0; i < segments.size(); i++)
	{
		delete segments[i];
		segments[i] = nullptr;
	}
	segments.clear();
	for (int i = 0; i < trapezoids.size(); i++)
	{
		delete trapezoids[i];
		trapezoids[i] = nullptr;
	}
	trapezoids.clear();
}
