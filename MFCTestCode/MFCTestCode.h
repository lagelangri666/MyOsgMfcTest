
// MFCTestCode.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCTestCodeApp:
// �йش����ʵ�֣������ MFCTestCode.cpp
//

class CMFCTestCodeApp : public CWinApp
{
public:
	CMFCTestCodeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCTestCodeApp theApp;