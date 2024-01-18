#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#define NB_BACKGROUND_LAYER 12

class CSimpleSprite;

namespace InfiniteScroller
{

	class CBackground
	{
	public:

		void DisplayBackground();
		void UpdateBackground(float deltaTime);
		CBackground();
		~CBackground();

	private:
		CSimpleSprite* m_layer[NB_BACKGROUND_LAYER];
		float m_layerSpeed[NB_BACKGROUND_LAYER];
		const float m_referenceSpeed{ 0.12f };
		float m_currentSpeed{ m_referenceSpeed };


	};
}

#endif

