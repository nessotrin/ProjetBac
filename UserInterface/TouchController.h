#ifndef _TOUCH_CONTROLER_H_
#define _TOUCH_CONTROLER_H_

#include "UIHelper.h"

/**
TOP LEFT 0;0         BOTTOM RIGHT 1;1
**/
enum TOUCH_CORNER {
TOP_LEFT = 0,
TOP_RIGHT,
BOTTOM_LEFT,
BOTTOM_RIGHT,	
};

enum AXIS{
	X = 0,
	Y,
};

struct Boundaries{
	int lowLimit;
	int highLimit;
};



#define RESOLUTION_X 100
#define RESOLUTION_Y 50

class TouchController
{
public:
	
	Pos getCursorPos();


	void setCalibrationData(TOUCH_CORNER corner);

private:

	
	int calibrationPoints[2][4];
	int getTension(AXIS axis);
	int computeRealPos(AXIS axis, int value);
	Boundaries computeAxisLimit(AXIS axis, float opositeAxisPos);

};

#endif // _TOUCH_CONTROLER_H_
