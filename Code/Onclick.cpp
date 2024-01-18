#include "stdafx.h"
#include "Onclick.h"
#include "GameData.h"
#include "InfiniteScroller.h"
#include "CBackground.h"
#include "CPlayer.h"
#include "CScore.h"
#include "CEnemiesSpawner.h"
#include "CHeart.h"

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

void OpenMenu()
{
	InfiniteScroller::GameData::GetInstance()->m_gameState = InfiniteScroller::MENU;
	InfiniteScroller::GameData::GetInstance()->m_score->ResetScore();
	InfiniteScroller::GameData::GetInstance()->m_enemiesSpawner->ClearEnemies();
	InfiniteScroller::GameData::GetInstance()->m_player->SetStateAnime(InfiniteScroller::IDLE);
	InfiniteScroller::GameData::GetInstance()->m_player->SetStateAnime2(InfiniteScroller::IDLE);
	InfiniteScroller::GameData::GetInstance()->m_player->ResetHp();
	InfiniteScroller::GameData::GetInstance()->m_itemList.clear();
}
