// BoomEffect.h: interface for the CBoomEffect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOMEFFECT_H__FD2A3192_43FE_4FA5_9C49_6D74E9EFAEA0__INCLUDED_)
#define AFX_BOOMEFFECT_H__FD2A3192_43FE_4FA5_9C49_6D74E9EFAEA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

class CBoomEffect  
{
public:
	bool NeedClear();
	void Draw(IplImage* bg);
	CBoomEffect();
	CBoomEffect(int posx,int posy,int speed);
	virtual ~CBoomEffect();
private:
	IplImage* m_imgs[4];
	int m_index;
	int m_speed;
	bool m_isClear;
	int m_posx,m_posy;
};

#endif // !defined(AFX_BOOMEFFECT_H__FD2A3192_43FE_4FA5_9C49_6D74E9EFAEA0__INCLUDED_)
