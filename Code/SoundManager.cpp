#include "stdafx.h"
#include "SoundManager.h"
#include "../App/app.h"
#include "GameData.h"

using namespace InfiniteScroller;

SoundManager::SoundManager()
{
	m_lastState = MENU;
	App::PlaySound(m_musicMenu, true);
}

void SoundManager::UpdateMusic()
{
	if (m_lastState != GameData::GetInstance()->GetState())
	{
		m_lastState = GameData::GetInstance()->GetState();
		App::StopSound(m_musicMenu);
		App::StopSound(m_musicInGame);
		App::StopSound(m_musicInGameIntro);
		App::StopSound(m_musicGameOver);

		switch (GameData::GetInstance()->GetState())
		{
		case MENU:
			if (!App::IsSoundPlaying(m_musicMenu))
				App::PlaySound(m_musicMenu, true);
			break;
		case DEATHMENU:
			if (!App::IsSoundPlaying(m_musicGameOver))
				App::PlaySound(m_musicGameOver, true);
			break;
		case INGAME:
			if (!App::IsSoundPlaying(m_musicInGameIntro))
				App::PlaySound(m_musicInGameIntro);
			break;
		default:
			break;
		}
	}
	else if (GameData::GetInstance()->GetState() == INGAME)
	{
		if (!App::IsSoundPlaying(m_musicInGameIntro))
			App::PlaySound(m_musicInGame, true);
	}



}
