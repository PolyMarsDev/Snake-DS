#include "snake.h"
#include "segment.h"
#include "apple.h"
#include <vector>
Snake::Snake(int size)
{
	segments.push_back(Segment());
	segments[0].setPos(8, 8);
	this->size = 1;
	score = 0;
	delay = 5;
	while (this->size < size)
	{
		grow();
	}
}

int Snake::getX()
{
	return segments[0].getX();
}

int Snake::getY()
{
	return segments[0].getY();
}

int Snake::getSize()
{
	return size;
}

int Snake::getScore()
{
	return score;
}

int Snake::getDelay()
{
	return delay;
}

bool Snake::hasApple()
{
	return getX() == apple.getX() && getY() == apple.getY();
}

void Snake::grow()
{
	size += 1;
	segments.resize(size);
}

bool Snake::hasSegment(int x, int y, bool includeHead)
{
	int startIndex = 1;
	if (includeHead) 
	{
		startIndex = 0;
	} 
	for (int i = startIndex; i < size; i++)
	{
		if (x == segments[i].getX()  && y == segments[i].getY())
		{
			return true;
		}
	}
	return false;
}

Segment Snake::getSegment(int index)
{
	return segments[index];
}

Apple Snake::getApple()
{
	return apple;
}

void Snake::randomizeApple()
{
	apple.randomizePos();
	while (hasSegment(apple.getX(), apple.getY(), true))
	{
		apple.randomizePos();
	}
}

bool Snake::move(int direction)
{
	for (int i = size - 1; i >= 1; i--)
	{
		segments[i].setPos(segments[i - 1].getX(), segments[i - 1].getY());
	}
	segments[0].move(direction);
	if (hasSegment(getX(), getY(), false) || getX() < 0 || getX() + 8 > 256 || getY() < 0 || getY() + 8 > 192)
	{
		return false;
	}
	if (hasApple())
	{
		if (size < 62)
		{
			grow();
		}
		score += 1;
		if (delay > 3)
		{
			delay -= .25;
		}
		randomizeApple();
	}
	return true;
}