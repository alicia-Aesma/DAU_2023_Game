#include "stdafx.h"
#include "CButton.h"
#include "GameData.h"
#include "../App/app.h"
#include "InfiniteScroller.h"

using namespace InfiniteScroller;

CButton::CButton(CSimpleSprite* sprite, CSimpleSprite* overlapSprite, PtrFonctOnclick onclick)
{
	m_sprite = sprite;
	m_overlapSprite = overlapSprite;
	m_onClick = onclick;

}

CButton::~CButton()
{
	SAFE_DELETE(m_sprite);
	SAFE_DELETE(m_overlapSprite);
}

void CButton::Display()
{
	if (MouseIsOnInteractible())
		m_overlapSprite->Draw();
	else
		m_sprite->Draw();
}

void CButton::OnClick()
{
	if (MouseIsOnInteractible())
		m_onClick();
}

bool CButton::MouseIsOnInteractible()
{
	FDot mousePos;
	FDot buttonPos;

	//retrieves position of the mouse and center of button
	App::GetMousePos(mousePos.x, mousePos.y);
	m_sprite->GetPosition(buttonPos.x, buttonPos.y);

	//we suppose the button to be a rectangle, test if the mouse is in rectangle
	if (mousePos.x > buttonPos.x - m_sprite->GetWidth() / 2.0f && mousePos.x < buttonPos.x + m_sprite->GetWidth() / 2.0f
		&& mousePos.y > buttonPos.y - m_sprite->GetHeight() / 2.0f && mousePos.y < buttonPos.y + m_sprite->GetHeight() / 2.0f)
		return true;
	else
		return false;
}




