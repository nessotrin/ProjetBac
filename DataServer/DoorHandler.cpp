#include "DoorHandler.h"

#include "Logger.h"

void DoorHandler::openDoor()
{
	Logger::log("OPENDOOR: TODO!!\n");
}

void DoorHandler::setDoorStatus(bool newDoorStatus)
{
	doorStatus = newDoorStatus;
}

bool DoorHandler::getDoorStatus()
{
	return doorStatus;
}
