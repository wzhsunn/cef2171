
// MyBrowser2View.h : interface of the CMyBrowser2View class
//

#pragma once


class CMyBrowser2View : public CView
{
protected: // create from serialization only
	CMyBrowser2View();
	DECLARE_DYNCREATE(CMyBrowser2View)

// Attributes
public:
	CMyBrowser2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMyBrowser2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in MyBrowser2View.cpp
inline CMyBrowser2Doc* CMyBrowser2View::GetDocument() const
   { return reinterpret_cast<CMyBrowser2Doc*>(m_pDocument); }
#endif

