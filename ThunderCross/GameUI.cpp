// GameUI.cpp: implementation of the CGameUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GameUI.h"
#include "GameManager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGameUI::CGameUI()
{
	m_img = cvLoadImage(".\\resource\\bg.jpg");
	m_nums[0] = cvLoadImage(".\\resource\\nums\\0.png");
	m_nums[1] = cvLoadImage(".\\resource\\nums\\1.png");
	m_nums[2] = cvLoadImage(".\\resource\\nums\\2.png");
	m_nums[3] = cvLoadImage(".\\resource\\nums\\3.png");
	m_nums[4] = cvLoadImage(".\\resource\\nums\\4.png");
	m_nums[5] = cvLoadImage(".\\resource\\nums\\5.png");
	m_nums[6] = cvLoadImage(".\\resource\\nums\\6.png");
	m_nums[7] = cvLoadImage(".\\resource\\nums\\7.png");
	m_nums[8] = cvLoadImage(".\\resource\\nums\\8.png");
	m_nums[9] = cvLoadImage(".\\resource\\nums\\9.png");
	m_clone = cvCloneImage(m_img);
	m_speed = 1;
	m_length = 0;
}

CGameUI::~CGameUI()
{
	cvReleaseImage(&m_img);
	cvReleaseImage(&m_clone);
}
IplImage* CGameUI::GetImage()
{
	return m_img;
}
void CGameUI::SetBgImage()
{
	m_length = (m_length - m_speed + m_clone->height) % m_clone->height;

	for(int ty = 0 ; ty < m_clone->height ; ty ++)
	{
		int y = (ty + m_length) % m_clone->height;
		for(int x = 0 ; x < m_clone->width ; x ++)
		{
			int b = CV_IMAGE_ELEM( m_clone, uchar, y, x*3);
			int g = CV_IMAGE_ELEM( m_clone, uchar, y, x*3+1);
			int r = CV_IMAGE_ELEM( m_clone, uchar, y, x*3+2);
			CV_IMAGE_ELEM( m_img, uchar, ty, x*3) = b;
			CV_IMAGE_ELEM( m_img, uchar, ty, x*3+1) = g;
			CV_IMAGE_ELEM( m_img, uchar, ty, x*3+2) = r;
		}
	}
}
void CGameUI::Show(CGameManager* manager)
{
	ShowScoreNum(manager);
	cvShowImage("ThunderCross",m_img);
	SetBgImage();
}

void CGameUI::ShowScoreNum(CGameManager* manager)
{
	int posx = 480;
	int posy = 650;
	int arr[10];
	int length = 0,score = manager->GetNowScore();

	if(score != 0)
	{
		while(score)
		{
			arr[length++] = score % 10;
			score /= 10;
		}
	}
	else{
		arr[length++] = 0;
	}

	for(int k  = length - 1 ; k >= 0 ; k --)
	{
		for(int i = 0 ; i < m_nums[arr[k]]->height ; i ++)
		{
			for(int j = 0 ; j < m_nums[arr[k]]->width ; j ++)
			{
				int b = CV_IMAGE_ELEM( m_nums[arr[k]], uchar, i, j*3);
				int g = CV_IMAGE_ELEM( m_nums[arr[k]], uchar, i, j*3+1);
				int r = CV_IMAGE_ELEM( m_nums[arr[k]], uchar, i, j*3+2);
				//rgb 178 132 91
				if( b > 85 && b < 95 && g > 128 && g < 135 && r > 175 && r < 180) continue;

				CV_IMAGE_ELEM( m_img, uchar, i + posy, (j + posx)*3) = b;
				CV_IMAGE_ELEM( m_img, uchar, i + posy, (j + posx)*3+1) = g;
				CV_IMAGE_ELEM( m_img, uchar, i + posy, (j + posx)*3+2) = r;
			}
		}
		posx += m_nums[arr[k]]->width;
	}

}
