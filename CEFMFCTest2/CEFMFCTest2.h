
// CEFMFCTest2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCEFMFCTest2App:
// See CEFMFCTest2.cpp for the implementation of this class
//

class CCEFMFCTest2App : public CWinApp
{
public:
	CCEFMFCTest2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCEFMFCTest2App theApp;