#include "stdafx.h"
#include "Onclick.h"
#include "GameData.h"
#include "EGameState.h"


void ChangeGameStatetoPlay()
{
	GameData gameData;
	*gameData.GetInstance()->m_gameState = INGAME;
}

void QuitGame()
{
}
