#include "TouchController.h"

#include "BBBiolib.h"


#include <unistd.h>

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
#define SAMPLE_SIZE 1
unsigned int buffer_AIN_0[BUFFER_SIZE] ={0};
unsigned int buffer_AIN_1[BUFFER_SIZE] ={0};

void TouchController::init()
{
	calibrationPoints[0][0] = 10;
	calibrationPoints[0][1] = 1000;
	calibrationPoints[0][2] = 10;
	calibrationPoints[0][3] = 1000;
	calibrationPoints[1][0] = 10;
	calibrationPoints[1][1] = 10;
	calibrationPoints[1][2] = 1000;
	calibrationPoints[1][3] = 1000;
	
	#ifdef BBB
	
	/*
	iolib_init();
	

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

	*/
	
	
	unsigned int sample;
	int i ,j;
//	unsigned int buffer_AIN_0[BUFFER_SIZE] ={0};
//	unsigned int buffer_AIN_1[BUFFER_SIZE] ={0};

	/* BBBIOlib init*/
	iolib_init();
	BBBIO_ADCTSC_Init();

	/* using ADC_CALC toolkit to decide the ADC module argument . Example Sample rate : 10000 sample/s
	 *
	 *	#./ADC_CALC -f 10000 -t 5
	 *
	 *	Suggest Solution :
	 *		Clock Divider : 160 ,   Open Dly : 0 ,  Sample Average : 1 ,    Sample Dly : 1
	 *
	 */
//	const int clk_div = 34 ;
	const int clk_div = 160;
	const int open_dly = 0;
	const int sample_dly = 1;

	/*ADC work mode : Timer interrupt mode
	 *	Note : This mode handle SIGALRM using signale() function in BBBIO_ADCTSC_work();
	 */
	BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_TIMER_INT, clk_div);

	/*ADC work mode : Busy polling mode  */
	/* BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_BUSY_POLLING, clk_div);*/


	BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN0, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \
				BBBIO_ADC_STEP_AVG_1, buffer_AIN_0, BUFFER_SIZE);

	BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN1, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, open_dly, sample_dly, \
				BBBIO_ADC_STEP_AVG_1, buffer_AIN_1, BUFFER_SIZE);
	


	for(i = 0 ; i < 3 ; i++) {
		printf("Start sample , fetch %d sample \n", BUFFER_SIZE);
		BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN0);
		BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN1);
		BBBIO_ADCTSC_work(SAMPLE_SIZE);

		printf("AIN 0 :\n");
		for(j = 0 ; j < SAMPLE_SIZE ; j++) {
			sample = buffer_AIN_0[j];
			printf("\t[sample : %d , %f v]\n", sample, ((float)sample / 4095.0f) * 1.8f);
		}
		printf("AIN 1 :\n");
		for(j = 0 ; j < SAMPLE_SIZE ; j++) {
			sample = buffer_AIN_1[j];
			printf("\t[sample : %d , %f v]\n", sample, ((float)sample / 4095.0f) * 1.8f);
                }
		printf("------------------------------\n");
		//sleep(1);
}

	//BBBIO_ADCTSC_module_ctrl(BBBIO_ADCTSC_module_ctrl(BBBIO_ADC_WORK_MODE_BUSY_POLLING, 1);

//	BBBIO_ADCTSC_channel_ctrl(BBBIO_ADC_AIN1, BBBIO_ADC_STEP_MODE_SW_CONTINUOUS, 0, 1, BBBIO_ADC_STEP_AVG_1, buffer_AIN_1, 100);	
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


#endif

int i,j;
unsigned int sample;

//		printf("Start sample , fetch %d sample \n", BUFFER_SIZE);
		BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN0);
		BBBIO_ADCTSC_channel_enable(BBBIO_ADC_AIN1);
		BBBIO_ADCTSC_work(SAMPLE_SIZE);


		if(axis == X)
		{
		
//		printf("AIN 0 :\n");
		for(j = 0 ; j < SAMPLE_SIZE ; j++) {
			sample = buffer_AIN_0[j];
//			printf("\t[sample : %d , %f v]\n", sample, ((float)sample / 4095.0f) * 1.8f);
		}
		}
		else
		{
//		printf("AIN 1 :\n");
		for(j = 0 ; j < SAMPLE_SIZE ; j++) {
			sample = buffer_AIN_1[j];
//			printf("\t[sample : %d , %f v]\n", sample, ((float)sample / 4095.0f) * 1.8f);
                }
//		printf("------------------------------\n");
		}
		value = sample;
		//sleep(1);

	printf("%d\n",value);

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
