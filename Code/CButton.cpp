#include "stdafx.h"
#include "CButton.h"
#include "GameData.h"
#include "EGameState.h"
#include "App/app.h"

CButton::CButton(CSimpleSprite* sprite, CSimpleSprite* overlapSprite, EGameState gameState)
{
	m_sprite = sprite;
	m_overlapSprite = overlapSprite;
	m_gameState = new EGameState();
	*m_gameState = gameState;

}

CButton::~CButton()
{
	if (m_sprite != nullptr)
		delete m_sprite;

	if (m_overlapSprite != nullptr)
		delete m_overlapSprite;

	if (m_gameState != nullptr)
		delete m_gameState;
}

void CButton::Display()
{
	float mousePosX;
	float mousePosY;
	float buttonPosX;
	float buttonPosY;

	App::GetMousePos(mousePosX, mousePosY);
	m_sprite->GetPosition(buttonPosX, buttonPosY);

	if (mousePosX > buttonPosX - m_sprite->GetWidth() / 2.0f && mousePosX < buttonPosX + m_sprite->GetWidth() / 2.0f
		&& mousePosY > buttonPosY - m_sprite->GetHeight() / 2.0f && mousePosY < buttonPosY + m_sprite->GetHeight() / 2.0f)
		m_overlapSprite->Draw();
	else
		m_sprite->Draw();
}

void CButton::onMouseClick()
{
	GameData gameData;
	*gameData.GetInstance()->m_gameState = *(this->m_gameState);

}
