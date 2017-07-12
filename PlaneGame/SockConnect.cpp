#include "stdafx.h"
#include "SockConnect.h"
#include <afxsock.h>

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
int CSockConnect::BuildConnect() {
	if (SendInfo(L"[####Connect####]") && ReceiveMessage() == "[####Connect Accept####]") {
		AfxMessageBox(L"OK");
	}
	return 0;

}
char * CSockConnect::ReceiveMessage() {
	return NULL;

}
int CSockConnect::SendHeartPackage() {
	return 0;

}
int CSockConnect::SendInfo(CString str) {
	while (1) {
		try {
			char* p;
			//wchar_t ss[100] = L"ÄãºÃÑ½";
			p = UnicodeToUTF8(str);
			sock->Send(p, strlen(p));
			delete p;
			return 1;
		}
		catch (int p) {
			return 0;
		}
	}

	//aSocket->Receive((void*)szRecValue, 1024);
	//if (strlen(szRecValue))
	//	AfxMessageBox((CString)szRecValue);
	
}
CSockConnect::CSockConnect()
{
	AfxSocketInit();
	IP = (CString)"127.0.0.1";
	Port = 8001;
	sock = new CSocket();
	if (!sock->Create()) {
		//sprintf(szMsg, "create faild: %d", aSocket.GetLastError());
		//AfxMessageBox((CString)"Connect Error");
		throw "Connect Error!";
	}
	if (sock->Connect(L"127.0.0.1", Port)) {
		if (!BuildConnect())
			throw L"Build Error!";

	}
	else {
		char szMsg[1024] = { 0 };
		AfxMessageBox(CString("Error"));
	}
}


CSockConnect::~CSockConnect()
{
	//delete sock;
}
