#pragma once
#include "OsgScene.h"
class COsgWindow
{
private:
	COsgScene*m_Scene;//�����ĳ���
public:
	COsgWindow(HWND hwnd,COsgScene*scene=NULL);
	~COsgWindow(void);
public:
	BOOL OpenScene(COsgScene*scene);
	BOOL CloseScene();
};

