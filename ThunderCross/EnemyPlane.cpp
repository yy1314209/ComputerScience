// EnemyPlane.cpp: implementation of the EnemyPlane class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EnemyPlane.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CEnemyPlane::CEnemyPlane(int width)
{
	m_isClear = false;
	if(rand()%2)
		m_img = cvLoadImage(".\\resource\\enemy_1.png");
	else
		m_img = cvLoadImage(".\\resource\\enemy_2.png");
	m_posx = rand() % (width - m_img->width);
	m_posy = - m_img->height;
	m_dirx = (1 - 2 * (rand()%2)) * 2;
	m_diry = 2;
	m_hp = 200;
	m_value = 50;
}
CEnemyPlane::CEnemyPlane()
{
	m_hp = 200;
	if(rand()%2)
		m_img = cvLoadImage(".\\resource\\enemy_1.png");
	else
		m_img = cvLoadImage(".\\resource\\enemy_2.png");
}

CEnemyPlane::~CEnemyPlane()
{
	cvReleaseImage(&m_img);
}
void CEnemyPlane::Update()
{

}
bool CEnemyPlane::NeedClear()
{
	return m_isClear;
}
void CEnemyPlane::Draw(IplImage* bg)
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
void CEnemyPlane::Move(int width,int height)
{
	m_posx += m_dirx;
	m_posy += m_diry;
	if(m_posx < 0 )
	{
		m_dirx = - m_dirx;
		m_posx = 0;
	}
	else if(m_posx >= width - m_img->width)
	{
		m_posx = width - m_img->width - 1;
		m_dirx = - m_dirx;
	}
}

void CEnemyPlane::TakeDamage(int damage)
{
	if(m_hp > damage)
		m_hp -= damage;
	else
	{
		m_hp = 0;
		m_isClear = true;
	}
}

int CEnemyPlane::GetPosX()
{
	return m_posx;
}

int CEnemyPlane::GetPosY()
{
	return m_posy;
}

IplImage* CEnemyPlane::GetNowImage()
{
	return m_img;
}
