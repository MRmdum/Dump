#include "TCPSocket.h"

TCPSocket::TCPSocket()
{
	mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mSocket == INVALID_SOCKET)
	{		
		cout << "Erreur initialisation socket [" << Sockets::GetError() << "]";
	}
}

TCPSocket::~TCPSocket()
{
	Sockets::ClosetheSocket(mSocket);
}

bool TCPSocket::Connect(const string& ipaddress, unsigned short port)
{
	sockaddr_in server;
	InetPton(AF_INET, (PCWSTR&)ipaddress, &server.sin_addr.s_addr);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	return connect(mSocket, (struct sockaddr*)&server, sizeof(server)) == 0;
}

bool TCPSocket::Send(string message)
{
	return send(mSocket, message.c_str(), (int)strlen(message.c_str()), 0);
}