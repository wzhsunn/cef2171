#pragma once




// ��ʼ��ȫ�������ж���
void AppInitCommandLine(int argc, const char* const* argv);


// ��ʼ��Cef������
void AppGetSettings(CefSettings& settings);

// ���ر��������ڵ�Ŀ¼
std::wstring AppGetAppPath();
// ���ر����������
//std::wstring AppGetAppName();
