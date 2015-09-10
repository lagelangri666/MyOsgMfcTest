#pragma once
#include "OsgScene.h"
#include "OsgRender.h"


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
	COsgRender* m_osgRender;
	CRenderingThread* m_thread;
public:
	COsgScene* OsgScene() const { return m_osgScene; }
	void OsgScene(COsgScene* val) { m_osgScene = val; }
	BOOL StartRender();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
