#pragma once
#include <list>
#include "OsgSceneCollection.h"
#include "OsgWindowCollection.h"
#include "OsgFileSource.h"
using namespace std;
class COsgManager
{
private:
	COsgFileSource * m_fileSource;//�ļ��б�
	COsgSceneCollection* m_sceneCollection;//��������
	COsgWindowCollection*m_windowCollection;//���ڼ���
public:
	COsgManager(void);
	~COsgManager(void);
public:
	COsgFileSource * FileSource() const;
	COsgSceneCollection* SceneCollection()const;
	COsgWindowCollection* WindowCollection() const;
};

