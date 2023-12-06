#include "stdafx.h"
#include "CEntity.h"
#include "InfiniteScroller.h"
#include "../App/app.h"

using namespace InfiniteScroller;

CSimpleSprite* CEntity::InitSprite(char* spritePath, int spriteColumns, int spriteRows, float speed)
{
	CSimpleSprite* sprite = App::CreateSprite(spritePath, spriteColumns, spriteRows);
	sprite->SetScale(1.0f);

	std::vector<int> vectorColumns;
	for (int i = 0; i < spriteColumns && i < InfiniteScroller::COUNT; i++)
		vectorColumns.push_back(i);

	for (int i = 0; i < spriteRows; i++)
	{
		sprite->CreateAnimation((EAnimation)i, speed, { 0 + i * spriteColumns,1 + i * spriteColumns,2 + i * spriteColumns,3 + i * spriteColumns,4 + i * spriteColumns ,5 + i * spriteColumns,6 + i * spriteColumns });
		sprite->SetAnimation((EAnimation)i);
	}

	return sprite;
}


CEntity::CEntity(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed)
{
	m_maxHp = maxHp;
	m_hp = m_maxHp;

	m_stateAnim = new EAnimation();
	*m_stateAnim = InfiniteScroller::IDLE;

	m_sprite = InitSprite(spritePath, spriteColumns, spriteRows, speed);
	m_sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, HEIGHT_FROM_GROUND + m_sprite->GetHeight() / 2.0f);
	m_sprite->SetAnimation(*m_stateAnim);
}




void CEntity::DisplayEntity()
{
	m_sprite->Draw();
	
}

void CEntity::UpdateEntity(float deltaTime)
{
	m_sprite->Update(deltaTime);

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
