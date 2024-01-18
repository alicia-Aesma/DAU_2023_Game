#ifndef CENTITY_H
#define CENTITY_H

#define HEIGHT_FROM_GROUND 135
#include "InfiniteScroller.h"

class CSimpleSprite;

namespace InfiniteScroller
{
	enum EAnimation;
	struct FDot;

	class CEntity
	{

	public:
		CEntity(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed);
		~CEntity();
		void DisplayEntity();
		void UpdateEntity(float deltaTime);
		EAnimation GetStateAnim();
		void SetStateAnime(EAnimation animation);
		void GetPosition(float& x, float& y);
		void GetSize(float& width, float& height);
		void ResetHp();

	protected:
		int m_hp{ 0 };
		int m_maxHp{ 0 };
		EAnimation m_lastStateAnim{ IDLE };
		EAnimation m_stateAnim{ IDLE };
		CSimpleSprite* m_sprite = { nullptr };
		FDot m_position{ 0,0 };
		bool m_endLoopAnimation{ false };
		int m_totalNumberFrames{ 0 };
		bool m_isAlive{ true };

	protected:
		CSimpleSprite* InitSprite(char* spritePath, int spriteColumns, int spriteRows, float speed);

		friend class CHpBar;
	};

}

#endif

