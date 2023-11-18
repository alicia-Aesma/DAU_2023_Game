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
}

CSimpleSprite* CEntity::InitSprite(char* spritePath, int spriteColumns, int spriteRows, float speed)
{
	CSimpleSprite* sprite;

	sprite = App::CreateSprite(spritePath, spriteColumns, spriteRows);
	sprite->SetScale(1.0f);

	std::vector<int> vectorColumns;
	for (int i = 0; i < spriteColumns; i++)
		vectorColumns.push_back(i);

	for (int i = 0; i < spriteRows; i++)
	{
		sprite->CreateAnimation((EAnimation)i, speed, {0,1,2,3,4,5});
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
	//m_sprite2->Update(deltaTime);

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

CEntity::~CEntity()
{
	delete m_sprite;
	delete m_stateAnim;
}
