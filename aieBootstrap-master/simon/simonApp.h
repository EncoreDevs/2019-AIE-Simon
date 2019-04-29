#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "button.h"

class simonApp : public aie::Application {
public:

	simonApp();
	virtual ~simonApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	button* blue_button;
	button* red_button;
	button* green_button;
	button* yellow_button;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};