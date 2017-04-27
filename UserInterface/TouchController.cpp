#include "TouchController.h"

#include "BBBiolib.h"


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

#define BUFFER_SIZE 100
unsigned int buffer_AIN_0[BUFFER_SIZE] ={0};
unsigned int buffer_AIN_1[BUFFER_SIZE] ={0};

void TouchController::init()
{
	#ifdef BBB
	unsigned int sample;
	int i ,j;

	const int clk_div = 160;
	const int open_dly = 0;
	const int sample_dly = 1;

	BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_TIMER_INT, clk_div);


	BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN0, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \
				BBBIO_ADC_STEP_AVG_1, buffer_AIN_0, BUFFER_SIZE);

	BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN1, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \
				BBBIO_ADC_STEP_AVG_1, buffer_AIN_1, BUFFER_SIZE);


	BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN0);
	BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN1);
	#endif
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
	unsigned int value = 4096;

#ifdef BBB

	BBBIO_ADCTSC_work(1);

	if(axis == X)
	{
		value = buffer_AIN_0[0];
	}
	else
	{
		value = buffer_AIN_1[0];		
	}

#endif

	return value;
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