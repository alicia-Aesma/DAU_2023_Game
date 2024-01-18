//------------------------------------------------------------------------
// Game.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
#include "GameData.h"
#include "CBackground.h"
#include "CPlayer.h"
#include "CMenuStart.h"
#include "Onclick.h"
#include "CEnemiesSpawner.h"
#include "CHPBar.h"
#include "CScore.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "../app/app.h"
#include <iostream>
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Example data....
//------------------------------------------------------------------------
InfiniteScroller::GameData* gameData = gameData->GetInstance();

//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	gameData->Init();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	switch (gameData->m_gameState)
	{
	case InfiniteScroller::MENU:
		gameData->m_menuStart->Input();
		gameData->m_score->ResetScore();
		break;
	case InfiniteScroller::INGAME:
		gameData->m_enemiesSpawner->UpdateEnemies(deltaTime);
		gameData->m_score->UpdateScore(deltaTime);
		break;
	default:
		break;
	}

	gameData->Update();
	gameData->m_background->UpdateBackground(deltaTime);
	gameData->m_player->UpdatePlayer(deltaTime);
	

}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{
	gameData->m_background->DisplayBackground();
	gameData->m_player->DisplayPlayer();

	switch (gameData->m_gameState)
	{
	case InfiniteScroller::MENU:
		gameData->m_menuStart->Display();
		break;
	case InfiniteScroller::INGAME:
		gameData->m_hpBar->DisplayHPBar();
		gameData->m_enemiesSpawner->DisplayEnemies();
		gameData->m_score->DisplayScore();
		break;
	default:
		break;
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{

}