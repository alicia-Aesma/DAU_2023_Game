#include "stdafx.h"
#include "CBackground.h"
#include "App/app.h"
#include <string>

void CBackground::DisplayBackground()
{
	//allows to move all the layers of the backgrounds
	for (int i = 11; i >= 0; i--)
	{
		//allows to retrieve the position of my background layer
		float x;
		float y;
		m_layer[i]->GetPosition(x, y);

		if (!m_isPause)
		{

			//moves the x position of the layer to the left
			x += -1 * m_currentSpeed * m_layerSpeed[i];

			//if the layer leaves the screen completely, positions it at the position of the layer following it
			if (x <= -1.0f * APP_INIT_WINDOW_WIDTH / 2.0f)
				x += APP_INIT_WINDOW_WIDTH;
		}

		//displays the layer
		m_layer[i]->SetPosition(x, y);
		m_layer[i]->Draw();

		//displays the layer a second time following the first
		m_layer[i]->SetPosition(x + APP_INIT_WINDOW_WIDTH, y);
		m_layer[i]->Draw();
		m_layer[i]->SetPosition(x, y);

	}

}

void CBackground::UpdateBackground(float deltaTime)
{
	//Updates the speed of my backgrounds according to the frame rate
	m_currentSpeed = m_referenceSpeed * deltaTime;
}

CBackground::CBackground()
{
	for (int i = 0; i < NB_BACKGROUND_LAYER; i++)
	{
		std::string s = "..//Asset//Sprites//Background//Layer_" + std::to_string(i) + ".png";
		char* path = new char[s.length() + 1];
		strcpy(path, s.c_str());
		m_layer[i] = App::CreateSprite(path, 1, 1);
		m_layer[i]->SetPosition(APP_INIT_WINDOW_WIDTH / 2.0f, APP_INIT_WINDOW_HEIGHT / 2.0f);

	}

	m_isPause = true;
	m_referenceSpeed = 0.12f;
	m_currentSpeed = m_referenceSpeed;

	m_layerSpeed[0] = 1;
	m_layerSpeed[1] = 1;
	m_layerSpeed[2] = 1;
	m_layerSpeed[3] = 1;
	m_layerSpeed[4] = 1;
	m_layerSpeed[5] = 0.8f;
	m_layerSpeed[6] = 0.6f;
	m_layerSpeed[7] = 0.4f;
	m_layerSpeed[8] = 0.4f;
	m_layerSpeed[9] = 0.2f;
	m_layerSpeed[10] = 0.05f;
	m_layerSpeed[11] = 0;
}


CBackground::~CBackground()
{
	if (m_layer != nullptr)
		for (int i = 0; i < NB_BACKGROUND_LAYER; i++)
			delete m_layer[i];
}
