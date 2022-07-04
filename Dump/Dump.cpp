//#define WIN32_LEAN_AND_MEAN
//
//#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <stdio.h>
//
//// Need to link with Ws2_32.lib
//#pragma comment(lib, "ws2_32.lib")


#ifdef _WIN32
#ifndef _WIN32_WINNT
#endif
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
  /* Assume that any non-Windows platform uses POSIX-style sockets instead. */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>  /* Needed for getaddrinfo() and freeaddrinfo() */
#include <unistd.h> /* Needed for close() */
#endif

#include "TCPSocket.h"

//#include <curl/curl.h>


/*class files*/
#include "HttpExtractor.h"
#include "TxtExtractor.h"
#include "SqliteDumper.h"
#include "Dump.h"
/*---*/

using namespace std;

int main()
{
    Extractor* extractor = new HttpExtractor;
    SqliteDumper dump = SqliteDumper(extractor);
    map<string,string> parameters;
    dump.dump(parameters);




    //(*dump).enumerateTables();
    //SqlDump dump = SqlDump("db.sqlite3");
    

    /*SqlDump* dump2 = SqlDump::GetInstance();
    (*dump2).WritteTable();*/
    //(*dump2).DestroyInstance();

   /* WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);

    TCPSocket sock = TCPSocket();

    string ip = "127.0.0.1";
    unsigned short port = 8000;

    if (!sock.Connect(ip, port))
        cout << "connexion reussi";
    else
        cout << "connexion echouee";

    if (!sock.Send("Test socket"))
        cout <<"envoie effectue";
    else
        cout<<"envoie echoue";

    sock.~TCPSocket();*/



    //SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    ////if (sock == INVALID_SOCKET) cout << "socket invalid" << endl;

    ////def server's connexion
    //sockaddr_in server;
    //const char* ipaddress = ip.c_str();
    //InetPton(AF_INET, (PCWSTR)(ipaddress), &server.sin_addr.s_addr);

    //server.sin_family = AF_INET;
    //server.sin_port = htons(6455);

    //if (connect(sock.mSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    //{
    //    std::cout << "Erreur connection : " << WSAGetLastError() << std::endl;
    //    return 0;
    //}
    //std::cout << "Socket connecte !" << std::endl;

    ////tentative d'envoi
    //string sendbuf = "Test Socket";
    //if (send(sock.mSocket, sendbuf.c_str(), (int)strlen(sendbuf.c_str()), 0))
    //    cout << "echec connexion";
    //else
    //    cout << "connexion";
    //

    //closesocket(sock.mSocket);
    //WSACleanup();
}

