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
	if (!GameData::GetInstance()->GetPause())
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

bool CHeart::GetIsDestroy()
{
	return m_isDestroy;
}

void CHeart::CollisionWithPlayer()
{
	//get position of the item
	FDot itemPos;
	m_sprite->GetPosition(itemPos.x, itemPos.y);

	//get position of the player
	FDot playerPos;
	GameData::GetInstance()->GetPlayer()->GetPosition(playerPos.x, playerPos.y);

	const float distance = itemPos.x - playerPos.x;

	//if player is close enough to the item he heals himself and destroys item
	if (distance <= m_sprite->GetWidth())
	{
		GameData::GetInstance()->GetPlayer()->HpGain(m_hpGain);
		m_isDestroy = true;
	}


}
