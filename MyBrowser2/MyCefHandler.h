#pragma once

#include "include/cef_client.h"
#include "include/base/cef_lock.h"
#include <list>
class MyCefHandler :
	public CefClient,
	public CefContextMenuHandler,
	public CefDisplayHandler,
	public CefDownloadHandler,
	public CefDragHandler,
	public CefGeolocationHandler,
	public CefKeyboardHandler,
	public CefLifeSpanHandler,
	public CefLoadHandler,
	public CefRequestHandler   {

public:

	MyCefHandler();
	virtual	~MyCefHandler();

	// Provide access to the single global instance of this object.
	static MyCefHandler* GetInstance();

	CefRefPtr<CefBrowser> GetBrowser();
#pragma region CefClient  
	// since we are letting the base implementations handle all of the heavy lifting,  
	// these functions just return the this pointer  
	virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() OVERRIDE;
	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE;
	virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() OVERRIDE;
	virtual CefRefPtr<CefDragHandler> GetDragHandler() OVERRIDE;
	virtual CefRefPtr<CefGeolocationHandler> GetGeolocationHandler() OVERRIDE;
	virtual CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() OVERRIDE;
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE;
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE;
	virtual CefRefPtr<CefRequestHandler> GetRequestHandler() OVERRIDE;
#pragma endregion // CefClient  

#pragma region CefDownloadHandler  
	// this function is virtual and must be implemented; we do nothing in it, so downloading files won't work as the callback function isn't invoked  
	virtual void OnBeforeDownload(CefRefPtr<CefBrowser> browser, CefRefPtr<CefDownloadItem> download_item, const CefString& suggested_name, CefRefPtr<CefBeforeDownloadCallback> callback);
#pragma endregion // CefDownloadHandler   

#pragma region CefLifeSpanHandler  
	// cache a reference to the browser  
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
	// release the browser reference  
	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
#pragma endregion // CefLifeSpanHandler    

protected:
	// the browser reference  
	CefRefPtr<CefBrowser> browser;

	// Include the default reference counting implementation.  
	IMPLEMENT_REFCOUNTING(MyCefHandler);
	// Include the default locking implementation.  
	IMPLEMENT_LOCKING(MyCefHandler);


//	// CefClient methods:
//	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE{
//		return this;
//	}
//		virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE{
//		return this;
//	}
//		virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE{
//		return this;
//	}
//
//		// CefDisplayHandler methods:
//		virtual void OnTitleChange(CefRefPtr<CefBrowser> browser,
//		const CefString& title) OVERRIDE;
//
//	// CefLifeSpanHandler methods:
//	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
//	virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
//	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
//
//	// CefLoadHandler methods:
//	virtual void OnLoadError(CefRefPtr<CefBrowser> browser,
//		CefRefPtr<CefFrame> frame,
//		ErrorCode errorCode,
//		const CefString& errorText,
//		const CefString& failedUrl) OVERRIDE;
//
//	// Request that all existing browser windows close.
//	void CloseAllBrowsers(bool force_close);
//
//	bool IsClosing() const { return is_closing_; }
//
//private:
//	// List of existing browser windows. Only accessed on the CEF UI thread.
//	typedef std::list<CefRefPtr<CefBrowser> > BrowserList;
//	BrowserList browser_list_;
//
//	bool is_closing_;
//
//	// Include the default reference counting implementation.
//	IMPLEMENT_REFCOUNTING(MyCefHandler);
};


