#ifndef SNAKE_H
#define SNAKE_H

#include "segment.h"
#include "apple.h"
#include <vector>
class Snake
{
  private:
	int size;
	int score;
	int delay;
	std::vector<Segment> segments;
	Apple apple;
	
  public:
	Snake(int size);
	int getX();
	int getY();
	int getSize();
	int getScore();
	int getDelay();
	bool hasApple();
	void grow();
	bool hasSegment(int x, int y, bool includeHead);
	Segment getSegment(int index);
	Apple getApple();
	void randomizeApple();
	bool move(int direction);
};
#endif