// EnemyFighterPlane.h: interface for the CEnemyFighterPlane class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENEMYFIGHTERPLANE_H__7115C050_F55F_443E_9994_92AD131BD561__INCLUDED_)
#define AFX_ENEMYFIGHTERPLANE_H__7115C050_F55F_443E_9994_92AD131BD561__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGameManager;
class CEnemyFighterPlane  
{
public:
	void TakeDamage(int damage);
	IplImage* GetNowImage();
	int GetPosY();
	int GetPosX();
	CEnemyFighterPlane();
	CEnemyFighterPlane(int width);
	virtual ~CEnemyFighterPlane();
	void Update();
	void Draw(IplImage* bg);
	void Move(int width,int height);
	void Attack(CGameManager* manager);
	bool NeedClear();
	int GetValue(){  return m_value; }
	bool m_isClear;
private:
	static IplImage* m_imgs[3];
	static IplImage* m_bullet;
	IplImage* m_img;
	int m_posx,m_posy;
	int m_dirx,m_diry;
	
	float m_atkPos;
	int m_atkCd;
	int m_timer;
	int m_bulletspeed;
	int m_preTime;
	int m_num;

	int m_hp;
	int m_value;
};

#endif // !defined(AFX_ENEMYFIGHTERPLANE_H__7115C050_F55F_443E_9994_92AD131BD561__INCLUDED_)
