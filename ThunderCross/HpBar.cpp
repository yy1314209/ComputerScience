// HpBar.cpp: implementation of the CHpBar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HpBar.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHpBar::CHpBar()
{
	m_img = cvLoadImage(".\\resource\\hpbar.png");
}

CHpBar::~CHpBar()
{
	cvReleaseImage(&m_img);
}

void CHpBar::Draw(IplImage* bg)
{
	for(int i = 0 ; i < m_img->height; i ++)
	{
		for(int j = 0 ; j < 58 + (m_img->width - 58 ) * ((double)m_nowHp / m_maxHp); j ++)
		{
			int b = CV_IMAGE_ELEM( m_img, uchar, i, j*3);
			int g = CV_IMAGE_ELEM( m_img, uchar, i, j*3+1);
			int r = CV_IMAGE_ELEM( m_img, uchar, i, j*3+2);
			//rgb 178 132 91
			if( b > 85 && b < 95 && g > 128 && g < 135 && r > 175 && r < 180) continue;

			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3) = b;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+1) = g;
			CV_IMAGE_ELEM( bg, uchar, i + m_posy, (j + m_posx)*3+2) = r;
		}
	}
}