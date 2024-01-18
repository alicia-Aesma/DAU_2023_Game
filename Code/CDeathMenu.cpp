#include "stdafx.h"
#include "CDeathMenu.h"
#include "CButton.h"
#include "InfiniteScroller.h"
#include "Onclick.h"
#include "../App/app.h"

#define PATH_MENU_SPRITE "..//Asset//Sprites//UI//Menu//"
#define BOTTOM_MARGIN_SCREEN 300.0f

using namespace InfiniteScroller;

CDeathMenu::CDeathMenu()
{

	//init play button sprite
	CSimpleSprite* sprite = App::CreateSprite(PATH_MENU_SPRITE "Button_Play.png", 1, 1);
	sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, BOTTOM_MARGIN_SCREEN);
	//init overlap of play button sprite
	CSimpleSprite* spriteOverlap = App::CreateSprite(PATH_MENU_SPRITE "Button_Play_Overlap.png", 1, 1);
	spriteOverlap->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, BOTTOM_MARGIN_SCREEN);
	//init play button
	m_returnMenu = new CButton(sprite, spriteOverlap, &OpenMenu);
}

CDeathMenu::~CDeathMenu()
{
	SAFE_DELETE(m_returnMenu);
}

void InfiniteScroller::CDeathMenu::Display()
{
	m_returnMenu->Display();
}

void InfiniteScroller::CDeathMenu::Input()
{
	if (App::IsKeyPressed(MOUSEEVENTF_LEFTDOWN))
	{
		m_returnMenu->OnClick();
	}
}
