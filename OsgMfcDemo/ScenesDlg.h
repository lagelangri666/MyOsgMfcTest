#pragma once

// CScenesDlg �Ի���

class CScenesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CScenesDlg)
public:
	CScenesDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScenesDlg();

// �Ի�������
	enum { IDD = IDD_PANEL_SCENES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
};
