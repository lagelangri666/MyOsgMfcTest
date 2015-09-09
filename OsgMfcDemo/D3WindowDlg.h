#pragma once
#include "OsgScene.h"
#include "MFC_OSG.h"


// CD3WindowDlg �Ի���

class CD3WindowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CD3WindowDlg)

public:
	CD3WindowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CD3WindowDlg();

// �Ի�������
	enum { IDD = IDD_3D_WINDOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	COsgScene* m_osgScene;
	cOSG* m_osg;
	CRenderingThread* m_thread;
public:
	COsgScene* OsgScene() const { return m_osgScene; }
	void OsgScene(COsgScene* val) { m_osgScene = val; }
	void InitOsg();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
