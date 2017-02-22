#ifndef _LOGIN_PROTOCOL_H_
#define _LOGIN_PROTOCOL_H_

#include "Client.h" 

/***
Class object qui gère la connection des clients
***/
class LoginProtocol
{
public:
	bool doLogin(Client * client);

};

#endif // _LOGIN_PROTOCOL_H_
