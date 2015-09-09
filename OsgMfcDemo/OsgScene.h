#pragma once
#include <list>
#include "OsgSceneFile.h"
using namespace std;
class COsgScene
{
private:
	list<COsgSceneFile*>* m_osgSceneFileList;//�ļ��б�
	BOOL m_isNew;//�Ƿ����½���δ������
	BOOL m_isSaved;//�Ƿ��ѱ���
	CString m_Name;//��������
	static int NEW_COUNT;
public:
	COsgScene(BOOL isNew);
	COsgScene(CString name,BOOL isNew);
	~COsgScene(void);
public:
	CString Name() const { return m_Name; }
	void Name(CString val) { m_Name = val; }
	list<COsgSceneFile*>* OsgSceneFileList() const { return m_osgSceneFileList; }
	void AddOsgSceneFile(COsgSceneFile *osgFile);
};

