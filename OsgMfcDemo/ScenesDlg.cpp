// ScenesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OsgMfcDemo.h"
#include "ScenesDlg.h"
#include "afxdialogex.h"
#include "GroupSize.h"


// CScenesDlg �Ի���

IMPLEMENT_DYNAMIC(CScenesDlg, CDialogEx)

CScenesDlg::CScenesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CScenesDlg::IDD, pParent)
{
	m_osgManager=NULL;
}

CScenesDlg::~CScenesDlg()
{
}

void CScenesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_SCENE, m_treeScenes);
}


BEGIN_MESSAGE_MAP(CScenesDlg, CDialogEx)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_NOTIFY(NM_RCLICK, IDC_TREE_SCENE, &CScenesDlg::OnNMRClickTreeScene)
	ON_COMMAND(ID_SCENE_NEW, &CScenesDlg::OnSceneNew)
	ON_COMMAND(ID_SCENE_OPEN, &CScenesDlg::OnSceneOpen)
END_MESSAGE_MAP()
// CScenesDlg ��Ϣ�������


int CScenesDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}


void CScenesDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	GROUPSIZE(IDC_STA_GSRC,IDC_TREE_SCENE);
}


void CScenesDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: �ڴ˴������Ϣ����������
}

void CScenesDlg::BindingOsgManager( COsgManager* manager)
{
	m_osgManager=manager;
}
void CScenesDlg::Refresh()
{
	if (m_osgManager&&m_treeScenes.GetSafeHwnd())
	{
		COsgSceneCollection* src=m_osgManager->SceneCollection();
		HTREEITEM hroot= m_treeScenes.GetRootItem();
		if (!hroot)
		{
			CString str=_T("���г���");
			hroot=m_treeScenes.InsertItem(str);
		}
		list<COsgScene*> temp;

		if(m_treeScenes.ItemHasChildren(hroot))
		{
			//��ú��ӽڵ�  
			HTREEITEM hChild=m_treeScenes.GetChildItem(hroot);  
			//����hRoot��һ������к��ӽڵ�  
			while(hChild)  
			{  
				COsgScene* scene=(COsgScene*)m_treeScenes.GetItemData(hChild);
				HTREEITEM item=m_treeScenes.GetNextItem(hChild,TVGN_NEXT);  
				if(!src->Contains(scene))
				{
					m_treeScenes.DeleteItem(hChild);
				}
				else
				{
					temp.push_back(scene);
				}
				hChild=item;
			}  
		}
		for (int i = 0; i < src->Count(); i++)
		{
			COsgScene*scene =src->Get(i);
			list<COsgScene*>::iterator it=temp.begin();
			BOOL ret=FALSE;
			while (it!=temp.end())
			{
				COsgScene*t=*it;
				if (t==scene)
				{
					ret= TRUE;
					break;
				}
				it++;
			}
			if (ret)
			{
				continue;
			}
			HTREEITEM hChild=m_treeScenes.InsertItem(scene->Name(),hroot); 
			m_treeScenes.SetItemData(hChild,(DWORD_PTR)scene);
			m_treeScenes.SelectItem(hChild);
		}
		m_treeScenes.Expand(hroot,TVE_EXPAND);
	}
}

void CScenesDlg::OnNMRClickTreeScene(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CPoint p;
	GetCursorPos(&p);
	m_treeScenes.ScreenToClient(&p);  

	CMenu m_Menu;  
	m_Menu.LoadMenu(IDR_MENU_SCENES);  
	CMenu *m_SubMenu = m_Menu.GetSubMenu(0);  

 	UINT uFlags;  
    HTREEITEM hItem = m_treeScenes.HitTest(p,&uFlags); 
	HTREEITEM hRoot=m_treeScenes.GetRootItem();
	if (hItem != NULL) 
	{  
		m_treeScenes.Select(hItem, TVGN_CARET);
	}
	if (hItem==hRoot||hItem==NULL)
	{
		m_SubMenu->EnableMenuItem(ID_SCENE_OPEN,MF_DISABLED);
		m_SubMenu->EnableMenuItem(ID_SCENE_DELETE,MF_DISABLED);
	}
	m_treeScenes.ClientToScreen(&p);
	m_SubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, this); 
}


void CScenesDlg::OnSceneNew()
{
	// TODO: �ڴ���������������
	COsgSceneCollection* scenes=m_osgManager->SceneCollection();
	scenes->Add(new COsgScene(TRUE));
	Refresh();
}


void CScenesDlg::OnSceneOpen()
{
	// TODO: �ڴ���������������
	HTREEITEM item=m_treeScenes.GetSelectedItem();
	if (item!=NULL&&item!=m_treeScenes.GetRootItem())
	{
		COsgScene* scene=(COsgScene*)m_treeScenes.GetItemData(item);
		m_osgManager->D3WindowsDlg()->OpenOrGetD3Window(scene);
	}
}


