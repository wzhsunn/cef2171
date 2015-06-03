#pragma once




// 初始化全局命令行对象
void AppInitCommandLine(int argc, const char* const* argv);


// 初始化Cef的配置
void AppGetSettings(CefSettings& settings);

// 返回本程序所在的目录
std::wstring AppGetAppPath();
// 返回本程序的名字
//std::wstring AppGetAppName();
