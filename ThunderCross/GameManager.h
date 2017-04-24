// GameManager.h: interface for the CGameManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEMANAGER_H__87128AD7_873D_4C3E_92F9_E092563D3847__INCLUDED_)
#define AFX_GAMEMANAGER_H__87128AD7_873D_4C3E_92F9_E092563D3847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StdAfx.h"
#include "GameUI.h"
#include "MyPlane.h"
#include "Bullet.h"
#include "AddReward.h"
#include "EnemyFighterPlane.h"
#include "cBuffReward.h"
#include "StartUI.h"
#include "EndUI.h"
#include "EnemyPlane.h"
#include "BoomEffect.h"

class CGameManager  
{
public:
	void LevelController();
	void AddEnemyPlane();
	void GameRunInit();
	void Start();
	void End();
	void EffectUpdate();
	void Collider();
	IplImage* GetNowGameImage();
	void BulletUpdate();
	void MyPlaneUpdate();
	void EnemyPlaneUpdate();
	void BulletMove();
	void BulletClear();
	void BulletDraw();
	void CreatBullet(IplImage* img,int posx,int posy,int dirx,int diry,int tpye,int atk);
	void Run();
	CGameManager();
	int GetNowScore(){ return m_score; }
	virtual ~CGameManager();
	enum GameState {  GameStart,GameRunning,GameEnd  };
private:
	
	GameState m_state;
	CGameUI m_gameUi;
	CStartUI m_startui;
	CEndUI m_endui;
	CMyPlane m_myPlane;
	vector<CBoomEffect*> m_boomEffect;
	vector<CEnemyPlane* > m_enemyPlane;
	vector<CEnemyFighterPlane*> m_enemyFighterPlane;
	vector<CBullet*> m_bullets;
	vector<CBullet*> m_enemyBullets;
	CAddReward* m_addReward;
	cBuffReward* m_buffReward;
	int m_score;
	int m_levelcd;
	int m_rewardNum;
};

#endif // !defined(AFX_GAMEMANAGER_H__87128AD7_873D_4C3E_92F9_E092563D3847__INCLUDED_)
