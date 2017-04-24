// GameManager.cpp: implementation of the CGameManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GameManager.h"
#include "Timer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGameManager::CGameManager()
{
	cvNamedWindow("ThunderCross");
	m_addReward = NULL;
	m_buffReward = NULL;
	Start();
}

CGameManager::~CGameManager()
{
	cvDestroyWindow("ThunderCross");
}
void CGameManager::Run()
{
	
	while(1)
	{
		cvWaitKey(20);
		switch(m_state)
		{
		case GameState::GameStart :
			m_startui.Show();
			if(GetAsyncKeyState(' ') & 0x8000)
			{
				GameRunInit();
			}
			if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				return;
			}
		break;
		case GameState::GameRunning :
			LevelController();
			MyPlaneUpdate();
			EnemyPlaneUpdate();
			BulletUpdate();
			EffectUpdate();
			Collider();
			m_gameUi.Show(this);
			CTimer::Update();
		break;
		case GameState::GameEnd:
			m_endui.Show(this);
			if(GetAsyncKeyState(VK_RETURN) & 0x8000)
			{
				Start();
			}
			if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				return;
			}
		break;
		}
	}
}

void CGameManager::CreatBullet(IplImage *img, int posx, int posy, int dirx, int diry,int type,int atk)
{
	if(type == 0)
		m_bullets.push_back(new CBullet(img,posx,posy,dirx,diry,atk));
	else
		m_enemyBullets.push_back(new CBullet(img,posx,posy,dirx,diry,atk));
}

void CGameManager::BulletDraw()
{
	int i;
	for(i = 0 ; i < m_bullets.size() ; i ++)
		m_bullets[i]->Draw(m_gameUi.GetImage());
	for(i = 0 ; i < m_enemyBullets.size() ; i ++)
		m_enemyBullets[i]->Draw(m_gameUi.GetImage());
}

void CGameManager::BulletClear()
{
	int i;
	for(i = 0 ; i < m_bullets.size() ; i ++)
	{
		if(m_bullets[i]->NeedClear()){
			delete m_bullets[i];
			m_bullets.erase(m_bullets.begin()+i);
		}
	}
	for(i = 0 ; i < m_enemyBullets.size() ; i ++)
	{
		if(m_enemyBullets[i]->NeedClear()){
			delete m_enemyBullets[i];
			m_enemyBullets.erase(m_enemyBullets.begin()+i);
		}
	}
}

void CGameManager::BulletMove()
{
	int i;
	for(i = 0 ; i < m_bullets.size() ; i ++)
		m_bullets[i]->Move();
	for(i = 0 ; i < m_enemyBullets.size() ; i ++)
		m_enemyBullets[i]->Move();
}

void CGameManager::EnemyPlaneUpdate()
{
	int i;
	
	for(i = 0 ; i < m_enemyFighterPlane.size() ; i ++)
	{
		m_enemyFighterPlane[i]->Attack(this);
	}
	for(i = 0 ; i < m_enemyPlane.size() ; i ++)
	{
		m_enemyPlane[i]->Move(m_gameUi.GetImage()->width,m_gameUi.GetImage()->height);
	}
	
	for(i = 0 ; i < m_enemyFighterPlane.size() ; i ++)
	{
		m_enemyFighterPlane[i]->Move(m_gameUi.GetImage()->width,m_gameUi.GetImage()->height);
	}

	for(i = 0 ; i < m_enemyPlane.size() ; i ++)
	{
		m_enemyPlane[i]->Draw(m_gameUi.GetImage());
	}
	
	for(i = 0 ; i < m_enemyFighterPlane.size() ; i ++)
	{
		m_enemyFighterPlane[i]->Draw(m_gameUi.GetImage());
	}
	for(i = 0 ; i < m_enemyPlane.size() ; i ++)
	{
		if(m_enemyPlane[i]->NeedClear()){
			m_boomEffect.push_back(new CBoomEffect(
				m_enemyPlane[i]->GetPosX() + m_enemyPlane[i]->GetNowImage()->width / 2,
				m_enemyPlane[i]->GetPosY() + m_enemyPlane[i]->GetNowImage()->height / 2,
				10));
			m_score += m_enemyPlane[i]->GetValue();
			m_rewardNum ++;
			delete m_enemyPlane[i];
			m_enemyPlane.erase(m_enemyPlane.begin()+i);
		}
	}
	
	for(i = 0 ; i < m_enemyFighterPlane.size() ; i ++)
	{
		if(m_enemyFighterPlane[i]->NeedClear()){
			m_boomEffect.push_back(new CBoomEffect(
				m_enemyFighterPlane[i]->GetPosX() + m_enemyFighterPlane[i]->GetNowImage()->width / 2,
				m_enemyFighterPlane[i]->GetPosY() + m_enemyFighterPlane[i]->GetNowImage()->height / 2,
				10));
			m_score += m_enemyFighterPlane[i]->GetValue();
			m_rewardNum ++;
			m_rewardNum ++;
			delete m_enemyFighterPlane[i];
			m_enemyFighterPlane.erase(m_enemyFighterPlane.begin()+i);
		}
	}
	for(i = 0 ; i < m_enemyPlane.size() ; i ++)
	{
		m_enemyPlane[i]->Update();
	}
	
	for(i = 0 ; i < m_enemyFighterPlane.size() ; i ++)
	{
		m_enemyFighterPlane[i]->Update();
	}
}

