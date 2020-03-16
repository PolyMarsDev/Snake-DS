#ifndef APPLE_H
#define APPLE_H

class Apple 
{
  private:
	int x;
	int y;
	
  public:
	Apple();
	int getX();
	int getY();
	void randomizePos();
};

#endif