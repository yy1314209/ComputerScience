// EnemyFighterPlane.cpp: implementation of the CEnemyFighterPlane class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EnemyFighterPlane.h"
#include "GameManager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IplImage* CEnemyFighterPlane::m_imgs[3] = {
	cvLoadImage(".\\resource\\enemy_3.png"), //移动快，射速慢
	cvLoadImage(".\\resource\\enemy_4.png"), //直线，射速快
	cvLoadImage(".\\resource\\enemy_5.png") //移动慢，射速中
}
;
IplImage* CEnemyFighterPlane::m_bullet = cvLoadImage(".\\resource\\bullet_5.png");
CEnemyFighterPlane::CEnemyFighterPlane()
{
}
CEnemyFighterPlane::CEnemyFighterPlane(int width)
{
	int key = rand() % 3;
	int dir;
	m_img = m_imgs[key];

	m_posx = rand() % (width - m_img->width);
	
	if(m_posx >= (width - m_img->width) / 2)
		dir = -1;
	else 
		dir = 1;
	m_posy = - m_img->height;
	m_isClear = false;
	m_timer = 0;
	m_preTime = 0;
	m_value = 100;
	if(key == 0)
	{
		m_atkCd = 2000;
		m_diry = 3;
		m_dirx = dir * 1;
		m_bulletspeed = 4;
		m_atkPos = 0.1;
		m_num = 3;
		m_hp = 600;
	}
	else if(key == 1)
	{
		m_atkCd = 800;
		m_dirx = 0;
		m_diry = 4;
		m_bulletspeed = 6;
		m_atkPos = 0;
		m_num = 1;
		m_hp = 600;
	}
	else
	{
		m_atkCd = 1000;
		m_diry = 2;
		m_dirx = dir * 1;
		m_bulletspeed = 5;
		m_atkPos = 0.1875;
		m_num = 2;
		m_hp = 600;
	}
}

CEnemyFighterPlane::~CEnemyFighterPlane()
{

}
void CEnemyFighterPlane::Update()
{
	m_timer += clock() - m_preTime;
	m_preTime = clock();
}
bool CEnemyFighterPlane::NeedClear()
{
	return m_isClear;
}
void CEnemyFighterPlane::Draw(IplImage* bg)
{
	if(m_isClear) return;

	m_isClear = true;
	if( m_posy < 0) m_isClear = false;
	for(int i = 0 ; i < m_img->height; i ++)
	{
		for(int j = 0 ; j < m_img->width; j ++)
		{
			int b = CV_IMAGE_ELEM( m_img, uchar, i, j*3);
			int g = CV_IMAGE_ELEM( m_img, uchar, i, j*3+1);
			int r = CV_IMAGE_ELEM( m_img, uchar, i, j*3+2);
			//rgb 178 132 91
			if( b > 85 && b < 95 && g > 128 && g < 135 && r > 175 && r < 180) continue;
			if(i + m_posy < 0 || i + m_posy >= bg->height || j + m_posx < 0 || j + m_posx >= bg->width) continue;
			m_isClear = false;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3) = b;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+1) = g;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+2) = r;
		}
	}
}
void CEnemyFighterPlane::Move(int width,int height)
{
	m_posx += m_dirx;
	m_posy += m_diry;
}

void CEnemyFighterPlane::Attack(CGameManager* manager)
{
	if(m_timer >= m_atkCd)
	{
		m_timer = 0;
		
		//攻击
		if(m_num == 1)
		{
			manager->CreatBullet(m_bullet,
				m_posx + (m_img->width - m_bullet->width) / 2,
				m_posy + m_img->height,
				0,m_bulletspeed,1,10);
		}
		else if(m_num == 2)
		{
			manager->CreatBullet(m_bullet,
				m_posx + m_img->width * m_atkPos - m_bullet->width / 2,
				m_posy + m_img->height,
				0,m_bulletspeed,1,10);
			manager->CreatBullet(m_bullet,
				m_posx + m_img->width - m_img->width * m_atkPos - m_bullet->width / 2,
				m_posy + m_img->height,
				0,m_bulletspeed,1,10);
		}
		else
		{
			manager->CreatBullet(m_bullet,
				m_posx + (m_img->width - m_bullet->width) / 2,
				m_posy + m_img->height,
				0,m_bulletspeed,1,10);
			manager->CreatBullet(m_bullet,
				m_posx + m_img->width * m_atkPos - m_bullet->width / 2,
				m_posy + m_img->height,
				0,m_bulletspeed,1,10);
			manager->CreatBullet(m_bullet,
				m_posx + m_img->width - m_img->width * m_atkPos - m_bullet->width / 2,
				m_posy + m_img->height,
				0,m_bulletspeed,1,10);
		}
	}
}

int CEnemyFighterPlane::GetPosX()
{
	return m_posx;
}

int CEnemyFighterPlane::GetPosY()
{
	return m_posy;
}

IplImage* CEnemyFighterPlane::GetNowImage()
{
	return m_img;
}

void CEnemyFighterPlane::TakeDamage(int damage)
{
	if(m_hp > damage)
		m_hp -= damage;
	else
	{
		m_hp = 0;
		m_isClear = true;
	}
}
