#pragma once


// CD3WindowDlg �Ի���

class CD3WindowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CD3WindowDlg)

public:
	CD3WindowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CD3WindowDlg();

// �Ի�������
	enum { IDD = IDD_3D_WINDOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_d3WindowName;
public:
	CString D3WindowName() const { return m_d3WindowName; }
	void D3WindowName(CString val) { m_d3WindowName = val; }
};
