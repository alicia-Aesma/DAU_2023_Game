#ifndef CENEMY_H
#define CENEMY_H

#include "CEntity.h"

namespace InfiniteScroller
{
	class CEnemy : public CEntity
	{
	public :
		CEnemy(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed);
		~CEnemy() = default;
		void DisplayEnemy();
		void UpdateEnemy(float deltaTime);
		void HurtEnemy(int damage);

	private : 
		const float m_referenceSpeed{ -0.12f };
		float m_currentSpeed{ m_referenceSpeed };
		const int m_attackDamage{ 10 };
		bool m_canAttack{ true };

	};
}

#endif // !CENEMY_H



