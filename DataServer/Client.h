#ifndef _CLIENT_H_
#define _CLIENT_H_

class Client
{
public:
	Client( int newSocket);
	int getSocket();
private:
	int socket;

};

#endif // _CLIENT_H_
