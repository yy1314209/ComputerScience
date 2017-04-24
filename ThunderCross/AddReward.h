// AddReward.h: interface for the CAddReward class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDREWARD_H__92B141BF_C739_4582_8621_9706F1ECD933__INCLUDED_)
#define AFX_ADDREWARD_H__92B141BF_C739_4582_8621_9706F1ECD933__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

class CMyPlane;
class CAddReward  
{
public:
	IplImage* GetImage(){ return m_img; }
	int GetPosY(){ return m_posy; }
	int GetPosX(){ return m_posx; }
	void Draw(IplImage* bg);
	void Effect(CMyPlane& myplane);
	CAddReward();
	CAddReward(int width);
	virtual ~CAddReward();
	void Move(int width,int height);
	bool isNeedClear(){ return m_isClear; }
private:
	IplImage* m_img;
	bool m_isClear;
	int m_posx,m_posy;
	int m_spx,m_spy;
};

#endif // !defined(AFX_ADDREWARD_H__92B141BF_C739_4582_8621_9706F1ECD933__INCLUDED_)