void CGameManager::MyPlaneUpdate()
{
	m_myPlane.Move(m_gameUi.GetImage()->width,m_gameUi.GetImage()->height);
	m_myPlane.Draw(m_gameUi.GetImage());
	m_myPlane.Attack(this);
	m_myPlane.Update();
	if(m_myPlane.isDead()) End();
}

void CGameManager::BulletUpdate()
{
	BulletMove();
	BulletDraw();
	BulletClear();
}
IplImage* CGameManager::GetNowGameImage()
{
	return m_gameUi.GetImage();
}

void CGameManager::Collider()
{
	int i,j;


	//我方子弹与敌方子弹的碰撞检测.
	for(i = 0 ; i < m_enemyBullets.size() ; i ++)
	{
		int cx = m_enemyBullets[i]->GetPosX() + m_enemyBullets[i]->GetImage()->width / 2;
		int cy = m_enemyBullets[i]->GetPosY() + m_enemyBullets[i]->GetImage()->height / 2;
		for(j = 0 ; j < m_bullets.size() ; j ++)
		{
			int tx = m_bullets[j]->GetPosX() + m_bullets[j]->GetImage()->width / 2;
			int ty = m_bullets[j]->GetPosY() + m_bullets[j]->GetImage()->height / 2;
			if(abs(tx - cx) < m_enemyBullets[i]->GetImage()->width / 2 + m_bullets[j]->GetImage()->width / 2 &&
				abs(ty - cy) < m_enemyBullets[i]->GetImage()->height / 2 + m_bullets[j]->GetImage()->height / 2)
			{
				m_enemyBullets[i]->Destory();
				break;
			}
		}
	}

	// 我方子弹跟敌方中飞机的碰撞
	for(i = 0 ; i < m_bullets.size() ; i ++)
	{
		int cx = m_bullets[i]->GetPosX() + m_bullets[i]->GetImage()->width / 2;
		int cy = m_bullets[i]->GetPosY() + m_bullets[i]->GetImage()->height / 2;
		for(j = 0 ; j < m_enemyFighterPlane.size() ; j ++)
		{
			int tx = m_enemyFighterPlane[j]->GetPosX() + m_enemyFighterPlane[j]->GetNowImage()->width / 2;
			int ty = m_enemyFighterPlane[j]->GetPosY() + m_enemyFighterPlane[j]->GetNowImage()->height / 2;
			if(abs(tx - cx) < m_enemyFighterPlane[j]->GetNowImage()->width / 2 + m_bullets[i]->GetImage()->width / 2 &&
				abs(ty - cy) < m_enemyFighterPlane[j]->GetNowImage()->height / 2 + m_bullets[i]->GetImage()->height / 2)
			{
				m_enemyFighterPlane[j]->TakeDamage(m_bullets[i]->GetAttack());
				m_bullets.erase(m_bullets.begin()+i);
				break;
			}
		}
	}

	// 我方子弹跟敌方小飞机的碰撞
	for(i = 0 ; i < m_bullets.size() ; i ++)
	{
		int cx = m_bullets[i]->GetPosX() + m_bullets[i]->GetImage()->width / 2;
		int cy = m_bullets[i]->GetPosY() + m_bullets[i]->GetImage()->height / 2;
		for(j = 0 ; j < m_enemyPlane.size() ; j ++)
		{
			int tx = m_enemyPlane[j]->GetPosX() + m_enemyPlane[j]->GetNowImage()->width / 2;
			int ty = m_enemyPlane[j]->GetPosY() + m_enemyPlane[j]->GetNowImage()->height / 2;
			if(abs(tx - cx) < m_enemyPlane[j]->GetNowImage()->width / 2 + m_bullets[i]->GetImage()->width / 2 &&
				abs(ty - cy) < m_enemyPlane[j]->GetNowImage()->height / 2 + m_bullets[i]->GetImage()->height / 2)
			{
				m_enemyPlane[j]->TakeDamage(m_bullets[i]->GetAttack());
				m_bullets.erase(m_bullets.begin()+i);
				break;
			}
		}
	}
	//敌方子弹跟我方飞机的碰撞
	for(i = 0 ; i < m_enemyBullets.size() ; i ++)
	{
		int cx = m_enemyBullets[i]->GetPosX() + m_enemyBullets[i]->GetImage()->width / 2;
		int cy = m_enemyBullets[i]->GetPosY() + m_enemyBullets[i]->GetImage()->height / 2;

			int tx = m_myPlane.GetPosX() + m_myPlane.GetNowImage()->width / 2;
			int ty = m_myPlane.GetPosY() + m_myPlane.GetNowImage()->height / 2;
			if(abs(tx - cx) < m_myPlane.GetNowImage()->width / 2 + m_enemyBullets[i]->GetImage()->width / 2 &&
				abs(ty - cy) < m_myPlane.GetNowImage()->height / 2 + m_enemyBullets[i]->GetImage()->height / 2)
			{
				m_myPlane.TakeDamage(m_enemyBullets[i]->GetAttack());
				m_enemyBullets.erase(m_enemyBullets.begin()+i);
			}
	}

	//敌方飞机跟我方飞机的碰撞
	for(i = 0 ; i < m_enemyPlane.size() ; i ++)
	{
		int cx = m_enemyPlane[i]->GetPosX() + m_enemyPlane[i]->GetNowImage()->width / 2;
		int cy = m_enemyPlane[i]->GetPosY() + m_enemyPlane[i]->GetNowImage()->height / 2;

			int tx = m_myPlane.GetPosX() + m_myPlane.GetNowImage()->width / 2;
			int ty = m_myPlane.GetPosY() + m_myPlane.GetNowImage()->height / 2;
			if(abs(tx - cx) < m_myPlane.GetNowImage()->width / 2 + m_enemyPlane[i]->GetNowImage()->width / 2 &&
				abs(ty - cy) < m_myPlane.GetNowImage()->height / 2 + m_enemyPlane[i]->GetNowImage()->height / 2)
			{
				m_myPlane.TakeDamage(1);
				m_enemyPlane[i]->TakeDamage(2);
			}
	}
	for(i = 0 ; i < m_enemyFighterPlane.size() ; i ++)
	{
		int cx = m_enemyFighterPlane[i]->GetPosX() + m_enemyFighterPlane[i]->GetNowImage()->width / 2;
		int cy = m_enemyFighterPlane[i]->GetPosY() + m_enemyFighterPlane[i]->GetNowImage()->height / 2;

			int tx = m_myPlane.GetPosX() + m_myPlane.GetNowImage()->width / 2;
			int ty = m_myPlane.GetPosY() + m_myPlane.GetNowImage()->height / 2;
			if(abs(tx - cx) < m_myPlane.GetNowImage()->width / 2 + m_enemyFighterPlane[i]->GetNowImage()->width / 2 &&
				abs(ty - cy) < m_myPlane.GetNowImage()->height / 2 + m_enemyFighterPlane[i]->GetNowImage()->height / 2)
			{
				m_myPlane.TakeDamage(1);
				m_enemyFighterPlane[i]->TakeDamage(2);
			}
	}

	//道具和我方飞机的碰撞
	if(m_addReward != NULL)
	{
		int cx = m_addReward->GetPosX() + m_addReward->GetImage()->width / 2;
		int cy = m_addReward->GetPosY() + m_addReward->GetImage()->height / 2;
		int tx = m_myPlane.GetPosX() + m_myPlane.GetNowImage()->width / 2;
		int ty = m_myPlane.GetPosY() + m_myPlane.GetNowImage()->height / 2;
		if(abs(tx - cx) < m_myPlane.GetNowImage()->width / 2 + m_addReward->GetImage()->width / 2 &&
				abs(ty - cy) < m_myPlane.GetNowImage()->height / 2 + m_addReward->GetImage()->height / 2)
		{
			m_addReward->Effect(m_myPlane);
		}
	}
	if(m_buffReward != NULL)
	{
		int cx = m_buffReward->GetPosX() + m_buffReward->GetImage()->width / 2;
		int cy = m_buffReward->GetPosY() + m_buffReward->GetImage()->height / 2;
		int tx = m_myPlane.GetPosX() + m_myPlane.GetNowImage()->width / 2;
		int ty = m_myPlane.GetPosY() + m_myPlane.GetNowImage()->height / 2;
		if(abs(tx - cx) < m_myPlane.GetNowImage()->width / 2 + m_buffReward->GetImage()->width / 2 &&
				abs(ty - cy) < m_myPlane.GetNowImage()->height / 2 + m_buffReward->GetImage()->height / 2)
		{
			m_buffReward->Effect(m_myPlane);
		}
	}
}

