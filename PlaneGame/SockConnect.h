#pragma once
#include "CharsetConvert.h"


class CSockConnect
{
protected:
	CString IP;
	int Port;
public:
	static char * UnicodeToUTF8(const wchar_t * str);
	SOCKET GetSocket();
	//void SendAMessage(CString str);
	//static UINT MyThreadProc(LPVOID pParam);
	CSockConnect();
	virtual ~CSockConnect();
};

