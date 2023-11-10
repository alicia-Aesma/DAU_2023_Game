#include "stdafx.h"
#include "GameData.h"


GameData* GameData::GetInstance()
{
	static GameData singleInstance;
	return &singleInstance;
}
