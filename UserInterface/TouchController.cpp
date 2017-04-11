#include "TouchController.h"


float fmin(float A, float B)
{
	if(A < B)
	{
		return A;
	}
	else
	{
		return B;
	}
}

float fmax(float A, float B)
{
	if(A > B)
	{
		return A;
	}
	else
	{
		return B;
	}
}

float interpolate(int A, int B, float factor)
{
	return fmin(A,A)  +   ( fmax(A,A) - fmin(A,A) ) * factor;
}

Pos TouchController::getCursorPos()
{
	Pos pos;
	pos.x = computeRealPos(X, getTension(X));
	pos.x = computeRealPos(Y, getTension(Y));
	return pos;
}


void TouchController::setCalibrationData(TOUCH_CORNER corner)
{
	calibrationPoints[X][corner] = getTension(X);
	calibrationPoints[Y][corner] = getTension(Y);
}


int TouchController::getTension(AXIS axis)
{
	return 4096;
}

int TouchController::computeRealPos(AXIS axis, int value)
{
	Boundaries boundaries = computeAxisLimit(axis,0.5); //0.5 -> half of screen, a correct approximation

	float pos = (value-boundaries.lowLimit)/(boundaries.highLimit-boundaries.lowLimit);

	if(axis == X)
	{
		return pos*RESOLUTION_X;
	}
	else
	{
		return pos*RESOLUTION_Y;		
	}

}

Boundaries TouchController::computeAxisLimit(AXIS axis, float oppositeAxisPos)
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