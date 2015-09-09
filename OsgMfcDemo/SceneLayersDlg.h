#pragma once
#include "OsgScene.h"
#include "OsgManager.h"
#include "afxcmn.h"


// CSceneLayersDlg �Ի���
extern class COsgManager;
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
private:
	COsgManager*m_osgManager;
public:
	void BindingOsgManager(COsgManager* manager);
	void Refresh();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CTreeCtrl m_treeLayers;
};
