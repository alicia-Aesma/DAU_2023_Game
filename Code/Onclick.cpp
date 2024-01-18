#include "stdafx.h"
#include "Onclick.h"
#include "GameData.h"
#include "InfiniteScroller.h"
#include "CBackground.h"
#include "CPlayer.h"
#include <iostream>

void ChangeGameStatetoPlay()
{
	InfiniteScroller::GameData* gameData = gameData->GetInstance();
	gameData->m_gameState = InfiniteScroller::INGAME;
	gameData->m_isPause = false;
	gameData->m_player->SetStateAnime(InfiniteScroller::RUN);
	gameData->m_player->SetStateAnime2(InfiniteScroller::RUN);
}

void QuitGame()
{
	exit(0);
}
