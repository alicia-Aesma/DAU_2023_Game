#ifndef CHPBAR_H
#define CHPBAR_H

#define HPBAR_SPRITE_COUNT 5

class CSimpleSprite;

namespace InfiniteScroller
{
	class CHpBar
	{
	public :  
		CHpBar();
		~CHpBar();
		void DisplayHPBar();

	private :
		CSimpleSprite* m_sprite[HPBAR_SPRITE_COUNT];

	};
}

#endif // !CHPBAR_H



