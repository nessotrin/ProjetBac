#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_
	
enum ColorId
{
	R = 0,
	G = 1,
	B = 2,
};

struct RGB
{
	unsigned char value[3];
};

struct BRGB
{
	bool value[3];
};

#define LED_COUNT 3
class LedDriver
{
public:
	LedDriver();

	void work();
	void ledOn();
	void ledOff();
	void pointTo(int id);
	void emergencyFlash();



private:

	void writeLedRealtime();

	int realtimeCount;
	RGB leds[LED_COUNT];
	BRGB leds_RealtimeBool[LED_COUNT];


};

#endif // _LED_DRIVER_H_
