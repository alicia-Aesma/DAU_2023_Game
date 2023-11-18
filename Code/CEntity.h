#ifndef CENTITY_H
#define CENTITY_H
#define HEIGHT_FROM_GROUND 135
enum EAnimation;
class CSimpleSprite;

 class CEntity
{
protected :
	int m_hp = 0;
	int m_maxHp = 0;
	EAnimation* m_stateAnim = nullptr;
	CSimpleSprite* m_sprite = nullptr;

	CSimpleSprite* InitSprite(char* spritePath, int spriteColumns, int spriteRows, float speed);

public :
	CEntity(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed);
	CEntity();
	~CEntity();
	void DisplayEntity();
	void UpdateEntity(float deltaTime);


};

#endif

