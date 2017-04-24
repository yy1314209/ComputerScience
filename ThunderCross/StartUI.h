// StartUI.h: interface for the CStartUI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTUI_H__F544D9E4_41BE_4449_A8CB_8964A7B06C47__INCLUDED_)
#define AFX_STARTUI_H__F544D9E4_41BE_4449_A8CB_8964A7B06C47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStartUI  
{
public:
	CStartUI();
	virtual ~CStartUI();
	IplImage* GetImage();
	void Show();
private:
	IplImage* m_img;

};

#endif // !defined(AFX_STARTUI_H__F544D9E4_41BE_4449_A8CB_8964A7B06C47__INCLUDED_)
