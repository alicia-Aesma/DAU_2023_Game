#ifndef GAMEDATA_H
#define GAMEDATA_H

class CBackground;
class CPlayer;
enum EGameState;

class GameData
{
public:
	static GameData* GetInstance();
	CBackground* m_background;
	CPlayer* m_player;
	EGameState* m_gameState;
};

#endif



