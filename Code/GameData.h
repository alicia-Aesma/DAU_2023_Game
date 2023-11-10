#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "CBackground.h"

class GameData
{
public:
	static GameData* GetInstance();
	CBackground m_background;
};

#endif



