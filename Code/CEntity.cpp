#include "stdafx.h"
#include "CEntity.h"
#include "InfiniteScroller.h"
#include "../App/app.h"
#include <vector>

using namespace InfiniteScroller;

CSimpleSprite* CEntity::InitSprite(char* spritePath, int spriteColumns, int spriteRows, float speed)
{
	CSimpleSprite* sprite = App::CreateSprite(spritePath, spriteColumns, spriteRows);
	sprite->SetScale(1.0f);

	m_totalNumberFrames = spriteColumns;


	for (int i = 0; i < spriteRows; i++)
	{
		std::vector<int> frames;

		for (int f = 0; f < spriteColumns; f++)
			frames.push_back(f + i * spriteColumns);

		sprite->CreateAnimation((EAnimation)i, speed, frames);
		sprite->SetAnimation((EAnimation)i);
	}

	return sprite;
}


CEntity::CEntity(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed)
{
	m_maxHp = maxHp;
	m_hp = m_maxHp;

	m_stateAnim = IDLE;
	m_lastStateAnim = m_stateAnim;

	m_sprite = InitSprite(spritePath, spriteColumns, spriteRows, speed);

	//entity position in x = half width of screen
	m_position.x = APP_INIT_WINDOW_WIDTH / 2.0f;
	//entity position in y = height from ground + half height of entity sprite
	m_position.y = HEIGHT_FROM_GROUND + m_sprite->GetHeight() / 2.0f;

	m_sprite->SetPosition(m_position.x, m_position.y);
	m_sprite->SetAnimation(m_stateAnim);
}

void CEntity::DisplayEntity()
{
	m_sprite->Draw();
}


void CEntity::UpdateEntity(float deltaTime)
{
	if (m_isAlive)
	{
		//set animation if animation has changed
		if (m_lastStateAnim != m_stateAnim)
		{
			m_endLoopAnimation = false;
			m_sprite->SetAnimation(m_stateAnim);
			m_sprite->SetAnimTime(0);
			m_lastStateAnim = m_stateAnim;
		}

		//update animation
		m_sprite->Update(deltaTime);
	}
}

EAnimation CEntity::GetStateAnim()
{
	return m_stateAnim;
}

void CEntity::SetStateAnime(EAnimation animation)
{
	m_stateAnim = animation;
}

void CEntity::GetPosition(float& x, float& y)
{
	x = m_position.x;
	y = m_position.y;
}

void CEntity::GetSize(float& width, float& height)
{
	width = m_sprite->GetWidth();
	height = m_sprite->GetHeight();
}

void InfiniteScroller::CEntity::ResetHp()
{
	m_hp = m_maxHp;
	m_isAlive = true;
}

CEntity::~CEntity()
{
	SAFE_DELETE(m_sprite);
}

