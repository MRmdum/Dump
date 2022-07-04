#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include "Sockets.h"
#include <iostream>

using namespace std;

#include <string>

class TCPSocket
{
public:
	TCPSocket();
	~TCPSocket();

	bool Connect(const std::string& ipaddress, unsigned short port);
	bool Send(string message);

public:
	SOCKET mSocket;
};

#endif // TCPSOCKET_HPP

