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
#include "CDeathMenu.h"
#include "CHeart.h"
#include "SoundManager.h"
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
	switch (gameData->GetState())
	{
	case InfiniteScroller::MENU:
		gameData->GetMenuStart()->Input();
		gameData->GetScore()->ResetScore();
		break;
	case InfiniteScroller::INGAME:
		gameData->GetEnemiesSpawner()->UpdateEnemies(deltaTime);
		gameData->GetScore()->UpdateScore(deltaTime);
		
		break;
	case InfiniteScroller::DEATHMENU:
		gameData->GetMenuDeath()->Input();
		break;
	default:
		break;
	}

	gameData->GetBackground()->UpdateBackground(deltaTime);
	gameData->GetPlayer()->UpdatePlayer(deltaTime);
	gameData->GetSoundManager()->UpdateMusic();

}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{
	gameData->GetBackground()->DisplayBackground();
	gameData->GetPlayer()->DisplayPlayer();

	switch (gameData->GetState())
	{
	case InfiniteScroller::MENU:
		gameData->GetMenuStart()->Display();
		break;
	case InfiniteScroller::INGAME:
		gameData->GetHpBar()->DisplayHPBar();
		gameData->GetEnemiesSpawner()->DisplayEnemies();
		gameData->GetScore()->DisplayScore();
		break;
	case InfiniteScroller::DEATHMENU:
		gameData->GetMenuDeath()->Display();
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