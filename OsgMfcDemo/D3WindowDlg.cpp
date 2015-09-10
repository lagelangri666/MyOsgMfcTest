// D3WindowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OsgMfcDemo.h"
#include "D3WindowDlg.h"
#include "afxdialogex.h"
#include "Common.h"


// CD3WindowDlg �Ի���

IMPLEMENT_DYNAMIC(CD3WindowDlg, CDialogEx)

CD3WindowDlg::CD3WindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CD3WindowDlg::IDD, pParent)
{
	this->SetBackgroundColor(RGB(255,255,255));
	m_osgRender=NULL;
}

CD3WindowDlg::~CD3WindowDlg()
{
}

void CD3WindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CD3WindowDlg, CDialogEx)
	ON_WM_CREATE()
END_MESSAGE_MAP()

BOOL CD3WindowDlg::StartRender()
{
	if (m_hWnd==NULL)
	{
		return FALSE;
	}
	if (m_osgRender)
	{
		return TRUE;
	}
	m_osgRender=new COsgRender(m_hWnd);

	list<COsgSceneFile*>::iterator it=m_osgScene->OsgSceneFileList()->begin();
	COsgSceneFile* f=(*it);

	string str;
	ToString(f->OsgFile()->FilePathName(),str);

	m_osgRender->InitOSG(str);
	m_thread = new CRenderingThread(m_osgRender);
	m_thread->start();
	return TRUE;
}


// CD3WindowDlg ��Ϣ�������


int CD3WindowDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}
