#pragma once


// CSceneLayersDlg �Ի���

class CSceneLayersDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSceneLayersDlg)

public:
	CSceneLayersDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSceneLayersDlg();

// �Ի�������
	enum { IDD = IDD_PANEL_LAYERS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
