#pragma once
class COsgFile
{
private:
    CString m_filePathName;//�ļ�����·��
public:
    COsgFile(void);
    COsgFile(CString filePathName);
    ~COsgFile(void);
public:
    CString FilePathName() const;//��ȡ·��
    void FilePathName(CString val);//����·��
	CString FileName();
public:
    BOOL EqualByFilePathName(const COsgFile&file) const;//ͨ���ļ����Ƚ�
    BOOL EqualByReference(const COsgFile&file) const;//���ñȽ�
    BOOL operator==(const COsgFile&file) const;
};

