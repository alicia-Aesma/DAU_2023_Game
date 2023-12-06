#include "stdafx.h"
#include "CPlayer.h"
#include "../App/app.h"
#include "InfiniteScroller.h"

using namespace InfiniteScroller;

CPlayer::CPlayer(int maxHp, char* spritePath, char* spritePath2, int spriteColumns, int spriteRows, float speed) :CEntity(maxHp, spritePath, spriteColumns, spriteRows, speed)
{
	m_stateAnim2 = new EAnimation();
	*m_stateAnim2 = IDLE;

	m_sprite2 = InitSprite(spritePath2, spriteColumns, spriteRows, speed);
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
	m_sprite2->SetAnimation(*m_stateAnim2);
	m_sprite->SetAnimation(*m_stateAnim);

	//TEST SWAP MAIN CHARACTER CODE
	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	//{
	//	float x2;
	//	float y2;
	//	float x;
	//	float y;
	//	m_sprite2->GetPosition(x2, y2);
	//	m_sprite->GetPosition(x, y);
	//	m_sprite->SetPosition(x2, y2);
	//	m_sprite2->SetPosition(x, y);
	//}
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
	SAFE_DELETE(m_sprite2);
	SAFE_DELETE(m_stateAnim2);
}
