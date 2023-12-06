#include "stdafx.h"
#include "GameData.h"
#include "CBackground.h"
#include "CPlayer.h"
#include "CMenuStart.h"

using namespace InfiniteScroller;

GameData* GameData::GetInstance()
{
	static GameData singleInstance;
	return &singleInstance;
}

void GameData::Update()
{

	if (m_gameState != m_lastGameState)
	{
		m_lastGameState = m_gameState;
		//invoke event
	}

}

void GameData::Init()
{
	m_background = new CBackground();
	m_player = new CPlayer(50, "..//Asset//Sprites//Skeleton_Warrior//Warrior.png", "..//Asset//Sprites//Skeleton_Spearman//Spearman.png", 7, 5, 0.2f);
	m_lastGameState = m_gameState;
	m_menuStart = new CMenuStart();
}

GameData::~GameData()
{
	SAFE_DELETE(m_menuStart);
	SAFE_DELETE(m_background);
	SAFE_DELETE(m_player);
}
