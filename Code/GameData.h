#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "InfiniteScroller.h"

namespace InfiniteScroller
{
	class CBackground;
	class CPlayer;
	class CMenuStart;
	class CEnemiesSpawner;
	class CHpBar;
	class CScore;

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
		bool m_isPause{ true };


	public:

		static GameData* GetInstance();
		void Update();
		void Init();
		~GameData();

	private:
		EGameState m_lastGameState;
	};
}

#endif



