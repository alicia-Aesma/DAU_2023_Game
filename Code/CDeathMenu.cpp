#include "stdafx.h"
#include "CDeathMenu.h"
#include "CButton.h"
#include "InfiniteScroller.h"
#include "Onclick.h"
#include "../App/app.h"

#define PATH_MENU_SPRITE "..//Asset//Sprites//UI//Menu//"
#define BOTTOM_TOP_MARGIN_SCREEN 300.0f

using namespace InfiniteScroller;

CDeathMenu::CDeathMenu()
{

	//init play button sprite
	CSimpleSprite* sprite = App::CreateSprite(PATH_MENU_SPRITE "Button_Continue.png", 1, 1);
	sprite->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, BOTTOM_TOP_MARGIN_SCREEN);
	//init overlap of play button sprite
	CSimpleSprite* spriteOverlap = App::CreateSprite(PATH_MENU_SPRITE "Button_Continue_Overlap.png", 1, 1);
	spriteOverlap->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, BOTTOM_TOP_MARGIN_SCREEN);
	//init play button
	m_returnMenu = new CButton(sprite, spriteOverlap, &OpenMenu);
	//init sprite GameOver
	m_textGameOver = App::CreateSprite(PATH_MENU_SPRITE "Text_Game_Over.png", 1, 1);
	m_textGameOver->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT - BOTTOM_TOP_MARGIN_SCREEN );
}

CDeathMenu::~CDeathMenu()
{
	SAFE_DELETE(m_returnMenu);
}

void InfiniteScroller::CDeathMenu::Display()
{
	m_returnMenu->Display();
	//display text "Game Over" in red
	m_textGameOver->Draw();
}

void InfiniteScroller::CDeathMenu::Input()
{
	if (App::IsKeyPressed(MOUSEEVENTF_LEFTDOWN))
	{
		m_returnMenu->OnClick();
	}
}
