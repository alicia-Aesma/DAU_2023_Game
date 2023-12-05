#ifndef CBUTTON_H
#define CBUTTON_H
#include "Iinteractive.h"

class CSimpleSprite;
enum EGameState;
typedef void (*PtrFonctOnclick)();

class CButton : public IInteractible
{
public:

	CButton(CSimpleSprite* sprite, CSimpleSprite* overlapSprite, PtrFonctOnclick onclick);
	~CButton();
	void Display();

	// Inherited via IInteractible
	virtual void OnClick() override;

private:

	CSimpleSprite* m_sprite = nullptr;
	CSimpleSprite* m_overlapSprite = nullptr;
	PtrFonctOnclick m_onClick = nullptr;

	// Inherited via IInteractible
	virtual bool MouseIsOnInteractible() override;

};

#endif // !CBUTTON_H

