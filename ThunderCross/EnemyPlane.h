// EnemyPlane.h: interface for the EnemyPlane class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENEMYPLANE_H__2FED6257_E5D6_4D3A_94BC_2CDC40987D57__INCLUDED_)
#define AFX_ENEMYPLANE_H__2FED6257_E5D6_4D3A_94BC_2CDC40987D57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

class CEnemyPlane  
{
public:
	IplImage* GetNowImage();
	int GetPosY();
	int GetPosX();
	CEnemyPlane(int width);
	CEnemyPlane();
	virtual ~CEnemyPlane();
	void Update();
	void TakeDamage(int damage);
	void Draw(IplImage* bg);
	void Move(int width,int height);
	bool NeedClear();
	int GetValue(){  return m_value; }
private:
	IplImage* m_img;
	int m_posx,m_posy;
	int m_dirx,m_diry;
	bool m_isClear;
	int m_hp;
	int m_value;
};

#endif // !defined(AFX_ENEMYPLANE_H__2FED6257_E5D6_4D3A_94BC_2CDC40987D57__INCLUDED_)
