#ifndef CARCHER_H
#define CARCHER_H

#include "CEnemy.h"

class CSimpleSprite;

namespace InfiniteScroller
{

	class CArcher : public CEnemy
	{
	public :
		CArcher(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed);
		~CArcher();
		void DisplayEnemy();
		void UpdateEnemy(float deltaTime);

	private :
		CSimpleSprite* m_arrowSprite{ nullptr };
		const float m_referenceArrowSpeed{ -0.4f };
		float m_currentArrowSpeed{ m_referenceArrowSpeed };
		int m_nbArrow{ 1 };
		FDot m_arrowPosition;

	};
}

#endif // !CARCHER_H



