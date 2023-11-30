#ifndef CBUTTON_H
#define CBUTTON_H
#include "Iinteractive.h"

class CSimpleSprite;
enum EGameState;

class CButton : public IInteractible
{
public :
	CButton(CSimpleSprite* sprite, CSimpleSprite* overlapSprite, EGameState gameState);
	~CButton();
	void Display();

private:
	CSimpleSprite* m_sprite = nullptr;
	CSimpleSprite* m_overlapSprite = nullptr;
	EGameState* m_gameState = nullptr;

	// IInteractible
	void onMouseClick() override;

};

#endif // !CBUTTON_H

