// ScenesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OsgMfcDemo.h"
#include "ScenesDlg.h"
#include "afxdialogex.h"
#include "GroupSize.h"


// CScenesDlg �Ի���

IMPLEMENT_DYNAMIC(CScenesDlg, CDialogEx)

CScenesDlg::CScenesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScenesDlg::IDD, pParent)
{

}

CScenesDlg::~CScenesDlg()
{
}

void CScenesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CScenesDlg, CDialogEx)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SIZING()
END_MESSAGE_MAP()
// CScenesDlg ��Ϣ�������


int CScenesDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}


void CScenesDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	GROUPSIZE(IDC_STA_GSRC,IDC_TREE_SCENE);
}


void CScenesDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: �ڴ˴������Ϣ����������
}
