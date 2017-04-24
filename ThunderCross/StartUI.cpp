// StartUI.cpp: implementation of the CStartUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StartUI.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStartUI::CStartUI()
{
	m_img = cvLoadImage(".\\resource\\startbg.jpg");
}

CStartUI::~CStartUI()
{
	cvReleaseImage(&m_img);
}
IplImage* CStartUI::GetImage()
{
	return m_img;
}
void CStartUI::Show()
{
	cvShowImage("ThunderCross",m_img);
}
