#include "stdafx.h"
#include "GameData.h"
#include "CBackground.h"
#include "CPlayer.h"
#include "CMenuStart.h"
#include "CEnemiesSpawner.h"
#include "CHPBar.h"
#include "CScore.h"
#include "CDeathMenu.h"
#include "CHeart.h"

using namespace InfiniteScroller;

GameData* GameData::GetInstance()
{
	static GameData singleInstance;
	return &singleInstance;
}

void GameData::Init()
{
	m_background = new CBackground();
	m_player = new CPlayer(50, "..//Asset//Sprites//Skeleton_Warrior//Warrior.png", "..//Asset//Sprites//Skeleton_Spearman//Spearman.png", 7, 5, 0.2f);
	m_menuStart = new CMenuStart();
	m_enemiesSpawner = new CEnemiesSpawner();
	m_hpBar = new CHpBar();
	m_score = new CScore();
	m_deathMenu = new CDeathMenu();
}

GameData::~GameData()
{
	SAFE_DELETE(m_menuStart);
	SAFE_DELETE(m_background);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_enemiesSpawner);
	SAFE_DELETE(m_hpBar);
	SAFE_DELETE(m_score);
}
