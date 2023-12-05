#include "stdafx.h"
#include "CButton.h"
#include "GameData.h"
#include "EGameState.h"
#include "App/app.h"

CButton::CButton(CSimpleSprite* sprite, CSimpleSprite* overlapSprite, PtrFonctOnclick onclick)
{
	m_sprite = sprite;
	m_overlapSprite = overlapSprite;
	m_onClick = onclick;

}

CButton::~CButton()
{
	if (m_sprite != nullptr)
		delete m_sprite;

	if (m_overlapSprite != nullptr)
		delete m_overlapSprite;
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
	float mousePosX;
	float mousePosY;
	float buttonPosX;
	float buttonPosY;

	App::GetMousePos(mousePosX, mousePosY);
	m_sprite->GetPosition(buttonPosX, buttonPosY);

	if (mousePosX > buttonPosX - m_sprite->GetWidth() / 2.0f && mousePosX < buttonPosX + m_sprite->GetWidth() / 2.0f
		&& mousePosY > buttonPosY - m_sprite->GetHeight() / 2.0f && mousePosY < buttonPosY + m_sprite->GetHeight() / 2.0f)
		return true;
	else
		return false;
}




