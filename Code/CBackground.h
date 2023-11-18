#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#define NB_BACKGROUND_LAYER 12
class CSimpleSprite;

class CBackground
{
private :
	CSimpleSprite* m_layer[NB_BACKGROUND_LAYER];
	float m_layerSpeed[NB_BACKGROUND_LAYER];
	bool m_isPause;
	float m_referenceSpeed;
	float m_currentSpeed;

public:
	bool GetPause() const { return m_isPause; }
	void SetPause(bool val) { m_isPause = val; }
	void DisplayBackground();
	void UpdateBackground(float deltaTime);
	CBackground();
	~CBackground();
};
#endif

