#pragma once


// CFileSourceDlg �Ի���

class CFileSourceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFileSourceDlg)
public:
	CFileSourceDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFileSourceDlg();

// �Ի�������
	enum { IDD = IDD_PANEL_SOURCE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
