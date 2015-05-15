
// MyBrowser2.h : main header file for the MyBrowser2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMyBrowser2App:
// See MyBrowser2.cpp for the implementation of this class
//

class CMyBrowser2App : public CWinApp
{
public:
	CMyBrowser2App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyBrowser2App theApp;
