#include "stdafx.h"
#include "CScore.h"
#include "..//App/app.h"
#include <string>

using namespace InfiniteScroller;

void CScore::DisplayScore()
{
	//creates link to enemy's sprite
	std::string s = "Score : " + std::to_string((int)m_score);
	char* score = new char[s.length() + 1];
	strcpy(score, s.c_str());

	App::Print(APP_INIT_WINDOW_WIDTH/2.0f , APP_INIT_WINDOW_HEIGHT -125.0f, score);
}

void CScore::AddValueScore(float value)
{
	m_score += value;
}

void CScore::ResetScore()
{
	m_score = 0;
}

void CScore::UpdateScore(float deltaTime)
{
	m_score += m_scoreGain * (deltaTime / 1000.0f);
}
