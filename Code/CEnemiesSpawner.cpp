#include "stdafx.h"
#include "CEnemiesSpawner.h"
#include "../App/app.h"
#include "CEnemy.h"
#include <string>
#include "GameData.h"

#define PATH_ENNEMY_SPRITE "..//Asset//Sprites//Knight//"
#define HEIGHT_FROM_GROUND 135
#define ENEMY_COUNT 3

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

	for (CEnemy& enemy : m_enemiesInScene)
		enemy.DisplayEnemy();
}

void CEnemiesSpawner::UpdateEnemies(float deltaTime)
{
	//go through enemies in list
	auto itr = m_enemiesInScene.begin();

	while (itr != m_enemiesInScene.end())
	{
		FDot pos;
		FDot size;

		itr->GetPosition(pos.x, pos.y); //get position of enemy
		itr->GetSize(size.x, size.y);//get size of enemy

		if (pos.x < -size.x / 2.0f) //if  enemy is off screen erase him from list
		{
			auto enemyToErase = itr;
			itr++;
			m_enemiesInScene.erase(enemyToErase);
		}
		else
			itr++;
	}

	for (CEnemy& enemy : m_enemiesInScene)//update all enemies in list
		enemy.UpdateEnemy(deltaTime);

	m_currentTimeBetweenSpawn += deltaTime / 1000.0f;//increment time

	if (m_currentTimeBetweenSpawn >= m_timeBetweenSpawn) //if enough time has passed, a new enemy spawns
	{
		m_currentTimeBetweenSpawn = 0;

		//randomly defined a new duration before the next enemy spawn
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = m_maxTimeBetweenSpawns - m_minTimeBetweenSpawns;
		m_timeBetweenSpawn = m_minTimeBetweenSpawns + random * diff;

		SpawnEnemies();
	}
}

void CEnemiesSpawner::SpawnEnemies()
{
	const int rng = rand() % ENEMY_COUNT + 1; //random int between 1 and and value of ENEMY_COUNT inclusive

	//creates link to enemy's sprite
	std::string s = PATH_ENNEMY_SPRITE "knight_" + std::to_string(rng) + ".png";
	char* enemy = new char[s.length() + 1];
	strcpy(enemy, s.c_str());

	CEnemy* newEnemy = new CEnemy(1, enemy, 4, 4, 0.3f);//creates new enemy

	m_enemiesInScene.push_back(*newEnemy); //adds enemy to list of enemies present in the scene

}

void CEnemiesSpawner::HurtEnemies(int damage)
{
	for (CEnemy& enemy : m_enemiesInScene)
	{
		enemy.HurtEnemy(damage);
	}
}
