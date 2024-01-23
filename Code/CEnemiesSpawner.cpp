#include "stdafx.h"
#include "CEnemiesSpawner.h"
#include "../App/app.h"
#include "CEnemy.h"
#include <string>
#include "GameData.h"
#include "CArcher.h"
#include "CKnight.h"

#define PATH_ENNEMY_SPRITE "..//Asset//Sprites//Knight//"
#define HEIGHT_FROM_GROUND 135
#define ENEMY_SPRITE_COUNT 4

using namespace InfiniteScroller;

CEnemiesSpawner::CEnemiesSpawner()
{

}

CEnemiesSpawner::~CEnemiesSpawner()
{

}

void CEnemiesSpawner::DisplayEnemies()
{
	//displays all enemies in scene

	for (CEnemy* enemy : m_enemiesInScene)
	{
		enemy->DisplayEnemy();
	}
}

void CEnemiesSpawner::UpdateEnemies(float deltaTime)
{
	//go through enemies in list
	auto itr = m_enemiesInScene.begin();

	while (itr != m_enemiesInScene.end())
	{
		FDot pos;
		FDot size;

		//get position of enemy

		(*itr)->GetPosition(pos.x, pos.y);
		//get size of enemy
		(*itr)->GetSize(size.x, size.y);

		//if enemy is off screen erase him from list, enemy position in x < half size of enemy's sprite
		if (pos.x < -size.x / 2.0f)
		{
			auto enemyToErase = itr;
			SAFE_DELETE(*enemyToErase);
			itr = m_enemiesInScene.erase(enemyToErase);
		}
		else
			itr++;
	}

	//update all enemies in list
	for (CEnemy* enemy : m_enemiesInScene)
	{
		enemy->UpdateEnemy(deltaTime);
	}

	//increment time
	m_currentTimeBetweenSpawn += deltaTime / 1000.0f;

	//if enough time has passed, a new enemy spawns
	if (m_currentTimeBetweenSpawn >= m_timeBetweenSpawn)
	{
		m_currentTimeBetweenSpawn = 0;

		//randomly defined a new duration before the next enemy spawn
		const float random = ((float)rand()) / (float)RAND_MAX;
		const float diff = m_maxTimeBetweenSpawns - m_minTimeBetweenSpawns;
		m_timeBetweenSpawn = m_minTimeBetweenSpawns + random * diff;

		SpawnEnemies();
	}
}

void CEnemiesSpawner::SpawnEnemies()
{
	//random int between 1 and and value of ENEMY_COUNT inclusive
	const int rng = rand() % ENEMY_SPRITE_COUNT + 1;
	char* enemy;

	if (rng == ENEMY_SPRITE_COUNT)
	{
		//creates new enemy 
		enemy = "..//Asset//Sprites//Skeleton_Archer//Archer.png";
		CArcher* newEnemy = new CArcher(1, enemy, 4, 4, 0.3f);
		// adds enemy to list of enemies present in the scene
		m_enemiesInScene.push_back(newEnemy); 
	}
	else
	{
		//creates link to enemy's sprite
		std::string s = PATH_ENNEMY_SPRITE "knight_" + std::to_string(rng) + ".png";
		enemy = new char[s.length() + 1];
		strcpy(enemy, s.c_str());
		//creates new enemy 
		CKnight* newEnemy = new CKnight(1, enemy, 4, 4, 0.3f);
		// adds enemy to list of enemies present in the scene
		m_enemiesInScene.push_back(newEnemy);
	}

}

void CEnemiesSpawner::HurtEnemies(int damage)
{
	for (CEnemy* enemy : m_enemiesInScene)
	{
		enemy->HurtEnemy(damage);
	}
}

void CEnemiesSpawner::ClearEnemies()
{
	m_enemiesInScene.clear();
}
