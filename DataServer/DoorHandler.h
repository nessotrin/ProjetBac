#ifndef _DOOR_HANDLER_H_
#define _DOOR_HANDLER_H_

class DoorHandler
{
public:
	void openDoor();
	void setDoorStatus(bool newDoorStatus);
	bool getDoorStatus();

private:
	bool doorStatus = false;

};

#endif // _DOOR_HANDLER_H_
