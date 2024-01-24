#include "stdafx.h"
#include "CPlayer.h"
#include "../App/app.h"
#include "InfiniteScroller.h"
#include "GameData.h"
#include "CEnemiesSpawner.h"
#include "SoundManager.h"


#define INPUT_DELAY 2.0f // minimum delay between each player input in ms

using namespace InfiniteScroller;

CPlayer::CPlayer(int maxHp, char* spritePath, char* spritePath2, int spriteColumns, int spriteRows, float speed) : CEntity(maxHp, spritePath, spriteColumns, spriteRows, speed)
{
	m_stateAnim2 = IDLE;

	m_sprite2 = InitSprite(spritePath2, spriteColumns, spriteRows, speed);
	//player's sprite position in x = position player in x - half width of its sprite
	m_sprite2->SetPosition(m_position.x - m_sprite2->GetWidth() / 2.0f, m_position.y);

	m_sprite2->SetAnimation(m_stateAnim2);

}



void CPlayer::DisplayPlayer()
{
	DisplayEntity();
	m_sprite2->Draw();
}

void CPlayer::UpdatePlayer(float deltaTime)
{
	if (m_isAlive)
	{
		if (GameData::GetInstance()->GetState() == INGAME)
			Input(deltaTime);

		UpdateEntity(deltaTime);

		//set animation if animation has changed
		if (m_lastStateAnim2 != m_stateAnim2)
		{
			m_endLoopAnimation = false;
			m_sprite2->SetAnimation(m_stateAnim2, true);
			m_lastStateAnim2 = m_stateAnim2;
		}

		m_sprite2->Update(deltaTime);

		//if player plays an animation that does not loop 
		if (m_stateAnim == ACTION || m_stateAnim == DEAD || m_stateAnim == HURT)
		{

			if (m_sprite->GetFrame() == m_totalNumberFrames + (int)m_stateAnim * m_totalNumberFrames - 1)//if play the last frame of animation
			{
				m_endLoopAnimation = true;
			}

			if (m_endLoopAnimation) // if animation is finished
			{
				if (m_stateAnim == ACTION || m_stateAnim == HURT)
				{
					m_stateAnim = RUN; //play to default animation
					m_stateAnim2 = RUN;
				}
				if (m_stateAnim == DEAD)
				{
					m_isAlive = false;//player is dead
					GameData::GetInstance()->SetPause(true);
					GameData::GetInstance()->SetState(DEATHMENU);

				}
			}

		}
		else if (m_stateAnim2 == ACTION)
		{
			if (m_sprite2->GetFrame() == m_totalNumberFrames + (int)m_stateAnim2 * m_totalNumberFrames - 1)
			{
				m_endLoopAnimation = true;
			}

			if (m_endLoopAnimation)
			{
				Attack();//do damage in front of him
				m_stateAnim2 = RUN; //play to default animation
			}
		}
	}
}

EAnimation CPlayer::GetStateAnim2()
{
	return m_stateAnim2;
}

void CPlayer::SetStateAnime2(EAnimation animation)
{
	m_stateAnim2 = animation;

}

void CPlayer::HurtPlayer(int damage)
{

	if (m_stateAnim != ACTION)//if player does not parry the attack
	{
		m_hp -= damage;

		if (m_hp <= 0)
		{
			//play death animation
			m_stateAnim = DEAD;
			m_stateAnim2 = DEAD;
			//play death sound
			App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXPlayerDeath());
		}
		else
		{
			//play damage animation
			m_stateAnim = HURT;
			m_stateAnim2 = HURT;
			//play hurt sound
			App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXPlayerHurt());


		}
	}
	else
		//play parry sound
		App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXPlayerParry());

}

void CPlayer::Attack()
{
	GameData::GetInstance()->GetEnemiesSpawner()->HurtEnemies(m_damage);
}

void CPlayer::Input(float deltaTime)
{
	m_inputDelay += deltaTime / 100.0f;

	if (m_inputDelay >= INPUT_DELAY)
	{
		if (App::IsKeyPressed('A') && m_stateAnim != ACTION && m_stateAnim2 != ACTION)//input for exchange position of the two player characters
		{
			FDot pos1;
			FDot pos2;

			m_sprite->GetPosition(pos1.x, pos1.y);
			m_sprite2->GetPosition(pos2.x, pos2.y);

			m_sprite->SetPosition(pos2.x, pos2.y);
			m_sprite2->SetPosition(pos1.x, pos1.y);

			//reset input delay
			m_inputDelay = 0.0f;

		}
		if (App::IsKeyPressed('E'))//input for attack or parry
		{
			FDot pos1;
			FDot pos2;

			m_sprite->GetPosition(pos1.x, pos1.y);
			m_sprite2->GetPosition(pos2.x, pos2.y);

			if (pos1.x - pos2.x > 0)//check which character player is furthest to the right of screen
			{
				m_stateAnim = ACTION; // Parry
			}
			else
			{
				m_stateAnim2 = ACTION; // Attack
				//play hit sound
				App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXPlayerHit());
			}
			//reset input delay
			m_inputDelay = 0.0f;
		}
	}
}

void CPlayer::HpGain(float hp)
{
	//play heal sound
	App::PlaySound(GameData::GetInstance()->GetSoundManager()->GetSFXPlayerHeal());
	m_hp += hp;
	if (m_hp > m_maxHp)
		m_hp = m_maxHp;
}

CPlayer::~CPlayer()
{
	SAFE_DELETE(m_sprite2);
}
