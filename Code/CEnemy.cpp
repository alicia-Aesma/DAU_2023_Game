#include "stdafx.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "../App/app.h"
#include "InfiniteScroller.h"
#include "GameData.h"
#include "CEnemiesSpawner.h"
#include "CScore.h"
#include "CHeart.h"
#include "SoundManager.h"

using namespace InfiniteScroller;

CEnemy::CEnemy(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed) : CEntity(maxHp, spritePath, spriteColumns, spriteRows, speed)
{
	//init enemy position ,position = screen size + half sprite size
	m_position.x = APP_INIT_WINDOW_WIDTH + m_sprite->GetWidth() / 2.0f;
	m_sprite->SetPosition(m_position.x, m_position.y);
}

InfiniteScroller::CEnemy::~CEnemy()
{
	SAFE_DELETE(m_item);
}


void CEnemy::DisplayEnemy()
{
	//display enemy
	DisplayEntity();
	if (m_item != nullptr)
		m_item->Display();
}

void CEnemy::UpdateEnemy(float deltaTime)
{
	if (m_isAlive)
	{
		UpdateEntity(deltaTime);
	}

	if (!GameData::GetInstance()->GetPause())
	{
		//Update speed of enemy according to the frame rate
		m_currentSpeed = m_referenceSpeed * deltaTime;

		//update enemy position
		m_position.x += m_currentSpeed;

		//move enemy
		m_sprite->SetPosition(m_position.x, m_position.y);

		//move item
		if (m_item != nullptr)
		{
			if (m_item->GetIsDestroy())
			{
				SAFE_DELETE(m_item);
			}
			else
			{
				m_item->Update(deltaTime);
			}
		}
	}
}

void CEnemy::HurtEnemy(int damage)
{

	FDot posPlayer;
	GameData::GetInstance()->GetPlayer()->GetPosition(posPlayer.x, posPlayer.y);

	//calculates the distance between player and enemy
	const float distance = abs(m_position.x - posPlayer.x);

	//if player is close enough to enemy, attacks him, distanec <= quarter size of sprite
	if (distance <= m_sprite->GetWidth() / 4.0f)
	{
		m_hp -= damage;

		if (m_hp <= 0)
		{
			//play death animation
			m_stateAnim = DEAD;
			//test if enemy drops life when he dies death
			if ((float)(rand()) / (float)(RAND_MAX) <= m_dropChance)
				Loot();
			//play sounds
			if (m_enemyType == ARCHER)
			{
				App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXArcherDeath());
			}
			else
			{
				App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXKnightDeath());
				//play attack sound
				App::StopSound(GameData::GetInstance()->GetSoundManager()->GetSFXKnightHit());
			}

		}
	}
}

EEnemyType CEnemy::GetEnemyType()
{
	return m_enemyType;
}

void CEnemy::Loot()
{
	//itemPosX = position in x of enemy + half width of enemy sprite, itemPosY = position in y of enemy - quarter of height of enemy sprite
	m_item = new CHeart(m_position.x + m_sprite->GetWidth() / 2.0f, m_position.y - m_sprite->GetHeight() / 4.0f);
}
