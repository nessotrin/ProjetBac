#ifndef _BROADCAST_REQUEST_H_
#define _BROADCAST_REQUEST_H_

#include "ServerHelper.h"

#include "RequestCallbackable.h"

#include "RequestHandler.h"

#include "LoginHandler.h"

enum TypeList
{
	Ecran = 0,
	Codeur,
	Leds,
	Verrou,
	SwitchPorte,
	Carte,
	WEB,
	Alarme,
	SMS,
	Poids,
	debug,
};

class BroadcastInformation
{
public:
	
	BroadcastInformation(char * newName, ListD<int> newBroadcastList)
	{
		name = newName;
		broadcastList = newBroadcastList;
	}
	char * name;
	ListD<int> broadcastList;
};


class BroadcastRequest : public RequestCallbackable
{
public:
	BroadcastRequest(LoginHandler * newLoginHandler, RequestHandler * requestHandler);
	
	void handleRequest(char * request, Client * client);


private:

	void broadcastToType(char * request, int type);
	void addBroadcastInformation(char * name, int broadcastCount ...);

	LoginHandler * loginHandler;
	ListD<BroadcastInformation> broadcastRequestDefinition;
};

#endif // _BROADCAST_REQUEST_H_
