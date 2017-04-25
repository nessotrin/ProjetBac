#ifndef _REQUEST_MAP_H_
#define _REQUEST_MAP_H_

enum requestHandlerList
{
	NO_REQUEST = -1,
	MED_REQUEST = 0,
	HUMAN_REQUEST,
	DOOR_REQUEST,
	LED_REQUEST,
	SENSOR_REQUEST,
	LOG_REQUEST,
};

enum
{
	Aucun = -1,
	Ecran = 0,
	CodeurRotatif,
	Leds,
	VerrouPorte,
	NFC,
	WEB,
	AlarmeMail,
	Capteurs,
	SwitchPorte,
	Alarme,
	debug,
} typeList;


class RequestMap
{
public:
	static void initRequestMap();
	static int getBroadcastTo(char * request);
	static int getDesignatedRequestHandler(char * request);

};

#endif // _REQUEST_MAP_H_
