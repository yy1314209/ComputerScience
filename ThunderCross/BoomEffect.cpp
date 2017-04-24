// BoomEffect.cpp: implementation of the CBoomEffect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BoomEffect.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBoomEffect::CBoomEffect()
{
	m_index = 0;
	m_speed = 5;
	m_imgs[0] = cvLoadImage(".\\resource\\0.png");
	m_imgs[1] = cvLoadImage(".\\resource\\1.png");
	m_imgs[2] = cvLoadImage(".\\resource\\2.png");
	m_imgs[3] = cvLoadImage(".\\resource\\3.png");
	m_isClear = false;
	m_posx = m_posy = 100;
}

CBoomEffect::CBoomEffect(int posx,int posy,int speed = 5)
{
	m_index = 0;
	m_speed = 5;
	m_imgs[0] = cvLoadImage(".\\resource\\0.png");
	m_imgs[1] = cvLoadImage(".\\resource\\1.png");
	m_imgs[2] = cvLoadImage(".\\resource\\2.png");
	m_imgs[3] = cvLoadImage(".\\resource\\3.png");
	m_isClear = false;
	m_posx = posx;
	m_posy = posy;
}

CBoomEffect::~CBoomEffect()
{
	cvReleaseImage(&m_imgs[0]);
	cvReleaseImage(&m_imgs[1]);
	cvReleaseImage(&m_imgs[2]);
	cvReleaseImage(&m_imgs[3]);
}

void CBoomEffect::Draw(IplImage *bg)
{
	
	if(m_isClear) return;

	IplImage* nowImg = m_imgs[m_index / m_speed];

	int posx = m_posx - nowImg->width / 2;
	int posy = m_posy - nowImg->height / 2;
	
	for(int i = 0 ; i < nowImg->height; i ++)
	{
		for(int j = 0 ; j < nowImg->width; j ++)
		{
			int b = CV_IMAGE_ELEM( nowImg, uchar, i, j*3);
			int g = CV_IMAGE_ELEM( nowImg, uchar, i, j*3+1);
			int r = CV_IMAGE_ELEM( nowImg, uchar, i, j*3+2);
			//rgb 178 132 91
			if( b > 80 && b < 100 && g > 125 && g < 140 && r > 170 && r < 185) continue;
			if(i + posy < 0 || i + posy >= bg->height || j + posx < 0 || j + posx >= bg->width) continue;

			CV_IMAGE_ELEM( bg, uchar, i + posy, (j + posx)*3) = b;
			CV_IMAGE_ELEM( bg, uchar, i + posy, (j + posx)*3+1) = g;
			CV_IMAGE_ELEM( bg, uchar, i + posy, (j + posx)*3+2) = r;
		}
	}
	m_index ++;
	if(m_index / m_speed > 3) m_isClear = true;
}

bool CBoomEffect::NeedClear()
{
	return m_isClear;
}
