// FileSourceDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OsgMfcDemo.h"
#include "FileSourceDlg.h"
#include "afxdialogex.h"
#include "GroupSize.h"


// CFileSourceDlg �Ի���

IMPLEMENT_DYNAMIC(CFileSourceDlg, CDialogEx)

CFileSourceDlg::CFileSourceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileSourceDlg::IDD, pParent)
{
}

CFileSourceDlg::~CFileSourceDlg()
{
}

void CFileSourceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFileSourceDlg, CDialogEx)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CFileSourceDlg ��Ϣ�������


void CFileSourceDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: �ڴ˴������Ϣ����������
	GROUPSIZE(IDC_STA_GSRC,IDC_TREE_SOURCE);
}


void CFileSourceDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: �ڴ˴������Ϣ����������
}


int CFileSourceDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}
