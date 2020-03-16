#ifndef SEGMENT_H
#define SEGMENT_H
class Segment
{
  private:
	const int up = 0;
	const int down = 1;
	const int left = 2;
	const int right = 3;
	int x;
	int y;

  
  public:
	Segment();
	int getX();
	int getY();
	void setPos(int x, int y);
	void move(int direction);
};
#endif