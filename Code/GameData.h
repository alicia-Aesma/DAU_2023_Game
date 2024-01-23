#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "InfiniteScroller.h"
#include "CHeart.h"
#include <list>

namespace InfiniteScroller
{
	class CBackground;
	class CPlayer;
	class CMenuStart;
	class CEnemiesSpawner;
	class CHpBar;
	class CScore;
	class CDeathMenu;

	class GameData
	{
	public:
		static GameData* GetInstance();
		void Init();
		~GameData();
		CBackground* GetBackground() {return m_background;};
		CPlayer* GetPlayer() { return m_player; };
		EGameState GetState() { return m_gameState; };
		void SetState(EGameState state) { m_gameState = state; }
		CMenuStart* GetMenuStart() { return m_menuStart; };
		CEnemiesSpawner* GetEnemiesSpawner() { return m_enemiesSpawner; };
		CHpBar* GetHpBar() { return m_hpBar; };
		CScore* GetScore() { return m_score; };
		CDeathMenu* GetMenuDeath() { return m_deathMenu; };
		bool GetPause() { return m_isPause; };
		void SetPause(bool pause) { m_isPause = pause; }
		int frame{ 0 };

	private:
		CBackground* m_background{ nullptr };
		CPlayer* m_player{ nullptr };
		EGameState m_gameState{ MENU };
		CMenuStart* m_menuStart{ nullptr };
		CEnemiesSpawner* m_enemiesSpawner{nullptr};
		CHpBar* m_hpBar{ nullptr };
		CScore* m_score;
		CDeathMenu* m_deathMenu{ nullptr };
		bool m_isPause{ true };
	};
}

#endif



