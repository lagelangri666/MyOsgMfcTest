#pragma once
#include "OsgFile.h"
#include <list>
class COsgManager
{
private:
	std::list<COsgFile*> m_osgFileList;//���ļ�������
public:
	COsgManager(void);
	~COsgManager(void);
public:
	void AddOsgFile(COsgFile* osgfile);//���ģ���ļ�
	void RemoveOsgFile(COsgFile * const osgfile);//�Ƴ�ָ��ģ���ļ�
	void DeleteOsgFile(COsgFile * const osgfile);//ɾ��ָ��ģ���ļ�
	BOOL SwapOsgFile(COsgFile*const osgFile1,COsgFile*const osgFile2);//����ģ���ļ�
	std::list<COsgFile*> OsgFileList() const;
	void ClearOsgFileList();
};

