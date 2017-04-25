#include "DoorHandler.h"

#include "Logger.h"

void DoorHandler::openDoor()
{
	Logger::log("OPENDOOR: TODO!!\n",ErrorLog);
}

void DoorHandler::setDoorStatus(bool newDoorStatus)
{
	doorStatus = newDoorStatus;
}

bool DoorHandler::getDoorStatus()
{
	return doorStatus;
}
