#include "StdAfx.h"
#include "mycefutil.h"


//#include "client_switches.h"
#include "myglobal.h"
#include "include/cef_command_line.h"
#include "client_switches.h"

// 初始化全局命令行对象
void AppInitCommandLine(int argc, const char* const* argv)
{
	MyGlobal::inst().m_commandLine = CefCommandLine::CreateCommandLine();
#if defined(OS_WIN)
	MyGlobal::inst().m_commandLine->InitFromString(::GetCommandLineW());
#else
	XGlobal::inst().CommandLine->InitFromArgv(argc, argv);
#endif
}


// 初始化Cef的配置
void AppGetSettings(CefSettings& settings)
{
	ASSERT(MyGlobal::inst().m_commandLine.get());
	if (!MyGlobal::inst().m_commandLine.get())
		return;

	std::wstring strAppPath = AppGetAppPath();

	std::wstring strCacheDir = strAppPath + L"caches";
	std::wstring strLogFile = strCacheDir + L"\\CefBrowser.log";

	settings.command_line_args_disabled = false;
	settings.single_process = false;
	CefString(&settings.cache_path) = strCacheDir;
	settings.remote_debugging_port = 9009;
	CefString(&settings.locale) = L"zh-CN";
	CefString(&settings.log_file) = strLogFile;
	settings.log_severity = LOGSEVERITY_ERROR;

#if defined(OS_WIN)
	settings.multi_threaded_message_loop = 
		MyGlobal::inst().m_commandLine->HasSwitch(cefclient::kMultiThreadedMessageLoop);
#endif
}


// 返回本程序所在的目录
std::wstring AppGetAppPath()
{
	CefString strCefAppPath;

	strCefAppPath = MyGlobal::inst().m_commandLine->GetCommandLineString();
	std::wstring strAppPath = strCefAppPath.ToWString();

	size_t pos = strAppPath.rfind(L'\\');
	if (pos != std::wstring::npos)
		strAppPath.resize(pos + 1);
	if (strAppPath.size() > 0 && strAppPath[0] == L'\"')
		strAppPath.erase(0, 1);

	return strAppPath;
}