
// MFCCefDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCCefDemoApp: 
// �йش����ʵ�֣������ MFCCefDemo.cpp
//

class CMFCCefDemoApp : public CWinAppEx
{
public:
	CMFCCefDemoApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCCefDemoApp theApp;