#include "segment.h"
Segment::Segment()
{
    this->x = -8;
    this->y = -8;
}

int Segment::getX()
{
    return x;
}
  
int Segment::getY()
{
    return y;
}
  
void Segment::setPos(int x, int y)
{
	this->x = x;
    this->y = y;
}
  
void Segment::move(int direction)
{
	if (direction == up)
	{
		y -= 8;
	} 
	else if (direction == down)
	{
		y += 8;
	} 
	else if (direction == left)
	{
		x -= 8;
	} 
	else if (direction == right)
	{
		x += 8;
	}
}