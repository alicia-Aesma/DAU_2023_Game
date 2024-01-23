
#ifndef CKNIGHT_H
#define CKNIGHT_H

#include "CEnemy.h"

namespace InfiniteScroller
{

	class CKnight : public CEnemy
	{
	public : 
		CKnight(int maxHp, char* spritePath, int spriteColumns, int spriteRows, float speed);
		~CKnight() = default;
		void UpdateEnemy(float deltaTime);
	};
}


#endif // !CKNIGHT_H


