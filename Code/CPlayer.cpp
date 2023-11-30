#include "stdafx.h"
#include "CPlayer.h"
#include "App/app.h"
#include "EAnimation.h"

CPlayer::CPlayer(int maxHp, char* spritePath1, char* spritePath2, int spriteColumns, int spriteRows, float speed)
{
	m_maxHp = maxHp;
	m_hp = m_maxHp;

	m_stateAnim = new EAnimation();
	*m_stateAnim = IDLE;

	m_sprite = InitSprite(spritePath1, spriteColumns, spriteRows,speed);
	m_sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, HEIGHT_FROM_GROUND + m_sprite->GetHeight() / 2.0f);

	m_sprite->SetAnimation(*m_stateAnim);

	m_stateAnim2 = new EAnimation();
	*m_stateAnim2 = IDLE;

	m_sprite2 = InitSprite(spritePath2, spriteColumns, spriteRows,speed);
	m_sprite2->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f - m_sprite2->GetWidth() / 2.0f, HEIGHT_FROM_GROUND + m_sprite2->GetHeight() / 2.0f);

	m_sprite2->SetAnimation(*m_stateAnim2);

}



void CPlayer::DisplayPlayer()
{
	DisplayEntity();
	m_sprite2->Draw();
}

void CPlayer::UpdatePlayer(float deltaTime)
{
	UpdateEntity(deltaTime);
	m_sprite2->Update(deltaTime);
}

EAnimation* CPlayer::GetStateAnim2()
{
	return m_stateAnim2;
}

void CPlayer::SetStateAnime2(EAnimation animation)
{
	*m_stateAnim2 = animation;
	m_sprite2->SetAnimation(*m_stateAnim2);
}

CPlayer::~CPlayer()
{
	if(m_sprite2 != nullptr)
	delete m_sprite2;
	if (m_stateAnim2 != nullptr)
	delete m_stateAnim2;
}
