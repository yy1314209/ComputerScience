// cBuffReward.h: interface for the cBuffReward class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CBUFFREWARD_H__14DD463F_4689_481A_A3A2_8495F206493C__INCLUDED_)
#define AFX_CBUFFREWARD_H__14DD463F_4689_481A_A3A2_8495F206493C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StdAfx.h"

class CMyPlane;
class cBuffReward  
{
public:
	cBuffReward();
	cBuffReward(int width);
	virtual ~cBuffReward();
	IplImage* GetImage(){ return m_img; }
	int GetPosY(){ return m_posy; }
	int GetPosX(){ return m_posx; }
	void Draw(IplImage* bg);
	void Effect(CMyPlane& myplane);
	void Move(int width,int height);
	bool isNeedClear(){ return m_isClear; }
private:
	IplImage* m_img;
	bool m_isClear;
	int m_posx,m_posy;
	int m_spx,m_spy;
};

#endif // !defined(AFX_CBUFFREWARD_H__14DD463F_4689_481A_A3A2_8495F206493C__INCLUDED_)
