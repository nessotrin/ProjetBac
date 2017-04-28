#include "BroadcastRequest.h"

#include "IOHelper.h"

#include "Logger.h"

BroadcastRequest::BroadcastRequest(LoginHandler * newLoginHandler, RequestHandler * requestHandler)
{
	loginHandler = newLoginHandler;
	
	requestHandler->addRequestEntry("RecupEtatPorte",this);
	requestHandler->addRequestEntry("PorteOuverte",this);
	requestHandler->addRequestEntry("PorteFermee",this);
	requestHandler->addRequestEntry("OuvrirPorte",this);
	requestHandler->addRequestEntry("FermerPorte",this);
	requestHandler->addRequestEntry("LEDOn",this);
	requestHandler->addRequestEntry("LEDOff",this);
	requestHandler->addRequestEntry("CapteurOn",this);
	requestHandler->addRequestEntry("CapteurOff",this);
	requestHandler->addRequestEntry("VerifierCoherencePoid",this);
	requestHandler->addRequestEntry("LumiereMontrerMed",this);
	requestHandler->addRequestEntry("EnvoyerMailAlarme",this);
	requestHandler->addRequestEntry("DeclencherAlarme",this);
	requestHandler->addRequestEntry("AllumerLumieresAlarme",this);
	requestHandler->addRequestEntry("MedecinConnecte",this);
	
	
	addBroadcastInformation("PorteOuverte",2, Ecran,WEB);
	addBroadcastInformation("PorteFermee",2, Ecran,WEB);
	
	Logger::log("DO BROADCAST DEFINITIONS !!!\n",ErrorLog);
}


	
void BroadcastRequest::handleRequest(char * request, Client * client)
{
	for(int i = 0 ; i < broadcastRequestDefinition.getCount() ; i++)
	{
		if(strlen(request) >= strlen(broadcastRequestDefinition.get(i).name) && memcmp(request,broadcastRequestDefinition.get(i).name, strlen(broadcastRequestDefinition.get(i).name)) == 0)
		{
			for(int j = 0 ; j < broadcastRequestDefinition.get(i).broadcastList.getCount() ; j++)
			{
				broadcastToType(request,broadcastRequestDefinition.get(i).broadcastList.get(j));
			}
		}
	}
}

void BroadcastRequest::broadcastToType(char * request, int type)
{
	Client * client;
	while(loginHandler->iterateOnClients(&client))
	{
		if(client->getType() == type)
		{
			IOHelper::sendRequest(client->getSocket(),request);
		}
	}
}

void BroadcastRequest::addBroadcastInformation(char * name, int broadcastCount ...)
{
	ListD<int> broadcastList;
	
	va_list arguments;                     // A place to store the list of arguments

	va_start ( arguments, broadcastCount );           // Initializing arguments to store all values after num

	for(int i = 0 ; i < broadcastCount ; i++)
	{
		broadcastList.add(va_arg ( arguments, int)); // Adds the next value in argument list to sum.
	}
	
	va_end ( arguments );  
	
	broadcastRequestDefinition.add(BroadcastInformation(name,broadcastList));
}