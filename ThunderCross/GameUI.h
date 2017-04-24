// GameUI.h: interface for the CGameUI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEUI_H__DFD8958A_531D_4F38_9A5E_B20B1B095CD0__INCLUDED_)
#define AFX_GAMEUI_H__DFD8958A_531D_4F38_9A5E_B20B1B095CD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StdAfx.h"

class CGameManager;
class CGameUI  
{
public:
	CGameUI();
	virtual ~CGameUI();
	IplImage* GetImage();
	void Show(CGameManager* manager);	
private:
	void ShowScoreNum(CGameManager* manager);
	void SetBgImage();
	IplImage* m_img;
	IplImage* m_nums[10];
	IplImage* m_clone;
	int m_speed;
	int m_length;
};

#endif // !defined(AFX_GAMEUI_H__DFD8958A_531D_4F38_9A5E_B20B1B095CD0__INCLUDED_)
