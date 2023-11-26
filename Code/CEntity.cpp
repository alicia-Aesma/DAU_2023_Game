#include "stdafx.h"
#include "CEntity.h"
#include "EAnimation.h"
#include "App/app.h"

CEntity::CEntity(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed)
{
	m_maxHp = maxHp;
	m_hp = m_maxHp;

	m_stateAnim = new EAnimation();
	*m_stateAnim = IDLE;

	m_sprite = InitSprite(spritePath, spriteColumns, spriteRows, speed);
	m_sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2, HEIGHT_FROM_GROUND - m_sprite->GetHeight() / 2.0f);
	m_sprite->SetAnimation(*m_stateAnim);
}

CSimpleSprite* CEntity::InitSprite(char* spritePath, int spriteColumns, int spriteRows, float speed)
{
	CSimpleSprite* sprite;

	sprite = App::CreateSprite(spritePath, spriteColumns, spriteRows);
	sprite->SetScale(1.0f);

	std::vector<int> vectorColumns;
	for (int i = 0; i < spriteColumns && i < EAnimation::COUNT; i++)
		vectorColumns.push_back(i);

	for (int i = 0; i < spriteRows; i++)
	{
		sprite->CreateAnimation((EAnimation)i, speed, {0+i*spriteColumns,1+i*spriteColumns,2+i*spriteColumns,3+i*spriteColumns,4+i*spriteColumns ,5+i*spriteColumns,6 + i *spriteColumns });
		sprite->SetAnimation((EAnimation)i);
	}

	return sprite;
}

CEntity::CEntity()
{
}

void CEntity::DisplayEntity()
{
	m_sprite->Draw();
	
}

void CEntity::UpdateEntity(float deltaTime)
{
	m_sprite->Update(deltaTime);

	//if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	//{
	//	float x2;
	//	float y2;
	//	float x;
	//	float y;
	//	/*m_sprite2->GetPosition(x2, y2);
	//	m_sprite->GetPosition(x, y);
	//	m_sprite->SetPosition(x2, y2);
	//	m_sprite2->SetPosition(x, y);*/
	//}
}

EAnimation* CEntity::GetStateAnim()
{
	return m_stateAnim;
}

void CEntity::SetStateAnime(EAnimation animation)
{
	*m_stateAnim = animation;
	m_sprite->SetAnimation(*m_stateAnim);
}

CEntity::~CEntity()
{
	if (m_sprite != nullptr)
	delete m_sprite;
	if (m_stateAnim != nullptr)
	delete m_stateAnim;
}
