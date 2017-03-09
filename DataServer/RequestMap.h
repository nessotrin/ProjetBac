#ifndef _REQUEST_MAP_H_
#define _REQUEST_MAP_H_

enum handlerList
{
	NO_HANDLER = -1,
	MED_HANDLER = 0,
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
	static int getDesignatedHandler(char * request);

};

#endif // _REQUEST_MAP_H_
