// Bullet.cpp: implementation of the Bullet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bullet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBullet::CBullet()
{
	m_isClear = false;
}
CBullet::CBullet(IplImage* img,int posx,int posy,int dirx,int diry,int atk)
{
	m_img = img;
	m_posx = posx;
	m_posy = posy;
	m_dirx = dirx;
	m_diry = diry;
	m_atk = atk;
	m_isClear = false;
}
CBullet::~CBullet()
{

}

void CBullet::Move()
{
	m_posx += m_dirx;
	m_posy += m_diry;
}
void CBullet::Draw(IplImage *bg)
{
	if(m_isClear) return;
	m_isClear = true;
	for(int i = 0 ; i < m_img->height; i ++)
	{
		for(int j = 0 ; j < m_img->width; j ++)
		{
			int b = CV_IMAGE_ELEM( m_img, uchar, i, j*3);
			int g = CV_IMAGE_ELEM( m_img, uchar, i, j*3+1);
			int r = CV_IMAGE_ELEM( m_img, uchar, i, j*3+2);
			//rgb 178 132 91
			if( b > 80 && b < 100 && g > 125 && g < 140 && r > 170 && r < 185) continue;
			if(i + m_posy < 0 || i + m_posy >= bg->height || j + m_posx < 0 || j + m_posx >= bg->width) continue;
			m_isClear = false;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3) = b;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+1) = g;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+2) = r;
		}
	}
}

bool CBullet::NeedClear()
{
	return m_isClear;
}

int CBullet::GetPosX()
{
	return m_posx;
}

int CBullet::GetPosY()
{
	return m_posy;
}

IplImage* CBullet::GetImage()
{
	return m_img;
}

void CBullet::Destory()
{
	m_isClear = true;
}

int CBullet::GetAttack()
{
	return m_atk;
}
