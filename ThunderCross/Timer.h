// Timer.h: interface for the CTimer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMER_H__C8BFA5CD_9683_4A41_A779_6C003E7697BA__INCLUDED_)
#define AFX_TIMER_H__C8BFA5CD_9683_4A41_A779_6C003E7697BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"
typedef struct TIMERINFO
{
	string name;
	int timer;
	int top;
	TIMERINFO(){}
	TIMERINFO(string n,int t,int p){
		name = n;
		timer = t;
		top = p;
	}
}TIMERINFO;

class CTimer  
{
public:

	CTimer();
	virtual ~CTimer();
	static void Start();
	static void Update();
	static void Register(string name,int top);
	static void UnRegister(string name);
	static bool CheckTimer(string name);
	static void Reset(string name);
	static void Set(string name,int top);
private:
	static vector<TIMERINFO*> m_timers;
	static int m_preTime;
};

#endif // !defined(AFX_TIMER_H__C8BFA5CD_9683_4A41_A779_6C003E7697BA__INCLUDED_)
