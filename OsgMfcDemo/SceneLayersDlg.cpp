// SceneLayersDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OsgMfcDemo.h"
#include "SceneLayersDlg.h"
#include "afxdialogex.h"
#include "GroupSize.h"


// CSceneLayersDlg �Ի���

IMPLEMENT_DYNAMIC(CSceneLayersDlg, CDialogEx)

CSceneLayersDlg::CSceneLayersDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSceneLayersDlg::IDD, pParent)
{
	m_osgManager=NULL;
}

CSceneLayersDlg::~CSceneLayersDlg()
{
}

void CSceneLayersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_LAYERS, m_treeLayers);
}


BEGIN_MESSAGE_MAP(CSceneLayersDlg, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CSceneLayersDlg ��Ϣ�������


void CSceneLayersDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	GROUPSIZE(IDC_STA_GSRC,IDC_TREE_LAYERS);
}

void CSceneLayersDlg::BindingOsgManager( COsgManager* manager )
{
	m_osgManager=manager;
}

void CSceneLayersDlg::Refresh()
{
	CD3WindowDlg* d3windowdlg=m_osgManager->D3WindowsDlg()->SelectD3WindowDlg();
	if (d3windowdlg)
	{
		COsgScene* scene = d3windowdlg->OsgScene();
		list<COsgSceneFile*>* files = scene->OsgSceneFileList();
		HTREEITEM hRoot=m_treeLayers.GetRootItem();
		if (hRoot==NULL)
		{
			hRoot=m_treeLayers.InsertItem(_T("����ͼ��"));
		}
		if(m_treeLayers.ItemHasChildren(hRoot))
		{
			//��ú��ӽڵ�  
			HTREEITEM hChild=m_treeLayers.GetChildItem(hRoot);  
			//����hRoot��һ������к��ӽڵ㣬Ȼ��ɾ��
			while(hChild)  
			{  
				COsgSceneFile* file=(COsgSceneFile*)m_treeLayers.GetItemData(hChild);
				HTREEITEM item=m_treeLayers.GetNextItem(hChild,TVGN_NEXT);  
				m_treeLayers.DeleteItem(hChild);
				hChild=item;
			}  
		}
		for (list<COsgSceneFile*>::iterator it=files->begin();it!=files->end();it++)
		{
			HTREEITEM item=m_treeLayers.InsertItem((*it)->AliasName(),hRoot);
			m_treeLayers.SetItemData(item,(DWORD_PTR)(*it));
		}
		m_treeLayers.Expand(hRoot,TVE_EXPAND);
	}
	else
	{
		m_treeLayers.DeleteAllItems();
	}
}
