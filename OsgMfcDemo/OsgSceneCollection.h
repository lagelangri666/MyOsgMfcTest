#pragma once
#include "OsgScene.h"
#include <list>
#include "ICollection.h"
using namespace std;
//�����б�
class COsgSceneCollection:public ICollection<COsgScene>
{
public:
	COsgSceneCollection(void);
	~COsgSceneCollection(void);
public:
};

