// D3WindowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OsgMfcDemo.h"
#include "D3WindowDlg.h"
#include "afxdialogex.h"


// CD3WindowDlg �Ի���

IMPLEMENT_DYNAMIC(CD3WindowDlg, CDialogEx)

CD3WindowDlg::CD3WindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CD3WindowDlg::IDD, pParent)
{
	this->SetBackgroundColor(RGB(255,255,255));
}

CD3WindowDlg::~CD3WindowDlg()
{
}

void CD3WindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CD3WindowDlg, CDialogEx)
END_MESSAGE_MAP()


// CD3WindowDlg ��Ϣ�������
