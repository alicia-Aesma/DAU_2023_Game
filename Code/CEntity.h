#ifndef CENTITY_H
#define CENTITY_H

#define HEIGHT_FROM_GROUND 135


class CSimpleSprite;

namespace InfiniteScroller
{
	enum EAnimation;

	class CEntity
	{

	public:
		CEntity(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed);
		~CEntity();
		void DisplayEntity();
		void UpdateEntity(float deltaTime);
		EAnimation* GetStateAnim();
		void SetStateAnime(EAnimation animation);

	protected:
		int m_hp{ 0 };
		int m_maxHp{ 0 };
		EAnimation* m_stateAnim{ nullptr };
		CSimpleSprite* m_sprite = { nullptr };
		CSimpleSprite* InitSprite(char* spritePath, int spriteColumns, int spriteRows, float speed);


	};
}

#endif

