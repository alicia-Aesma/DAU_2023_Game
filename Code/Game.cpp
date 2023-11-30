//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
#include "GameData.h"
#include "CBackground.h"
#include "CPlayer.h"
#include "EGameState.h"
#include "CMenuStart.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Example data....
//------------------------------------------------------------------------
GameData* gameData = gameData->GetInstance();

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

	switch (*gameData->m_gameState)
	{
	case MENU :
		gameData->m_menuStart->Display();
		break;
	case INGAME : 
		break;
	default:
		break;
	}

	if (App::IsKeyPressed(VK_RBUTTON))
	{
		*gameData->m_gameState = INGAME;
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	gameData->m_background->~CBackground();
	gameData->m_player->~CPlayer();
	gameData->~GameData();
}