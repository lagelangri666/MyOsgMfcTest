
// OsgMfcDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "OsgManager.h"


// COsgMfcDemoDlg �Ի���
class COsgMfcDemoDlg : public CDialogEx
{
// ����
public:
	COsgMfcDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OSGMFCDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private:
	COsgManager m_osgManager;
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
	afx_msg void OnEditRect3d();
	afx_msg void OnOpen();
	afx_msg void OnImport();
};