void CGameManager::EffectUpdate()
{
	int i;
	for(i = 0 ; i < m_boomEffect.size() ; i ++)
		m_boomEffect[i]->Draw(m_gameUi.GetImage());
	for(i = 0 ; i < m_boomEffect.size() ; i ++)
	{
		if(m_boomEffect[i]->NeedClear()){
			delete m_boomEffect[i];
			m_boomEffect.erase(m_boomEffect.begin()+i);
		}
	}
	
	if(m_addReward != NULL )
	{
		m_addReward->Move(m_gameUi.GetImage()->width,m_gameUi.GetImage()->height);
		m_addReward->Draw(m_gameUi.GetImage());
		if( m_addReward->isNeedClear())
		{
			delete m_addReward;
			m_addReward = NULL;
		}
	}
	if(m_buffReward != NULL )
	{
		m_buffReward->Move(m_gameUi.GetImage()->width,m_gameUi.GetImage()->height);
		m_buffReward->Draw(m_gameUi.GetImage());
		if( m_buffReward->isNeedClear())
		{
			delete m_buffReward;
			m_buffReward = NULL;
		}
	}
}

void CGameManager::End()
{
	m_state = GameState::GameEnd;
	CTimer::UnRegister("Level");
	PlaySound(NULL,NULL,SND_FILENAME);
}

