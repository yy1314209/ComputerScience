// cBuffReward.cpp: implementation of the cBuffReward class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "cBuffReward.h"
#include "MyPlane.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cBuffReward::cBuffReward()
{
	m_isClear = false;
}


cBuffReward::cBuffReward(int width)
{
	m_isClear = false;
	m_img = cvLoadImage(".\\resource\\buff.png");
	m_posx = rand() % (width - m_img->width);
	m_posy = - m_img->height + 1;
	m_spx = (1 - 2 * (rand()%2)) * (rand() % 3 + 2);
	m_spy = rand() % 3 + 2;

}

cBuffReward::~cBuffReward()
{
	cvReleaseImage(&m_img);
}
void cBuffReward::Move(int width,int height)
{
	m_posx += m_spx;
	m_posy += m_spy;

	if(m_posx < 0){
		m_posx = 0;
		m_spx = - m_spx;
	}

	if(m_posx >= width - m_img->width)
	{
		m_posx = width - m_img->width - 1;
		m_spx = - m_spx;
	}

	if(m_posy >= height - m_img->height)
	{
		m_posy = height - m_img->height - 1;
		m_spy = - m_spy;
	}
}

void cBuffReward::Effect(CMyPlane& myplane)
{
	m_isClear = true;
	myplane.LevelUp();
}

void cBuffReward::Draw(IplImage *bg)
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
