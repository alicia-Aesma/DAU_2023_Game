#include "stdafx.h"
#include "CArcher.h"
#include "../App/app.h"
#include "InfiniteScroller.h"
#include "GameData.h"
#include "CScore.h"
#include "CPlayer.h"

#define ARROW_SPRITE_PATH "..//Asset//Sprites//Skeleton_Archer//Arrow.png"
#define ARROW_POS_X 75
#define ARROW_POS_Y -30
#define SCORE_WHEN_KILL 12

using namespace InfiniteScroller;

InfiniteScroller::CArcher::CArcher(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed) : CEnemy(maxHp, spritePath, spriteColumns, spriteRows, speed)
{
	m_enemyType = ARCHER;
}

CArcher::~CArcher()
{
	SAFE_DELETE(m_arrowSprite);
}

void CArcher::DisplayEnemy()
{
	CEnemy::DisplayEnemy();
	
	//displayArrow
	if (m_arrowSprite != nullptr)
	{
		m_arrowSprite->Draw();
	}
}

void CArcher::UpdateEnemy(float deltaTime)
{
	CEnemy::UpdateEnemy(deltaTime);

	if (m_isAlive)
	{
		if (m_nbArrow > 0 && m_position.x < APP_INIT_WINDOW_WIDTH - m_sprite->GetWidth())
		{
			//change archer animation
			m_stateAnim = ACTION;
			//removes an arrow from the archer's inventory
			m_nbArrow--;
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

					//create arrow sprite
					m_arrowSprite = App::CreateSprite(ARROW_SPRITE_PATH, 1, 1);
					//set position arrow sprite
					m_arrowPosition.x = m_position.x + ARROW_POS_X;
					m_arrowPosition.y = m_position.y + ARROW_POS_Y;
					m_arrowSprite->SetPosition(m_arrowPosition.x, m_arrowPosition.y);
				
				}
				else if (m_stateAnim == DEAD)
				{
					m_isAlive = false;
					GameData::GetInstance()->GetScore()->AddValueScore(SCORE_WHEN_KILL);
				}
			}

		}

	}

	if (!GameData::GetInstance()->GetPause()  && m_arrowSprite != nullptr)
	{

		//Update speed of arrow according to the frame rate
		m_currentArrowSpeed = m_referenceArrowSpeed * deltaTime;

		//update arrow position
		m_arrowPosition.x += m_currentArrowSpeed;

		//move arrow
		m_arrowSprite->SetPosition(m_arrowPosition.x, m_arrowPosition.y);

		//get player's position
		FDot posPlayer;
		GameData::GetInstance()->GetPlayer()->GetPosition(posPlayer.x, posPlayer.y);

		//calculates the distance between player and Arrow
		float distance = m_arrowPosition.x - posPlayer.x;

		//if arrow is close enough to player and to his right attacks him, distance <= eighth of width of arrow's sprite
		if (distance >= 0 && distance <= m_arrowSprite->GetWidth() / 8.0f )
		{
			// does damage to players
			GameData::GetInstance()->GetPlayer()->HurtPlayer(m_attackDamage);
		}
	}
}

