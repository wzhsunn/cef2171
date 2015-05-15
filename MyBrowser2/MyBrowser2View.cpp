
// MyBrowser2View.cpp : implementation of the CMyBrowser2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MyBrowser2.h"
#endif

#include "MyBrowser2Doc.h"
#include "MyBrowser2View.h"

#include "MyCefApp.h"
#include "MyCefHandler.h"

#define  INVALID_HWND (HWND)INVALID_HANDLE_VALUE
namespace
{
	CefRefPtr<MyCefHandler> my_cef_handler;
	HWND application_message_window_handle = INVALID_HWND;
}
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyBrowser2View

IMPLEMENT_DYNCREATE(CMyBrowser2View, CView)

BEGIN_MESSAGE_MAP(CMyBrowser2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMyBrowser2View construction/destruction

CMyBrowser2View::CMyBrowser2View()
{
	// TODO: add construction code here

}

CMyBrowser2View::~CMyBrowser2View()
{
}

BOOL CMyBrowser2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMyBrowser2View drawing

void CMyBrowser2View::OnDraw(CDC* /*pDC*/)
{
	CMyBrowser2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMyBrowser2View printing

BOOL CMyBrowser2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyBrowser2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyBrowser2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMyBrowser2View diagnostics

#ifdef _DEBUG
void CMyBrowser2View::AssertValid() const
{
	CView::AssertValid();
}

void CMyBrowser2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyBrowser2Doc* CMyBrowser2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBrowser2Doc)));
	return (CMyBrowser2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMyBrowser2View message handlers


int CMyBrowser2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

//	void* sandbox_info = NULL;
//	CefMainArgs main_args(AfxGetApp()->m_hInstance);
//	CefRefPtr<MyCefApp> app(new MyCefApp);
//
//	int exit_code = CefExecuteProcess(main_args, app.get(), sandbox_info);
//	if (exit_code >= 0) {
//		// The sub-process has completed so return here.
//		return exit_code;
//	}
//	CefSettings settings;
//
//#if !defined(CEF_USE_SANDBOX)
//	settings.no_sandbox = true;
//#endif
//
//	CefInitialize(main_args, settings, app.get(), sandbox_info);
//
//	my_cef_handler = new MyCefHandler();
//
//	CefWindowInfo info;
//	info.SetAsChild(m_hWnd, CRect(0, 0, 1200, 1200));
//
//	CefBrowserSettings settings1;
//	CefBrowserHost::CreateBrowser(info, my_cef_handler.get(), CefString("http://www.baidu.com"), settings1, NULL);
	// TODO:  在此添加您专用的创建代码  
	CefMainArgs main_args(AfxGetApp()->m_hInstance);
	CefRefPtr<MyCefApp> app(new MyCefApp);

	if (CefExecuteProcess(main_args, app.get(), nullptr) == -1)
	{
		CefSettings settings;
		CefSettingsTraits::init(&settings);
		settings.multi_threaded_message_loop = true;
		CefInitialize(main_args, settings, app.get(), nullptr);

		my_cef_handler = new MyCefHandler();

		CefWindowInfo info;
		info.SetAsChild(m_hWnd, CRect(0, 0, 1200, 1200));

		CefBrowserSettings settings1;
		CefBrowserHost::CreateBrowser(info, my_cef_handler.get(), CefString("http://www.baidu.com"), settings1, NULL);
	}
	return 0;
}
