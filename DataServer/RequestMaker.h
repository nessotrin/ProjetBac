#ifndef _REQUEST_MAKER_H_
#define _REQUEST_MAKER_H_

#include "Server.h"

class RequestMaker
{
public:
	RequestMaker(Server * newServer);

private:
	Server * server;

};

#endif // _REQUEST_MAKER_H_
