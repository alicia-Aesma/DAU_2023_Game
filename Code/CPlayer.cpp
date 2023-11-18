#include "stdafx.h"
#include "CPlayer.h"

CPlayer::CPlayer(int maxHp, char* spritePath1, char* spritePath2, int spriteColumns, int spriteRows, float speed)
{
	m_maxHp = maxHp;
	m_hp = m_maxHp;

	m_stateAnim = new EAnimation();
	*m_stateAnim = IDLE;

	m_sprite = InitSprite(spritePath1, spriteColumns, spriteRows,speed);
	m_sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2, HEIGHT_FROM_GROUND + m_sprite->GetHeight() / 2.0f);

	m_stateAnim2 = new EAnimation();
	*m_stateAnim2 = IDLE;

	m_sprite2 = InitSprite(spritePath2, spriteColumns, spriteRows,speed);
	m_sprite2->SetPosition(APP_INIT_WINDOW_WIDTH / 2 - m_sprite2->GetWidth() / 2.0f, HEIGHT_FROM_GROUND + m_sprite2->GetHeight() / 2.0f);
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

CPlayer::~CPlayer()
{
	delete m_sprite2;
	delete m_stateAnim2;
}
