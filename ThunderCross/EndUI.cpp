// EndUI.cpp: implementation of the CEndUI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EndUI.h"
#include "GameManager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEndUI::CEndUI()
{
	m_img = cvLoadImage(".\\resource\\end.png");
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
	m_levels[0] = cvLoadImage(".\\resource\\d.png");
	m_levels[1] = cvLoadImage(".\\resource\\c.png");
	m_levels[2] = cvLoadImage(".\\resource\\b.png");
	m_levels[3] = cvLoadImage(".\\resource\\a.png");
	m_levels[4] = cvLoadImage(".\\resource\\s.png");
	m_levels[5] = cvLoadImage(".\\resource\\ss.png");
	m_levels[6] = cvLoadImage(".\\resource\\sss.png");
	m_levelscore[0] = 2000;
	m_levelscore[1] = 5000;
	m_levelscore[2] = 9000;
	m_levelscore[3] = 14000;
	m_levelscore[4] = 20000;
	m_levelscore[5] = 27000;
}

CEndUI::~CEndUI()
{

}
void CEndUI::Show(CGameManager* manager)
{
	ShowScoreNum(manager);
	cvShowImage("ThunderCross",m_img);
}

void CEndUI::ShowScoreNum(CGameManager* manager)
{

	int arr[10];
	int length = 0,score = manager->GetNowScore();
	int level,i,j,k;
	for( i = 0 ; i < 6 ; i ++)
		if(score < m_levelscore[i] ) break;
	level = i;


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
	int posx = 320 - length * 10;
	int posy = 225;
	for(k  = length - 1 ; k >= 0 ; k --)
	{
		for(i = 0 ; i < m_nums[arr[k]]->height ; i ++)
		{
			for(j = 0 ; j < m_nums[arr[k]]->width ; j ++)
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
    posy = 450 - m_levels[level]->height / 2;
	posx = 320 - m_levels[level]->width / 2;
	for(i = 0 ; i < m_levels[level]->height ; i ++)
		{
			for(j = 0 ; j < m_levels[level]->width ; j ++)
			{
				int b = CV_IMAGE_ELEM( m_levels[level], uchar, i, j*3);
				int g = CV_IMAGE_ELEM( m_levels[level], uchar, i, j*3+1);
				int r = CV_IMAGE_ELEM( m_levels[level], uchar, i, j*3+2);
				//rgb 178 132 91
				if( b > 85 && b < 95 && g > 128 && g < 135 && r > 175 && r < 180) continue;

				CV_IMAGE_ELEM( m_img, uchar, i + posy, (j + posx)*3) = b;
				CV_IMAGE_ELEM( m_img, uchar, i + posy, (j + posx)*3+1) = g;
				CV_IMAGE_ELEM( m_img, uchar, i + posy, (j + posx)*3+2) = r;
			}
		}
}
