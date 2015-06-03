
// MFCCefDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "WebClient.h"



// CMFCCefDemoDlg �Ի���
class CMFCCefDemoDlg : public CDialogEx
{
// ����
public:
	CMFCCefDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCCEFDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	void	_LayoutRectCefControl(CRect & rc);
	void	_LayoutOtherControl(CRect & rc);


protected:
	CefRefPtr<CWebClient>		m_cefClient;

public:
	afx_msg void OnBnClickedBtnExecuteJs();
};
