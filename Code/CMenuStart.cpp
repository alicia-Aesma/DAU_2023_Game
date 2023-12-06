#include "stdafx.h"
#include "CMenuStart.h"
#include "CButton.h"
#include "InfiniteScroller.h"
#include "../App/app.h"
#include "Onclick.h"

#define PATH_MENU_SPRITE "..//Asset//Sprites//UI//Menu//"

using namespace InfiniteScroller;

CMenuStart::CMenuStart()
{
	////Init button Play
	CSimpleSprite* sprite = App::CreateSprite(PATH_MENU_SPRITE "Button_Play.png", 1, 1);
	sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f + VERTICAL_DIST_BETWEEN_BTN);
	CSimpleSprite* spriteOverlap = App::CreateSprite(PATH_MENU_SPRITE "Button_Play_Overlap.png", 1, 1);
	spriteOverlap->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f + VERTICAL_DIST_BETWEEN_BTN);

	m_buttonPlay = new CButton(sprite, spriteOverlap, &ChangeGameStatetoPlay );


	////Init button quit
	sprite = App::CreateSprite(PATH_MENU_SPRITE "Button_Quit.png",1,1);
	sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f - VERTICAL_DIST_BETWEEN_BTN);
	spriteOverlap = App::CreateSprite(PATH_MENU_SPRITE "Button_Quit_Overlap.png",1,1);
	spriteOverlap->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f - VERTICAL_DIST_BETWEEN_BTN);

	m_buttonQuit = new CButton(sprite, spriteOverlap, &QuitGame);
}

CMenuStart::~CMenuStart()
{
	SAFE_DELETE(m_buttonPlay);
	SAFE_DELETE(m_buttonQuit);
}

void CMenuStart::Display()
{
	m_buttonPlay->Display();
	m_buttonQuit->Display();
}

void CMenuStart::Input()
{
	if (App::IsKeyPressed(MOUSEEVENTF_LEFTDOWN))
	{
		m_buttonPlay->OnClick();
		m_buttonQuit->OnClick();
	}
}
