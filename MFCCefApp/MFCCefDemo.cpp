
// MFCCefDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "MFCCefDemo.h"
#include "MFCCefDemoDlg.h"

#include "WebApp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCefDemoApp

BEGIN_MESSAGE_MAP(CMFCCefDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCCefDemoApp ����

CMFCCefDemoApp::CMFCCefDemoApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMFCCefDemoApp ����

CMFCCefDemoApp theApp;


// CMFCCefDemoApp ��ʼ��

BOOL CMFCCefDemoApp::InitInstance()
{
	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	//CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	//CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	// Cef ��ʼ��
	class CefAppEmplyImpl : public CefApp
	{
	public:
		CefAppEmplyImpl(){}
		~CefAppEmplyImpl(){}
	protected:
		IMPLEMENT_REFCOUNTING(CefAppEmplyImpl);
	};
	CefRefPtr<CefApp>		spApp(new /*CWebApp*/CefAppEmplyImpl);

	//CefMainArgs main_args(this->m_hInstance);
	CefMainArgs main_args(::GetModuleHandle(NULL));
	int exit_code = CefExecuteProcess(main_args, spApp.get(), NULL);
	if (exit_code >= 0) {
		// The sub-process has completed so return here.
		return exit_code;
	}

	CefRefPtr<CefCommandLine>			CommandLine;
	CefSettings							settings;
	CefSettingsTraits::init(&settings);
	settings.command_line_args_disabled = false;
	settings.single_process = false;
	//����֧��
	// http://blog.sina.com.cn/s/blog_dad2c54101019dav.html
	CefString(&settings.locale).FromASCII("zh-cn");
	//settings.multi_threaded_message_loop = CommandLine->HasSwitch("multi-threaded-message-loop");
	settings.multi_threaded_message_loop = true;

	CefInitialize(main_args, settings, spApp.get(), NULL);


	{
		// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
		// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
		//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
		INITCOMMONCONTROLSEX InitCtrls;
		InitCtrls.dwSize = sizeof(InitCtrls);
		// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
		// �����ؼ��ࡣ
		InitCtrls.dwICC = ICC_WIN95_CLASSES;
		InitCommonControlsEx(&InitCtrls);
		CWinApp::InitInstance();
		AfxEnableControlContainer();
	}



	{
		CMFCCefDemoDlg dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO:  �ڴ˷��ô����ʱ��
			//  ��ȷ�������رնԻ���Ĵ���
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO:  �ڴ˷��ô����ʱ��
			//  ��ȡ�������رնԻ���Ĵ���
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
			TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
		}
	}
	CefShutdown();

	//CMFCCefDemoDlg* pDlg = new CMFCCefDemoDlg;
	//m_pMainWnd = pDlg;
	//pDlg->Create(MAKEINTRESOURCE(IDD_MFCCEFDEMO_DIALOG), NULL);
	//m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
	//m_pMainWnd->UpdateWindow();
	//{
	//	// Run the CEF message loop. This function will block until the application
	//	// recieves a WM_QUIT message.
	//	CefRunMessageLoop();

	//	CefShutdown();
	//}

// 	// ɾ�����洴���� shell ��������
// 	if (pShellManager != NULL)
// 	{
// 		delete pShellManager;
// 	}

	

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CMFCCefDemoApp::ExitInstance()
{
	int nResult = CWinAppEx::ExitInstance();

	if (m_pMainWnd != NULL)
	{
		delete m_pMainWnd;
		m_pMainWnd = NULL;
	}

	return nResult;
}