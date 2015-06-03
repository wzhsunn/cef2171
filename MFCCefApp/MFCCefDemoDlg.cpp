
// MFCCefDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCCefDemo.h"
#include "MFCCefDemoDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCefDemoDlg �Ի���



CMFCCefDemoDlg::CMFCCefDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCCefDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCefDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCCefDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_WM_CLOSE()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_EXECUTE_JS, &CMFCCefDemoDlg::OnBnClickedBtnExecuteJs)
END_MESSAGE_MAP()


// CMFCCefDemoDlg ��Ϣ�������
CString		GetAppDir()
{
	CString path;
	GetModuleFileName(NULL, path.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	path.ReleaseBuffer();
	int pos = path.ReverseFind('\\');
	path = path.Left(pos + 1);
	return path;
}
BOOL CMFCCefDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	{
		CWnd * pWnd = this->GetDlgItem(IDC_STATIC);
		if (pWnd)
		{
			// 			pWnd->GetWindowRect(&rt);
			// 			this->ScreenToClient(&rt);
			// 			pWnd->DestroyWindow();
			// 			pWnd->Detach();
			//delete pWnd;

			pWnd->ShowWindow(SW_HIDE);
			pWnd = NULL;
		}

		CWnd* pEditJs = GetDlgItem(IDC_EDIT_JS);
		if (pEditJs)
		{
			pEditJs->SetWindowText(
				//_T("alert('��̨����js')")
				_T("//redirect Baidu \r\n")\
				_T("(function(){ \r\nlocation = 'http://www.baidu.com'; \r\nwindow.open('http://www.douban.com/');\r\n})();")\
				);
		}
	}

	CRect	rc/*(0, 0, 800, 600)*/;
	this->GetClientRect(rc);
	_LayoutRectCefControl(rc);
	_LayoutOtherControl(rc);

	// Cef Ƕ��
	m_cefClient = new CWebClient();

	CefWindowInfo info;
	info.SetAsChild(m_hWnd, rc);
	

	std::string strUIPath =
		//"http://www.baidu.com";

		"http://cn.bing.com";

		//GetAppDir() + "skin\\"
		//	// �������ϵ�Ƥ��
		//	"bootstrap\\"
		//		"gebo_admin\\index.htm"
		//		//"arctic-sunset\\index.html"				
		//		//"musik-music-html\\index.html"
		//	// ����C++��js����
		//	//"testapp.html"
		//;
	BOOL bRet = CefBrowserHost::CreateBrowser(
		info, 
		static_cast<CefRefPtr<CefClient> >(m_cefClient),
		strUIPath,
		CefBrowserSettings(),
		NULL
		);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCCefDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCCefDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCCefDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCCefDemoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	CRect rc;
	GetClientRect(rc);
	_LayoutRectCefControl(rc);
	_LayoutOtherControl(rc);
}


void CMFCCefDemoDlg::_LayoutRectCefControl(CRect & rc)
{
	if (m_cefClient.get())
	{
		CefRefPtr<CefBrowser> browser = m_cefClient->GetMainBrowser();
		if (browser)
		{
			CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();

			//_LayoutRectCefControl(rc);
			// ::SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, SWP_NOZORDER);  
			::MoveWindow(hwnd, rc.left, rc.top, rc.Width(), rc.Height(), TRUE);
		}
	}
}
void	CMFCCefDemoDlg::_LayoutOtherControl(CRect & rc)
{
	int nleft = 0;
	CRect rcControl = { 0 };
	CWnd * pEditJs = GetDlgItem(IDC_EDIT_JS);
	CWnd * pBtnJs = GetDlgItem(IDC_BTN_EXECUTE_JS);
	if (pEditJs)
	{
		rcControl.SetRect(0, 0, 300, 100);
		rcControl.MoveToXY(rc.left, rc.bottom - rcControl.Height());
		nleft += rcControl.Width();
		pEditJs->MoveWindow(&rcControl);
	}
	if (pBtnJs)
	{
		rcControl.SetRect(0, 0, 100, 20);
		rcControl.MoveToXY(nleft + 10, rc.bottom - rcControl.Height());
		pBtnJs->MoveWindow(&rcControl);
	}
}

void CMFCCefDemoDlg::OnBnClickedBtnExecuteJs()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	// https://code.google.com/p/chromiumembedded/wiki/JavaScriptIntegration
	if (m_cefClient.get())
	{
		CefRefPtr<CefBrowser> browser = m_cefClient->GetMainBrowser();
		if (browser)
		{
			CefRefPtr<CefFrame> frame = browser->GetMainFrame();
			if (frame)
			{
				std::wstring	wstrJS;
				CString		strJS;
				
				GetDlgItemText(IDC_EDIT_JS, strJS);
				// document.querySelector("#sb_form_q").value="C++";
				wstrJS = strJS;

				CefString cefstrJs;
				cefstrJs.FromWString(wstrJS);
				// wchar û������
				frame->ExecuteJavaScript(
					cefstrJs,
					frame->GetURL(),  
					0);
			}
		}
	}
}

