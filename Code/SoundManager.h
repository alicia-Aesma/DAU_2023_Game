#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "InfiniteScroller.h"

namespace InfiniteScroller
{
	class SoundManager
	{
	public :
		SoundManager();
		~SoundManager() = default;

		void UpdateMusic();

		const char* GetMusicGameOver() { return m_musicGameOver; };
		const char* GetMusicInGameIntro() { return m_musicInGameIntro; };
		const char* GetMusicInGame() { return m_musicInGame; };
		const char* GetMusicMenu() { return m_musicMenu; };

		const char* GetSFXArcherDeath() { return m_archerDeath; };
		const char* GetSFXArcherHit() { return m_archerHit; };
		const char* GetSFXKnightDeath() { return m_knightDeath; };
		const char* GetSFXKnightHit() { return m_knightHit; };
		const char* GetSFXButtonOnClick() { return m_buttonOnClick; };
		const char* GetSFXPlayerDeath() { return m_playerDeath; };
		const char* GetSFXPlayerHeal() { return m_playerHeal; };
		const char* GetSFXPlayerHit() { return m_playerHit; };
		const char* GetSFXPlayerParry() { return m_playerParry; };
		const char* GetSFXPlayerHurt() { return m_playerHurt; };

	private :
		const char* m_musicGameOver{ "..//Asset//Sound//Music//MUSIC_Game_Over.wav" };
		const char* m_musicInGameIntro{ "..//Asset//Sound//Music//MUSIC_In_Game_intro.wav" };
		const char* m_musicInGame{ "..//Asset//Sound//Music//MUSIC_In_Game_loop.wav" };
		const char* m_musicMenu{ "..//Asset//Sound//Music//MUSIC_Menu.wav" };

		const char* m_archerDeath{ "..//Asset//Sound//SFX//SFX_ARCHER_Death.wav" };
		const char* m_archerHit{ "..//Asset//Sound//SFX//SFX_ARCHER_Hit.wav" };
		const char* m_knightDeath{ "..//Asset//Sound//SFX//SFX_KNIGHT_Death.wav" };
		const char* m_knightHit{ "..//Asset//Sound//SFX//SFX_KNIGHT_Hit.wav" };
		const char* m_buttonOnClick{ "..//Asset//Sound//SFX//SFX_BUTTON_OnClick.wav" };
		const char* m_playerDeath{ "..//Asset//Sound//SFX//SFX_PLAYER_Death.wav" };
		const char* m_playerHeal{ "..//Asset//Sound//SFX//SFX_PLAYER_Heal.wav" };
		const char* m_playerHit{ "..//Asset//Sound//SFX//SFX_PLAYER_Hit.wav" };
		const char* m_playerParry{ "..//Asset//Sound//SFX//SFX_PLAYER_Parry.wav" };
		const char* m_playerHurt{ "..//Asset//Sound//SFX//SFX_PLAYER_Hurt.wav" };
		

		EGameState m_lastState;

	};
}


#endif // !SOUND_MANAGER_H


