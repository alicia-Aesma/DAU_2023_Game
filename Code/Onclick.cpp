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
	gameData->SetState(InfiniteScroller::INGAME);
	gameData->SetPause(false);
	gameData->GetPlayer()->SetStateAnime(InfiniteScroller::RUN);
	gameData->GetPlayer()->SetStateAnime2(InfiniteScroller::RUN);
}

void QuitGame()
{
	exit(0);
}

void OpenMenu()
{
	InfiniteScroller::GameData::GetInstance()->SetState(InfiniteScroller::MENU);
	InfiniteScroller::GameData::GetInstance()->GetScore()->ResetScore();
	InfiniteScroller::GameData::GetInstance()->GetEnemiesSpawner()->ClearEnemies();
	InfiniteScroller::GameData::GetInstance()->GetPlayer()->SetStateAnime(InfiniteScroller::IDLE);
	InfiniteScroller::GameData::GetInstance()->GetPlayer()->SetStateAnime2(InfiniteScroller::IDLE);
	InfiniteScroller::GameData::GetInstance()->GetPlayer()->ResetHp();
}
