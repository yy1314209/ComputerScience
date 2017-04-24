// Bullet.h: interface for the Bullet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BULLET_H__08F96D40_4AAC_4426_B76D_C14B8B3DEE11__INCLUDED_)
#define AFX_BULLET_H__08F96D40_4AAC_4426_B76D_C14B8B3DEE11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StdAfx.h"


class CBullet  
{
public:
	int GetAttack();
	void Destory();
	IplImage* GetImage();
	int GetPosY();
	int GetPosX();
	bool NeedClear();
	void Draw(IplImage* bg);
	void Move();
	CBullet();
	CBullet(IplImage* img,int posx,int posy,int dirx,int diry,int atk);
	virtual ~CBullet();
private:
	IplImage* m_img;
	int m_posx,m_posy;
	int m_dirx,m_diry;
	bool m_isClear;
	int m_atk;
};

#endif // !defined(AFX_BULLET_H__08F96D40_4AAC_4426_B76D_C14B8B3DEE11__INCLUDED_)
