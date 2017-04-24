// EndUI.h: interface for the CEndUI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENDUI_H__DCCFA6B2_9FF5_4F11_9BC3_1A2199009E65__INCLUDED_)
#define AFX_ENDUI_H__DCCFA6B2_9FF5_4F11_9BC3_1A2199009E65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StdAfx.h"
class CGameManager;
class CEndUI  
{
public:
	CEndUI();
	virtual ~CEndUI();
	IplImage* GetImage(){ return m_img; }
	void Show(CGameManager* manager);	
private:
	void ShowScoreNum(CGameManager* manager);
	IplImage* m_img;
	IplImage* m_nums[10];
	IplImage* m_levels[7];
	int m_levelscore[6];
	IplImage* m_clone;
	int m_speed;
	int m_length;
};

#endif // !defined(AFX_ENDUI_H__DCCFA6B2_9FF5_4F11_9BC3_1A2199009E65__INCLUDED_)
