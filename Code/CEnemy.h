#ifndef CENEMY_H
#define CENEMY_H

#include "CEntity.h"

namespace InfiniteScroller
{
	class CHeart;

	class CEnemy : public CEntity
	{
	public :
		CEnemy(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed);
		virtual ~CEnemy();
		virtual void DisplayEnemy();
		virtual void UpdateEnemy(float deltaTime);
		void HurtEnemy(int damage);
		EEnemyType GetEnemyType();

	protected : 
		const float m_referenceSpeed{ -0.12f };
		float m_currentSpeed{ m_referenceSpeed };
		const int m_attackDamage{ 10 };
		bool m_canAttack{ true };
		const float m_dropChance{0.3f};
		CHeart* m_item{ nullptr };
		EEnemyType m_enemyType{ KNIGHT };

	protected :
		void Loot();

	};
}

#endif // !CENEMY_H



