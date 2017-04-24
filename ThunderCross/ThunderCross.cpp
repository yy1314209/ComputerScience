// ThunderCross.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameManager.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


int main(int argc, char* argv[])
{
	CGameManager manager;
	manager.Run();
	return 0;
}
