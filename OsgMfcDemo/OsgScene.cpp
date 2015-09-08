#include "stdafx.h"
#include "OsgScene.h"


COsgScene::COsgScene(BOOL isNew)
{
	m_isNew=isNew;
	m_Name="�½�����";
	m_Name.Format(_T("�½�����%d"),NEW_COUNT++);
}

COsgScene::COsgScene( CString name,BOOL isNew )
{
	m_isNew=isNew;
	if (name.Trim().Compare(_T(""))==0)
	{
		m_Name="�½�����";
		m_Name.Format(_T("�½�����%d"),NEW_COUNT++);
	}
	m_Name=name;
}


COsgScene::~COsgScene(void)
{
}

int COsgScene::NEW_COUNT=1;
