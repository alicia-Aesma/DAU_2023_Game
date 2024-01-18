#include "stdafx.h"
#include "CHeart.h"
#include "InfiniteScroller.h"
#include "..//App/app.h"
#include "GameData.h"
#include "CPlayer.h"

using namespace InfiniteScroller;

CHeart::CHeart(float posX, float posY)
{
	m_sprite = App::CreateSprite("..//Asset//Sprites//Decor//Heart.png",1,1);
	m_sprite->SetPosition(posX, posY);
}

CHeart::~CHeart()
{
	SAFE_DELETE(m_sprite);
}

void CHeart::Display()
{
	m_sprite->Draw();
}

void CHeart::Update(float deltaTime)
{
	if (!GameData::GetInstance()->m_isPause)
	{
		//get position of the item
		FDot itemPos;
		m_sprite->GetPosition(itemPos.x, itemPos.y);

		//Update speed of item according to the frame rate
		m_currentSpeed = m_referenceSpeed * deltaTime;

		//update item position
		itemPos.x += m_currentSpeed;

		//move item
		m_sprite->SetPosition(itemPos.x, itemPos.y);

		CollisionWithPlayer();
	}
}

void CHeart::CollisionWithPlayer()
{
	//get position of the item
	FDot itemPos;
	m_sprite->GetPosition(itemPos.x, itemPos.y);

	//get position of the player
	FDot playerPos;
	GameData::GetInstance()->m_player->GetPosition(playerPos.x, playerPos.y);

	const float distance = itemPos.x - playerPos.x;

	if (distance <= m_sprite->GetWidth())
	{
		GameData::GetInstance()->m_player->HpGain(m_hpGain);
	}


}
