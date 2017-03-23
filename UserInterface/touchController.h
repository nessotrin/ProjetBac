#ifndef _TOUCH_CONTROLER_H_
#define _TOUCH_CONTROLER_H_

/**
TOP LEFT 0;0         BOTTOM RIGHT 1;1
**/
enum {
TOP_LEFT = 0,
TOP_RIGHT,
BOTTOM_LEFT,
BOTTOM_RIGHT,	
} TOUCH_CORNER;

struct{
	int x;
	int y;
} ScreenPos;

struct{
	int lowLimit;
	int highLimit;
} Boundaries;

enum{
	X = 0,
	Y,
} AXIS;


#define RESOLUTION_X 100
#define RESOLUTION_Y 50

class touchController
{
public:
	
	ScreenPos getCursorPos();


	void setCalibrationData(touchCorners corner, int value);

private:

	
	int calibrationPoints[2][4];
	int getTension(AXIS axis);
	int computeRealPos(AXIS axis, int value);

};

#endif // _TOUCH_CONTROLER_H_
