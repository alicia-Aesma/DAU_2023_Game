#include "stdafx.h"
#include "Onclick.h"
#include "GameData.h"
#include "InfiniteScroller.h"

using namespace InfiniteScroller;

void ChangeGameStatetoPlay()
{
	GameData gameData;
	gameData.GetInstance()->m_gameState = InfiniteScroller::INGAME;
}

void QuitGame()
{
}
