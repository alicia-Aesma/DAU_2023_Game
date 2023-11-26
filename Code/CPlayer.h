#ifndef CPLAYER_H
#define  CPLAYER_H

#include "CEntity.h"
#include "EAnimation.h"
#include "App/app.h"

class CPlayer : public CEntity
{
private :
	EAnimation* m_stateAnim2 = nullptr;
	CSimpleSprite* m_sprite2 = nullptr;

public :
	CPlayer(int maxHp, char* spritePath1, char* spritePath2, int spriteColumns, int spriteRows,  float speed );
	~CPlayer();
	void DisplayPlayer();
	void UpdatePlayer(float deltaTime);
	EAnimation* GetStateAnim2();
	void SetStateAnime2(EAnimation animation);

};

#endif // !CPLAYER_H
