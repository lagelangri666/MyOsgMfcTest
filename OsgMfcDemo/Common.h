#pragma once
#include <string>
using namespace std;
//����ռ�
void* Malloc(int size);
//�ͷſռ�
void Free(void*p);
//���p=NULL,�������Malloc����Ϊ���򲻵���
void ToChars(CString str,char*&p);
//תΪstring ����
void ToString(CString str,string&cstr);
