#ifndef _MED_REQUEST_H_
#define _MED_REQUEST_H_

#include "MedHandler.h"

#include "Client.h"

class MedRequest
{
public:
	MedRequest(MedHandler * newMedHandler);
	void sendMedList(Client * client);

private:
	MedHandler * medHandler;
};

#endif // _MED_REQUEST_H_