void CGameManager::Start()
{
	m_state = GameState::GameStart;
}

void CGameManager::GameRunInit()
{
	m_state = GameState::GameRunning;
	PlaySound(TEXT(".\\resource\\bg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	m_score = 0;
	m_levelcd = 3000;
	m_rewardNum = 0;

	delete m_addReward;
	m_addReward = NULL;
	delete m_buffReward;
	m_buffReward = NULL;

	
	int i;
	//初始化敌人飞机
	for( i = 0 ; i < m_enemyPlane.size() ; i ++) delete m_enemyPlane[i];
	for( i = 0 ; i < m_enemyFighterPlane.size() ; i ++) delete m_enemyFighterPlane[i];

	m_enemyFighterPlane.clear();
	m_enemyPlane.clear();

	//初始化子弹
	for( i = 0 ; i < m_bullets.size() ; i ++) delete m_bullets[i];
	for( i = 0 ; i < m_enemyBullets.size() ; i ++) delete m_enemyBullets[i];

	m_enemyBullets.clear();
	m_bullets.clear();

	//初始化特效
	for( i = 0 ; i < m_boomEffect.size() ; i ++) delete m_boomEffect[i];
	m_boomEffect.clear();
	CTimer::Register("Level",m_levelcd);

	//初始化我方飞机
	m_myPlane.Init();

}

void CGameManager::AddEnemyPlane()
{
	m_enemyFighterPlane.push_back(new CEnemyFighterPlane(m_gameUi.GetImage()->width));
	m_enemyPlane.push_back(new CEnemyPlane(m_gameUi.GetImage()->width));
}

void CGameManager::LevelController()
{
	static int num = 0;
	if(CTimer::CheckTimer("Level"))
	{
		CTimer::Reset("Level");
		AddEnemyPlane();
		num ++;
		if( num % 3 == 0 && m_levelcd > 200 )
		{
			m_levelcd -= 100;
			CTimer::Set("Level",m_levelcd);
		}
	}
	if(m_rewardNum > 15)
	{
		if(rand()% 2 == 0)
		{
			if(m_addReward != NULL) delete m_addReward;
			m_addReward = new CAddReward(m_gameUi.GetImage()->width);
		}
		else
		{
			if(m_buffReward != NULL) delete m_buffReward;
			m_buffReward = new cBuffReward(m_gameUi.GetImage()->width);
		}
		m_rewardNum = 0;
	}
}
