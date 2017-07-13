#include "stdafx.h"
#include "SockConnect.h"
#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <io.h>
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
char * CSockConnect::UnicodeToUTF8(const wchar_t *str)
{
	char * result;
	int textlen = 0;
	// wide char to multi char
	textlen = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
	result = (char *)malloc((textlen + 1) * sizeof(char));
	memset(result, 0, sizeof(char) * (textlen + 1));
	WideCharToMultiByte(CP_UTF8, 0, str, -1, result, textlen, NULL, NULL);
	return result;
}
SOCKET CSockConnect::GetSocket() {
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		wprintf(L"WSAStartup failed with error: %ld\n", iResult);
		//return 1;
		return 1;
	}

	//----------------------
	// Create a SOCKET for connecting to server
	SOCKET ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
		//return;
	}
	//----------------------
	// The sockaddr_in structure specifies the address family,
	// IP address, and port for the socket that is being bound.
	sockaddr_in addrServer;
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	//addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrServer.sin_port = htons(20131);

	//----------------------
	// Connect to server.
	iResult = connect(ConnectSocket, (SOCKADDR*)&addrServer, sizeof(addrServer));
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		printf("Unable to connect to server: %ld\n", WSAGetLastError());
		WSACleanup();
		throw "ERROR";
		return 1;
	}
}
 CSockConnect::CSockConnect() {
	//char buf[1024 + 1];
	////以一个无限循环的方式，不停地接收输入，发送到server
	//while (1)
	//{
	//	int randnum;
	//	randnum = rand();
	//	sprintf_s(buf, "%d", randnum);
	//	int count = strlen(buf);
	//	//int count = _read(0, buf, 1024);//从标准输入读入
	//	if (count <= 0)break;
	//	int sendCount, currentPosition = 0;
	//	while (count>0 && (sendCount = send(ConnectSocket, buf + currentPosition, count, 0)) != SOCKET_ERROR)
	//	{
	//		count -= sendCount;
	//		currentPosition += sendCount;
	//	}
	//	if (sendCount == SOCKET_ERROR)break;

	//	count = recv(ConnectSocket, buf, 1024, 0);
	//	if (count == 0)break;//被对方关闭
	//	if (count == SOCKET_ERROR)break;//错误count<0
	//	buf[count] = '\0';
	//	printf("%s", buf);
	//}
	////结束连接

}


CSockConnect::~CSockConnect()
{
	//closesocket(ConnectSocket);
	//WSACleanup();
	//sock->Close();
	//delete sock;
}
