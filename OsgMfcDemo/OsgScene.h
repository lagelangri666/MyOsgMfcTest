#pragma once
#include <list>
#include "OsgFile.h"
using namespace std;
class COsgScene
{
private:
	list<COsgFile*>m_osgFileList;//�ļ��б�
	BOOL m_isNew;//�Ƿ����½���δ������
	BOOL m_isSaved;//�Ƿ��ѱ���
	CString m_Name;//��������
public:
	COsgScene(void);
	~COsgScene(void);
};

