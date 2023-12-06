#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "InfiniteScroller.h"

namespace InfiniteScroller
{
	class CBackground;
	class CPlayer;
	class CMenuStart;

	class GameData
	{
	public:

		CBackground* m_background{ nullptr };
		CPlayer* m_player{ nullptr };
		EGameState m_gameState{ MENU};
		CMenuStart* m_menuStart{ nullptr };

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



