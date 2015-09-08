
// OsgMfcDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OsgMfcDemo.h"
#include "OsgMfcDemoDlg.h"
#include "afxdialogex.h"
#include "OsgFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
    public:
        CAboutDlg();

// �Ի�������
        enum { IDD = IDD_ABOUTBOX };

    protected:
        virtual void DoDataExchange(CDataExchange *pDX);    // DDX/DDV ֧��

// ʵ��
    protected:
        DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COsgMfcDemoDlg �Ի���



COsgMfcDemoDlg::COsgMfcDemoDlg(CWnd *pParent /*=NULL*/)
    : CDialogEx(COsgMfcDemoDlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COsgMfcDemoDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COsgMfcDemoDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_COMMAND(ID_EDIT_RECT3D, &COsgMfcDemoDlg::OnEditRect3d)
    ON_COMMAND(ID_OPEN, &COsgMfcDemoDlg::OnOpen)
    ON_COMMAND(ID_IMPORT, &COsgMfcDemoDlg::OnImport)
	ON_WM_SIZING()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// COsgMfcDemoDlg ��Ϣ�������

BOOL COsgMfcDemoDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // ��������...���˵�����ӵ�ϵͳ�˵��С�

    // IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu *pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);		// ����Сͼ��

    ShowWindow(SW_MAXIMIZE);

    // TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_leftWidth=250;

	m_fileSourceDlg.Create(IDD_PANEL_SOURCE,this);
	m_fileSourceDlg.ShowWindow(SW_SHOW);

	m_d3WindowsDlg.Create(IDD_3D_WINS,this);
	m_d3WindowsDlg.ShowWindow(SW_SHOW);

	m_scenesDlg.Create(IDD_PANEL_SCENES,this);
	m_scenesDlg.ShowWindow(SW_SHOW);

	m_sceneLayersDlg.Create(IDD_PANEL_LAYERS,this);
	m_sceneLayersDlg.ShowWindow(SW_SHOW);

	m_osgManager.FileSourceDlg(&m_fileSourceDlg);
	m_osgManager.ScenesDlg(&m_scenesDlg);
	m_osgManager.D3WindowsDlg(&m_d3WindowsDlg);
	m_osgManager.SceneLayersDlg(&m_sceneLayersDlg);

	m_fileSourceDlg.BindingOsgManager(&m_osgManager);
	m_scenesDlg.BindingOsgManager(&m_osgManager);
	m_d3WindowsDlg.BindingOsgManager(&m_osgManager);
	m_sceneLayersDlg.BindingOsgManager(&m_osgManager);

	UpdatePosition();

    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COsgMfcDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
        CDialogEx::OnSysCommand(nID, lParam);
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COsgMfcDemoDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
        CDialogEx::OnPaint();
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COsgMfcDemoDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

//��
void COsgMfcDemoDlg::OnOpen()
{
    // TODO: �ڴ���������������
    CFileDialog dialog(TRUE,_T(".osg"),NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                       _T("ģ���ļ�|*.osg;*.osgt;*.ive|�����ļ�|*.*||"),NULL);
    if(dialog.DoModal()==IDOK)
    {
        CString fileName=dialog.GetPathName();
		if (m_osgManager.FileSource()->Contains(fileName))
		{
			MessageBox(_T("�Ѵ��ڸ��ļ���"));
			return;
		}
        COsgFile *osg=new COsgFile(fileName);
        m_osgManager.FileSource()->Add(osg);
		m_fileSourceDlg.Refresh();
    }
}
//����
void COsgMfcDemoDlg::OnImport()
{
    // TODO: �ڴ���������������

}

void COsgMfcDemoDlg::OnEditRect3d()
{
    // TODO: �ڴ���������������
	
}




void COsgMfcDemoDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: �ڴ˴������Ϣ����������
}


void COsgMfcDemoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: �ڴ˴������Ϣ����������
	UpdatePosition();
}

void COsgMfcDemoDlg::UpdatePosition()
{
	RECT rect;
	this->GetClientRect(&rect);
	int height=rect.bottom-rect.top;
	//�����ļ���Դ�б�λ��
	if (m_fileSourceDlg.GetSafeHwnd()!=NULL)
	{
		//RECT srcRect;
		//m_fileSourceDlg.GetClientRect(&srcRect);
		m_fileSourceDlg.MoveWindow(0,0,m_leftWidth,height*2/5);
	}
	if (m_scenesDlg.GetSafeHwnd()!=NULL)
	{
		m_scenesDlg.MoveWindow(0,height*2/5,m_leftWidth,height/5);
	}

	if (m_sceneLayersDlg.GetSafeHwnd()!=NULL)
	{
		m_sceneLayersDlg.MoveWindow(0,height*3/5,m_leftWidth,height*2/5);
	}

	if (m_d3WindowsDlg.GetSafeHwnd()!=NULL)
	{
		m_d3WindowsDlg.MoveWindow(m_leftWidth+5,0,rect.right-rect.left-m_leftWidth-5,height);
	}
}
