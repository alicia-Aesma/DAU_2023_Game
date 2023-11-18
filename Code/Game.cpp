//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
#include "GameData.h"
#include "CBackground.h"
#include "CPlayer.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Example data....
//------------------------------------------------------------------------
GameData gameData;


//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	gameData.GetInstance()->m_background = new CBackground();
	gameData.GetInstance()->m_player = new CPlayer(50, "..//Asset//Sprites//Skeleton_Warrior//Walk.png","..//Asset//Sprites//Skeleton_Spearman//Walk.png", 7, 1, 0.2f);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	gameData.GetInstance()->m_background->UpdateBackground(deltaTime);
	gameData.GetInstance()->m_player->UpdatePlayer(deltaTime);


}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	gameData.GetInstance()->m_background->DisplayBackground();
	gameData.GetInstance()->m_player->DisplayPlayer();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	gameData.GetInstance()->m_background->~CBackground();
	gameData.GetInstance()->m_player->~CPlayer();
}