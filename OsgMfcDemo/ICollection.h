#pragma once
#include <list>
using namespace std;
template <class T>
class ICollection
{
private:
	typedef void (*EventHandle)(T*item);
	typedef void (*SwapEventHandle)(T*item1,T*item2);
	typedef void (*ClearEventHandle)(void);
protected:
	BOOL m_onDestoryItems;
	list<T*> m_List;
public:
	ICollection(void);
	~ICollection(void);
public:
	void virtual Add(T*item);//��Ӷ���
	void virtual Remove(T*item);//�Ƴ�����
	BOOL virtual Contains(T*item);//�Ƿ��������
	BOOL virtual Swap(T*item1,T*item2);//��������˳��
	void virtual Clear();//��ռ���
	void virtual Delete(T*item);//�Ƴ����϶��󣬲����գ�ʹ��delete��
	void virtual DeleteAll();//�Ƴ����ж��󣬲����գ�ʹ��delete��
	list<T*> Collection() const;//��ȡ���϶���
	int Count() const;//���ϸ���
	T*Get(int index=0);//ȡ��ָ��λ�ö���
	T*operator[](int index) const;
	BOOL OnDestoryItems() const;//��ȡ�Ƿ�����ʱɾ������
	void OnDestoryItems(BOOL val);//�����Ƿ�ɾ��ʱɾ������
public:
	EventHandle Added;
	EventHandle Removed;
	ClearEventHandle Cleared; 
	SwapEventHandle Swaped;
};

template <class T>
BOOL ICollection<T>::Contains( T*item )
{
	list<T*>::iterator it=m_List.begin();
	while (it!=m_List.end())
	{
		T*t=*it;
		if (t==item)
		{
			return TRUE;
		}
		it++;
	}
	return FALSE;
}

template <class T>
int ICollection<T>::Count() const
{
	return m_List.size();
}

template <class T>
T* ICollection<T>::operator[]( const int index ) const
{
	return Get(index);
}

template <class T>
T* ICollection<T>::Get( int index/*=0*/ )
{
	std::list<T*>::iterator it=m_List.begin();
	int i=0;
	while (it!=m_List.end())
	{
		if (i==index)
		{
			T* t=*it;
			return t;
		}
		it++;
		i++;
	}
	return NULL;
}

template <class T>
ICollection<T>::ICollection( void )
{
	m_List.clear();
	Added=NULL;
	Removed=NULL;
	Cleared=NULL;
	Swaped=NULL;
}

template <class T>
ICollection<T>::~ICollection( void )
{
	if (m_onDestoryItems)
	{
		DeleteAll();
	}
	else
	{
		Clear();
	}
}

template <class T>
void ICollection<T>::Add( T*item )
{
	m_List.push_back(item);
	if (Added!=NULL)
	{
		Added(item);
	}
}

template <class T>
void ICollection<T>::Remove( T*item )
{
	m_List.remove(item);
	if (Removed!=NULL)
	{
		Removed(item);
	}
}

template <class T>
BOOL ICollection<T>::Swap( T*item1,T*item2 )
{
	if(item1==item2)
	{
		return FALSE;
	}
	int i = -1;
	int i1 = -1;
	int i2 = -1;
	for(std::list<T*>::iterator it = m_List.begin(); it != m_List.end(); it++)
	{
		i++;
		if(i1 == -1 && *it==item1)
		{
			i1 = i;
			if(i1 != -1 && i2 != -1)
			{
				break;
			}
		}
		else if(i2 == -1 && *it==item2)
		{
			i2 = i;
			if(i1 != -1 && i2 != -1)
			{
				break;
			}
		}
	}
	if(i1 == -1 || i2 == -1)
	{
		return FALSE;
	}
	i = -1;
	//����
	for(std::list<T*>::iterator it = m_List.begin(); it != m_List.end();)
	{
		i++;
		if (i1<i2)
		{
			if (i==i1)
			{
				it = m_List.insert(it,1,item2);//��item1ǰ����item2
				it++;
				it = m_List.erase(it);
				i++;
				if (i!=i2)
				{
					continue;
				}
			}
			if(i==i2)
			{
				it = m_List.insert(it,1,item1);//��item2ǰ����item1
				it++;
				m_List.erase(it);
				break;
			}
		}
		else if(i1>i2)
		{
			if (i==i2)
			{
				it = m_List.insert(it,1,item1);//��item2ǰ����item1
				it++;
				it = m_List.erase(it);
				i++;
				if (i!=i1)
				{
					continue;
				}
			}
			else if(i==i1)
			{
				it = m_List.insert(it,1,item2);//��item1ǰ����item2
				it++;
				m_List.erase(it);
				break;
			}
		}
		it++;
	}
	if (Swaped!=NULL)
	{
		Swaped(item1,item2);
	}
	return TRUE;
}

template <class T>
void ICollection<T>::Clear()
{
	m_List.clear();
	if (Cleared!=NULL)
	{
		Cleared();
	}
}

template <class T>
list<T*> ICollection<T>::Collection() const
{
	return m_List;
}

template <class T>
void ICollection<T>::Delete( T*item )
{
	if (item!=NULL)
	{
		Remove(item);
		delete item;
	}
}

template <class T>
void ICollection<T>::DeleteAll()
{
	list<T*>::iterator it=m_List.begin();
	while (it!=m_List.end())
	{
		T*t=*it;
		it=m_List.erase(it);
		delete t;
	}
	if (Cleared!=NULL)
	{
		Cleared();
	}
}
template <class T>
BOOL ICollection<T>::OnDestoryItems() const
{
	return m_onDestoryItems;
}

template <class T>
void ICollection<T>::OnDestoryItems( BOOL val )
{
	m_onDestoryItems = val;
}

