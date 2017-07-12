#pragma once
#include "CharsetConvert.h"
class CSocket;
class CSockConnect
{
protected:
	CString IP;
	int Port;
	CSocket* sock;
public:
	char * UnicodeToUTF8(const wchar_t * str);
	int BuildConnect();
	char * ReceiveMessage();
	int SendHeartPackage();
	int SendInfo(CString str);
	CSockConnect();
	virtual ~CSockConnect();
};

