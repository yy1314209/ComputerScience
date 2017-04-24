// HpBar.h: interface for the CHpBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HPBAR_H__3B40D599_4307_47F5_8360_6FF3A173C72D__INCLUDED_)
#define AFX_HPBAR_H__3B40D599_4307_47F5_8360_6FF3A173C72D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StdAfx.h"

class CHpBar  
{
public:
	CHpBar();
	virtual ~CHpBar();
    void Draw(IplImage* bg);
	void SetPos(int posx,int posy){ m_posx = posx , m_posy = posy ; }
	void SetMaxHp(int hp) { m_maxHp = hp; }
	void SetNowHp(int hp) { m_nowHp = hp; }
private:
	IplImage* m_img;
	int m_posx;
	int m_posy;
	int m_maxHp;
	int m_nowHp;
};

#endif // !defined(AFX_HPBAR_H__3B40D599_4307_47F5_8360_6FF3A173C72D__INCLUDED_)
