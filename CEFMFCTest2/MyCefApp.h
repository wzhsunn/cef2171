#pragma once
#include "include/cef_app.h"  
class MyCefApp :
	public CefApp,
	public CefBrowserProcessHandler
{
public:
	MyCefApp();
	virtual ~MyCefApp();

	// CefApp methods:
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler()
		OVERRIDE{ return this; }

		// CefBrowserProcessHandler methods:
	virtual void OnContextInitialized() OVERRIDE;

private:
	IMPLEMENT_REFCOUNTING(MyCefApp);
};

