#include "stdafx.h"
#include "CHPBar.h"
#include "GameData.h"
#include "CPlayer.h"
#include "../App/app.h"
#include <string>

#define HPBAR_SPRITE_PATH "..//Asset//Sprites//UI//InGame//"

using namespace InfiniteScroller;

CHpBar::CHpBar()
{
	for (int i = 0; i < HPBAR_SPRITE_COUNT; i++)
	{
		//Create sprite path
		std::string s = HPBAR_SPRITE_PATH "HPBar" + std::to_string(i) + ".png";
		char* path = new char[s.length() + 1];
		strcpy(path, s.c_str());

		//init sprite
		m_sprite[i] = App::CreateSprite(path, 1, 1);
		m_sprite[i]->SetPosition(APP_INIT_WINDOW_WIDTH / 100.0f * 10.0f, APP_INIT_WINDOW_HEIGHT / 100.0f * 90.0f );
	}
}

CHpBar::~CHpBar()
{
	for (int i = 0; i < HPBAR_SPRITE_COUNT; i++)
		SAFE_DELETE(m_sprite[i]);

}

void CHpBar::DisplayHPBar()
{
	//get player
	GameData gameData;
	CEntity* player = gameData.GetInstance()->m_player;

	//calculate player's life percentage 
	float percentageOfLife = (float)player->m_hp / (float)player->m_maxHp;

	//displays hp bar according to player's life percentage
	if (player->m_hp <= 0.0f)
	{
		m_sprite[0]->Draw();
	}
	else if (percentageOfLife <= 0.25f)
	{
		m_sprite[1]->Draw();
	}
	else if (percentageOfLife <= 0.5f)
	{
		m_sprite[2]->Draw();
	}
	else if (percentageOfLife <= 0.75f)
	{
		m_sprite[3]->Draw();
	}
	else if (percentageOfLife <= 1.0f)
	{
		m_sprite[4]->Draw();
	}

	
}
