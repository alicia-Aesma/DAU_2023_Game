#ifndef CPLAYER_H
#define  CPLAYER_H

#include "CEntity.h"

namespace InfiniteScroller
{
	class CPlayer : public CEntity
	{
	public:
		CPlayer(int maxHp, char* spritePath1, char* spritePath2, int spriteColumns, int spriteRows, float speed);
		~CPlayer();
		void DisplayPlayer();
		void UpdatePlayer(float deltaTime);
		EAnimation GetStateAnim2();
		void SetStateAnime2(EAnimation animation);
		void HurtPlayer(int damage);
		void Input(float deltaTime);

	private:
		EAnimation m_lastStateAnim2{ IDLE };
		EAnimation m_stateAnim2{ IDLE };
		CSimpleSprite* m_sprite2{ nullptr };
		float m_inputDelay{ 0 };
		int m_damage{1};

	private:
		void Attack();


	};
}

#endif // !CPLAYER_H
