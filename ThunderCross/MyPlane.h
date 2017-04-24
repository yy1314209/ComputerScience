// MyPlane.h: interface for the CMyPlane class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPLANE_H__DE6762A9_0E3A_4C3C_9482_69BD5AA70D0B__INCLUDED_)
#define AFX_MYPLANE_H__DE6762A9_0E3A_4C3C_9482_69BD5AA70D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StdAfx.h"
#include "HpBar.h"
class CGameManager;
class CMyPlane  
{
public:
	void Init();
	void LevelUp();
	IplImage* GetNowImage();
	int GetPosY();
	int GetPosX();
	void TakeDamage(int damage);
	void Update();
	
	void Draw(IplImage* bg);
	CMyPlane();
	virtual ~CMyPlane();
	void Move(int width,int height);
	void Attack(CGameManager* manager);
	bool isDead(){ return m_isClear;}
private:
	void ChangeLevel(int level);
	int m_hp;
	int m_level;
	int m_posx,m_posy;
	int m_speed;
	IplImage* m_imgs[3];
	IplImage* m_bullets[4];
	bool m_isClear;
	CHpBar m_hpbar;
};

#endif // !defined(AFX_MYPLANE_H__DE6762A9_0E3A_4C3C_9482_69BD5AA70D0B__INCLUDED_)
