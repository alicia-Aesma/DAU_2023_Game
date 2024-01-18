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

		CBackground* m_background{ nullptr };
		CPlayer* m_player{ nullptr };
		EGameState m_gameState{ MENU};
		CMenuStart* m_menuStart{ nullptr };
		CEnemiesSpawner* m_enemiesSpawner;
		CHpBar* m_hpBar{ nullptr };
		CScore* m_score;
		CDeathMenu* m_deathMenu{ nullptr };
		bool m_isPause{ true };
		std::list<CHeart> m_itemList;


	public:

		static GameData* GetInstance();
		void Init();
		~GameData();

	private:
		EGameState m_lastGameState;
	};
}

#endif



