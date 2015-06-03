#pragma once
#include "MyCefHandler.h"
#include "include/cef_command_line.h"
class MyGlobal
{
private:
	MyGlobal();
	MyGlobal(const MyGlobal&);
	MyGlobal& operator = (const MyGlobal&);
public:
	~MyGlobal();
	static MyGlobal& inst();
public:
	CefRefPtr<MyCefHandler> m_cefHandler;
	CefRefPtr<CefCommandLine>   m_commandLine;
};
