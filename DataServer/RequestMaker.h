#ifndef _REQUEST_MAKER_H_
#define _REQUEST_MAKER_H_

#include "LoginHandler.h"

class RequestMaker
{
public:
	RequestMaker(LoginHandler * newLoginHandler);

private:
	
	LoginHandler * loginHandler;

};

#endif // _REQUEST_MAKER_H_
