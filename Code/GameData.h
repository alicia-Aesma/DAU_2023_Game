#ifndef GAMEDATA_H
#define GAMEDATA_H

class CBackground;
class CPlayer;
class CMenuStart;
enum EGameState;

class GameData
{
public:
	static GameData* GetInstance();
	CBackground* m_background = nullptr;
	CPlayer* m_player = nullptr;
	EGameState* m_gameState = nullptr;
	CMenuStart* m_menuStart = nullptr;
	void Update();
	void Init();

private : 
	EGameState m_lastGameState;
};

#endif



