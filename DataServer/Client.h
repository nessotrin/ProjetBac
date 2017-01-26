#ifndef _CLIENT_H_
#define _CLIENT_H_


/***
Class objet qui représente un client, stock son socket, son type et son état 'debug'
Elle permet d'envoyer et de recevoir des données à travers le socket
***/

class Client
{
public:
	Client( int newSocket);
	
	int getSocket();
	
	void setType(int newType);
	int getType();

	void setDebug(bool newDebug);
	bool getDebug();
	
	int sendData(unsigned char * data, int size);
	int receiveData(unsigned char * data, int maxSize);

private:
	int socket;
	int type;
	bool debug;

};

#endif // _CLIENT_H_
