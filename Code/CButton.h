#ifndef CBUTTON_H
#define CBUTTON_H
#include "Iinteractible.h"

class CSimpleSprite;

namespace InfiniteScroller
{
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

		CSimpleSprite* m_sprite{ nullptr };
		CSimpleSprite* m_overlapSprite{ nullptr };
		PtrFonctOnclick m_onClick{ nullptr };

	private:
		// Inherited via IInteractible
		virtual bool MouseIsOnInteractible() override;

	};
}

#endif // !CBUTTON_H

