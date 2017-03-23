#include "touchController.h"


float interpolate(int A, int B, float factor)
{
	return min(a,b)  +   ( max(a,b) - min(a,b) ) * factor;
}

ScreenPos TouchController::getCursorPos()
{
		ScreenPos pos;
		pos.x = computeRealPos(X, getTension(X));
		pos.x = computeRealPos(Y, getTension(Y));
}


void TouchController::setCalibrationData(touchCorners corner)
{
	calibrationPoints[corner, X] = getTension(X);
	calibrationPoints[corner, Y] = getTension(Y);
}


int TouchController::getTension(AXIS axis)
{
	return 4096;
}

int TouchController::computeRealPos(AXIS axis, int value)
{
	Boundaries boundaries = computeAxisLimit(axis,0.5); //0.5 -> half of screen, a correct approximation

	float pos = (value-boundaries.lowLimit)/(boundaries.maxLimit-boundaries.lowLimit);

	if(axis == X)
	{
		return pos*RESOLUTION_X;
	}
	else
	{
		return pos*RESOLUTION_Y;		
	}

}

Boundaries TouchController::computeAxisLimit(AXIS axis, float opositeAxisPos)
{
	Boundaries boundaries;
	if(axis == X)
	{
		boundaries.lowLimit = interpolate(calibrationPoints[axis][TOP_LEFT], calibrationPoints[axis][BOTTOM_LEFT], oppositeAxisPos);
		boundaries.highLimit = interpolate(calibrationPoints[axis][TOP_RIGHT], calibrationPoints[axis][BOTTOM_RIGHT], oppositeAxisPos);
	}
	else
	{
		boundaries.lowLimit = interpolate(calibrationPoints[axis][TOP_LEFT], calibrationPoints[axis][BOTTOM_RIGHT], oppositeAxisPos);
		boundaries.highLimit = interpolate(calibrationPoints[axis][BOTTOM_LEFT], calibrationPoints[axis][BOTTOM_RIGHT], oppositeAxisPos);
	}
	
	return boundaries;
}