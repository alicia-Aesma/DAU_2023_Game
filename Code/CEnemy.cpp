#include "stdafx.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "../App/app.h"
#include "InfiniteScroller.h"
#include "GameData.h"
#include "CEnemiesSpawner.h"
#include "CScore.h"
#include "CHeart.h"

#define SCORE_WHEN_KILL 10

using namespace InfiniteScroller;

CEnemy::CEnemy(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed) : CEntity(maxHp, spritePath, spriteColumns, spriteRows, speed)
{
	m_position.x = APP_INIT_WINDOW_WIDTH + m_sprite->GetWidth() / 2.0f;
	m_sprite->SetPosition(m_position.x, m_position.y);
}


void CEnemy::DisplayEnemy()
{
	//display enemy
	DisplayEntity();
}

void CEnemy::UpdateEnemy(float deltaTime)
{
	if (m_isAlive)
	{
		UpdateEntity(deltaTime);

		//get player's position
		GameData gameData;
		FDot posPlayer;
		gameData.GetInstance()->m_player->GetPosition(posPlayer.x, posPlayer.y);

		//calculates the distance between player and enemy
		float distance = m_position.x - posPlayer.x;

		//if enemy is close enough to player and to his right attacks him
		if (distance >= 0 && distance <= m_sprite->GetWidth() / 8.0f && m_stateAnim != DEAD) 
		{
			m_stateAnim = ACTION;
		}

		//if entity plays an animation that does not loop 
		if (m_stateAnim == ACTION || m_stateAnim == DEAD)
		{
			if (m_sprite->GetFrame() == m_totalNumberFrames + (int)m_stateAnim * m_totalNumberFrames - 1)//if play the last frame of animation
			{
				m_endLoopAnimation = true;
			}

			if (m_endLoopAnimation) // if animation is finished
			{
				if (m_stateAnim == ACTION) // if attack animation is finished
				{
					m_stateAnim = IDLE; //play to default animation
					if (m_canAttack)//security to avoid double attack
					{
						m_canAttack = false;
						gameData.GetInstance()->m_player->HurtPlayer(m_attackDamage);// does damage to players
					}
				}
				else if (m_stateAnim == DEAD)
				{
					m_isAlive = false;
					GameData gameData;
					gameData.GetInstance()->m_score->AddValueScore(SCORE_WHEN_KILL);
				}
			}

		}
	}

	if (!GameData::GetInstance()->m_isPause)
	{

		//Update speed of enemy according to the frame rate
		m_currentSpeed = m_referenceSpeed * deltaTime;

		//update enemy position
		m_position.x += m_currentSpeed;

		//move enemy
		m_sprite->SetPosition(m_position.x, m_position.y);
	}
}

void CEnemy::HurtEnemy(int damage)
{
	FDot posPlayer;

	GameData::GetInstance()->m_player->GetPosition(posPlayer.x, posPlayer.y);

	const float distance = abs(m_position.x - posPlayer.x);//calculates the distance between player and enemy

	if (distance <= m_sprite->GetWidth()/4.0f) //if player is close enough to enemy, attacks him
	{
		m_hp -= damage;

		if (m_hp <= 0)
		{
			//play death animation
			m_stateAnim = DEAD;
			Loot();
		}
	}
}

void CEnemy::Loot()
{
	CHeart* item= new CHeart(m_position.x + m_sprite->GetWidth(), m_position.y);
	GameData::GetInstance()->m_itemList.push_back(*item);
}
