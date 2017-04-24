// Timer.cpp: implementation of the CTimer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Timer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
vector<TIMERINFO*> CTimer::m_timers;
int CTimer::m_preTime = 0;
CTimer::CTimer()
{
	m_preTime = 0;
}

CTimer::~CTimer()
{
	for(int i = 0 ; i < m_timers.size() ; i ++)
	{
		delete m_timers[i];
	}
	m_timers.clear();
}

void CTimer::Start()
{
	m_preTime = clock();
}

void CTimer::Update()
{
	int nowTime = clock();
	int offset = nowTime - m_preTime;
	for(int i = 0 ; i < m_timers.size() ; i ++){
		m_timers[i]->timer += offset;
	}
	m_preTime = nowTime;
}

void CTimer::Register(string name,int top)
{
	for(int i = 0 ; i < m_timers.size() ; i ++)
	{
		if(m_timers[i]->name == name)
		{
			printf("此名称计时器已使用: %s\n",name.c_str());
			return;
		}
	}
	m_timers.push_back(new TIMERINFO(name,0,top));
}

void CTimer::UnRegister(string name)
{
	for(int i = 0 ; i < m_timers.size() ; i ++)
		if(m_timers[i]->name == name)
		{
			delete m_timers[i];
			m_timers.erase(m_timers.begin()+i);
			break;
		}
}

void CTimer::Reset(string name)
{
	for(int i = 0 ; i < m_timers.size() ; i ++)
		if(m_timers[i]->name == name)
			m_timers[i]->timer = 0;
}

bool CTimer::CheckTimer(string name)
{
	for(int i = 0 ; i < m_timers.size() ; i ++)
			if(m_timers[i]->name == name)
				return m_timers[i]->timer >= m_timers[i]->top;
	return false;
}

void CTimer::Set(string name, int top)
{
	for(int i = 0 ; i < m_timers.size() ; i ++)
	{
		if(m_timers[i]->name == name)
		{
			m_timers[i]->top = top;
			return;
		}
	}
}
