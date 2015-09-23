#include "stdafx.h"
#include "PickEventHandle.h"
#include <osgFX/Scribe>

CPickEventHandle::CPickEventHandle(void)
{
	m_mouseX=-1;
	m_mouseY=-1;
}


CPickEventHandle::~CPickEventHandle(void)
{
}

bool CPickEventHandle::handle( const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
	osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
	if (!view) return false;
	switch(ea.getEventType())
	{
		//��갴��
	case(osgGA::GUIEventAdapter::PUSH):
		{
			//�������λ��
			m_mouseX = ea.getX();
			m_mouseY = ea.getY();
			//Select(view, ea.getX(), ea.getY());
			break;
		}
	case(osgGA::GUIEventAdapter::RELEASE):
		{
			if (m_mouseX==ea.getX() && m_mouseY==ea.getY())
			{
				//ִ�ж���ѡȡ
				Select(view, ea.getX(), ea.getY());
			}
			break;
		}
	default:
		break;
	}
	return false;
}

void CPickEventHandle::Select( osgViewer::View* view, float mouseX, float mouseY )
{
	osg::ref_ptr<osg::Node> node = new osg::Node();
	osg::ref_ptr<osg::Group> parent = new osg::Group();
	//����һ���߶ν�����⺯��
	osgUtil::LineSegmentIntersector::Intersections intersections;
	if (view->computeIntersections(mouseX, mouseY, intersections))
	{
		osgUtil::LineSegmentIntersector::Intersection intersection = *intersections.begin();
		osg::NodePath& nodePath = intersection.nodePath;
		//�õ�ѡ�������
		node = (nodePath.size()>=1)?nodePath[nodePath.size()-1]:0;
		parent = (nodePath.size()>=2)?dynamic_cast<osg::Group*>(nodePath[nodePath.size()-2]):0;
	}       

	//��һ�ָ�����ʾ����ʾ�����Ѿ���ѡ��
	if (parent.get() && node.get())
	{
		osg::ref_ptr<osgFX::Scribe> parentAsScribe = dynamic_cast<osgFX::Scribe*>(parent.get());
		if (!parentAsScribe)
		{
			//�������ѡ�񵽣�������ʾ
			osg::ref_ptr<osgFX::Scribe> scribe = new osgFX::Scribe();
			scribe->addChild(node.get());
			parent->replaceChild(node.get(),scribe.get());
		}
		else
		{
			//���û��û��ѡ�񵽣����Ƴ�������ʾ�Ķ���
			osg::Node::ParentList parentList = parentAsScribe->getParents();
			for(osg::Node::ParentList::iterator itr=parentList.begin();
				itr!=parentList.end();
				++itr)
			{
				(*itr)->replaceChild(parentAsScribe.get(),node.get());
			}
		}
	}
}
