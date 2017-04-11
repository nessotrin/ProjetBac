#ifndef _LED_HANDLER_H_
#define _LED_HANDLER_H_

struct RGB
{
	unsigned char value[3];
};

#define LED_COUNT 3

class LedHandler
{
public:

	LedHandler();

	void work();

	void LedOn();
	void LedOff();
	void PointTo(int id);
	void EmergencyFlash();

private:

	RGB Leds[3];

	RGB Leds_RealtimeBool[3];
	unsigned int realtimeCount = 1;
	void writeLedRealtime();

	long tickCount;


};

#endif // _LED_HANDLER_H_
