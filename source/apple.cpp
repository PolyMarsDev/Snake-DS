#include "apple.h"
#include <stdlib.h>
#include <time.h>
Apple::Apple()
{
	srand(time(NULL));
	x = rand() % 32*8;
	y = rand() % 24*8;
}

int Apple::getX() 
{
	return x;
} 

int Apple::getY()
{
    return y;
}

void Apple::randomizePos()
{
	x = rand() % 32*8;
	y = rand() % 24*8;
}