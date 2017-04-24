// MyPlane.cpp: implementation of the CMyPlane class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyPlane.h"
#include "Timer.h"
#include "GameManager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyPlane::CMyPlane()
{
	m_imgs[0] = cvLoadImage(".\\resource\\airport_1.png");
	m_imgs[1] = cvLoadImage(".\\resource\\airport_2.png");
	m_imgs[2] = cvLoadImage(".\\resource\\airport_3.png");
	m_bullets[0] = cvLoadImage(".\\resource\\bullet_1.png");
	m_bullets[1] = cvLoadImage(".\\resource\\bullet_2.png");
	m_bullets[2] = cvLoadImage(".\\resource\\bullet_3.png");
	m_bullets[3] = cvLoadImage(".\\resource\\bullet_4.png");
	Init();
}
void CMyPlane::Init()
{
	m_speed = 5;
	ChangeLevel(0);
	m_posy = 500;
	m_posx = 300;
	m_isClear = false;
	m_hp = 100;
	m_hpbar.SetMaxHp(m_hp);
	m_hpbar.SetNowHp(m_hp);
	m_hpbar.SetPos(40,650);
}

CMyPlane::~CMyPlane()
{
	cvReleaseImage(&m_imgs[0]);
	cvReleaseImage(&m_imgs[1]);
	cvReleaseImage(&m_imgs[2]);
	cvReleaseImage(&m_bullets[0]);
	cvReleaseImage(&m_bullets[1]);
	cvReleaseImage(&m_bullets[2]);
	cvReleaseImage(&m_bullets[3]);
}
void CMyPlane::Move(int width,int height)
{
	if(GetAsyncKeyState('A') && 0x8000 && m_posx - m_speed >= 0)
		m_posx -= m_speed;
	if(GetAsyncKeyState('D') && 0x8000 && m_posx + m_imgs[m_level]->width + m_speed <= width)
		m_posx += m_speed;
	if(GetAsyncKeyState('W') && 0x8000 && m_posy-m_speed >= 0)
		m_posy -= m_speed;
	if(GetAsyncKeyState('S') && 0x8000 && m_posy + m_imgs[m_level]->height + m_speed <= height)
		m_posy += m_speed;
}
void CMyPlane::Attack(CGameManager* manager)
{
	if(GetAsyncKeyState('J') && 0x8000 )
	{
		if(m_level == 0 && CTimer::CheckTimer("MyPlaneAtk1") )
		{
			manager->CreatBullet(m_bullets[0],
				m_posx + (m_imgs[0]->width - m_bullets[0]->width)/2,
				m_posy - m_imgs[0]->height,
				0,-4,0,100
			);
			CTimer::Reset("MyPlaneAtk1");
		}
		else if(m_level == 1 && CTimer::CheckTimer("MyPlaneAtk2"))
		{
			manager->CreatBullet(m_bullets[1],
				m_posx + (m_imgs[1]->width - m_bullets[1]->width)/2,
				m_posy - m_imgs[1]->height + 25,
				0,-4,0,150
			);
			manager->CreatBullet(m_bullets[1],
				m_posx + m_imgs[1]->width*14/15 - m_bullets[1]->width/2,
				m_posy - m_imgs[1]->height + 25,
				0,-4,0,150
			);
			manager->CreatBullet(m_bullets[1],
				m_posx + m_imgs[1]->width/15- m_bullets[1]->width/2,
				m_posy - m_imgs[1]->height + 25,
				0,-4,0,150
			);
			CTimer::Reset("MyPlaneAtk2");
		}
		else if(m_level == 2 && CTimer::CheckTimer("MyPlaneAtk3"))
		{
			manager->CreatBullet(m_bullets[2],
				m_posx + (m_imgs[2]->width - m_bullets[2]->width)/2,
				m_posy - m_imgs[2]->height + 25,
				0,-4,0,250
			);
			CTimer::Reset("MyPlaneAtk3");
			if(CTimer::CheckTimer("MyPlaneAtk4"))
			{
				manager->CreatBullet(m_bullets[3],
				m_posx + 45 - m_bullets[3]->width/2,
				m_posy - m_imgs[2]->height + 25,
				0,-2,0,500
				);
				manager->CreatBullet(m_bullets[3],
				m_posx + 105 - m_bullets[3]->width/2,
				m_posy - m_imgs[2]->height + 25,
				0,-2,0,500
				);
				CTimer::Reset("MyPlaneAtk4");
			}
		}
	}
}

void CMyPlane::Draw(IplImage *bg)
{
	for(int i = 0 ; i < m_imgs[m_level]->height; i ++)
	{
		for(int j = 0 ; j < m_imgs[m_level]->width; j ++)
		{
			int b = CV_IMAGE_ELEM( m_imgs[m_level], uchar, i, j*3);
			int g = CV_IMAGE_ELEM( m_imgs[m_level], uchar, i, j*3+1);
			int r = CV_IMAGE_ELEM( m_imgs[m_level], uchar, i, j*3+2);
			//rgb 178 132 91
			if( b > 85 && b < 95 && g > 128 && g < 135 && r > 175 && r < 180) continue;

			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3) = b;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+1) = g;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+2) = r;
		}
	}
	m_hpbar.Draw(bg);
}

void CMyPlane::ChangeLevel(int level)
{
	m_level = level;
	CTimer::UnRegister("MyPlaneAtk1");
	CTimer::UnRegister("MyPlaneAtk2");
	CTimer::UnRegister("MyPlaneAtk3");
	CTimer::UnRegister("MyPlaneAtk4");
	if(level == 0){
		CTimer::Register("MyPlaneAtk1",200);
		CTimer::UnRegister("Buff");
	}
	else if(level == 1)
	{
		CTimer::Register("MyPlaneAtk2",300);
		CTimer::Register("Buff",10000);
	}
	else if(level == 2)
	{
		CTimer::Register("MyPlaneAtk3",200);
		CTimer::Register("MyPlaneAtk4",1800);
		CTimer::Reset("Buff");
	}
}

void CMyPlane::Update()
{
	if(CTimer::CheckTimer("Buff"))
	{
		ChangeLevel(0);
	}
}

void CMyPlane::TakeDamage(int damage)
{
	if(m_hp > damage)
	{
		m_hp -= damage;
		if(m_hp > 100) m_hp = 100;
		m_hpbar.SetNowHp(m_hp);
	}
	else
	{
		m_hp = 0;
		m_hpbar.SetNowHp(m_hp);
		m_isClear = true;
	}
}
IplImage* CMyPlane::GetNowImage()
{
	return m_imgs[m_level];
}
int CMyPlane::GetPosY()
{
	return m_posy;
}
int CMyPlane::GetPosX()
{
	return m_posx;
}

void CMyPlane::LevelUp()
{
	if(m_level != 2)
		ChangeLevel(m_level+1);
	else
		ChangeLevel(2);
}
