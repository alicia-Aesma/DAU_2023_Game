#include "stdafx.h"
#include "CKnight.h"
#include "GameData.h"
#include "CPlayer.h"
#include "../App/app.h"
#include "CScore.h"
#include "SoundManager.h"

#define SCORE_WHEN_KILL 10

using namespace InfiniteScroller;

CKnight::CKnight(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed) : CEnemy(maxHp, spritePath, spriteColumns, spriteRows, speed)
{
	m_enemyType = KNIGHT;
}

void InfiniteScroller::CKnight::UpdateEnemy(float deltaTime)
{
	CEnemy::UpdateEnemy(deltaTime);

	if (m_isAlive)
	{

		//get player's position
		FDot posPlayer;
		GameData::GetInstance()->GetPlayer()->GetPosition(posPlayer.x, posPlayer.y);

		//calculates the distance between player and Knight
		float distance = m_position.x - posPlayer.x;

		//if knight is close enough to player and to his right attacks him, distance <= eighth of width of enemy's sprite
		if (distance >= 0 && distance <= m_sprite->GetWidth() / 8.0f && m_stateAnim != DEAD)
		{
			m_stateAnim = ACTION;
			//play attack sound
			App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXKnightHit());
		}



		//if entity plays an animation that does not loop 
		if (m_stateAnim == ACTION || m_stateAnim == DEAD)
		{
			//if play the last frame of animation
			if (m_sprite->GetFrame() == m_totalNumberFrames + (int)m_stateAnim * m_totalNumberFrames - 1)
			{
				m_endLoopAnimation = true;
			}

			// if animation is finished
			if (m_endLoopAnimation)
			{
				// if attack animation is finished
				if (m_stateAnim == ACTION)
				{
					//play to default animation
					m_stateAnim = IDLE;
					//security to avoid double attack
					if (m_canAttack)
					{
						m_canAttack = false;
						// does damage to players
						GameData::GetInstance()->GetPlayer()->HurtPlayer(m_attackDamage);
					}
				}
				else if (m_stateAnim == DEAD)
				{
					m_isAlive = false;
					GameData::GetInstance()->GetScore()->AddValueScore(SCORE_WHEN_KILL);

				}
			}

		}
	}


}
