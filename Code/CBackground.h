#ifndef CBACKGROUND_H
#define CBACKGROUND_H

#include "App/app.h"

class CBackground
{
private :
	//CSimpleSprite m_layer[12];
	CSimpleSprite* m_layer[12];
	float m_layerSpeed[12];
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

