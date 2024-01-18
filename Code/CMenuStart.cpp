#include "stdafx.h"
#include "CMenuStart.h"
#include "CButton.h"
#include "InfiniteScroller.h"
#include "../App/app.h"
#include "Onclick.h"

#define PATH_MENU_SPRITE "..//Asset//Sprites//UI//Menu//"
#define VERTICAL_DIST_BETWEEN_BTN 300.0f

using namespace InfiniteScroller;

CMenuStart::CMenuStart()
{
	//init play button sprite
	CSimpleSprite* sprite = App::CreateSprite(PATH_MENU_SPRITE "Button_Play.png", 1, 1);
	sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f + VERTICAL_DIST_BETWEEN_BTN);
	//init overlap of play button sprite
	CSimpleSprite* spriteOverlap = App::CreateSprite(PATH_MENU_SPRITE "Button_Play_Overlap.png", 1, 1);
	spriteOverlap->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f + VERTICAL_DIST_BETWEEN_BTN);
	//init play button
	m_buttonPlay = new CButton(sprite, spriteOverlap, &ChangeGameStatetoPlay );


	//init quit button sprite
	sprite = App::CreateSprite(PATH_MENU_SPRITE "Button_Quit.png",1,1);
	sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f );
	//init overlap of quit button sprite
	spriteOverlap = App::CreateSprite(PATH_MENU_SPRITE "Button_Quit_Overlap.png",1,1);
	spriteOverlap->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f);
	//init quit button
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
