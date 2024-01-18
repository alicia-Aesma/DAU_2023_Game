
#ifndef CHEART_H
#define CHEART_H

class CSimpleSprite;

namespace InfiniteScroller
{
	class CHeart
	{
	public: 
		CHeart(float posX, float posY);
		~CHeart();
		void Display();
		void Update(float deltaTime);

	private :
		CSimpleSprite* m_sprite;
		const float m_referenceSpeed{ -0.12f };
		float m_currentSpeed{ m_referenceSpeed };
		const int m_hpGain{ 2 };

	private :
		void CollisionWithPlayer();

	};
}

#endif // !CHEART_H



