#include "simonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

simonApp::simonApp() {

}

simonApp::~simonApp() {

}

bool simonApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	blue_button = new button("Blue", 640, 550, 220, 130);
	red_button = new button("Red", 310, 360, 220, 130);
	green_button = new button("Green", 990, 360, 220, 130);
	yellow_button = new button("Yellow", 640, 150, 220, 130);
	return true;
}

void simonApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete blue_button;

}

void simonApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	//Updating Button
	if (blue_button->update())
	{
		//Replace this with whatever the button should do.
		std::cout << "Blue clicked" << std::endl;
	}
	if (red_button->update())
	{
		//Replace this with whatever the button should do.
		std::cout << "Red clicked" << std::endl;
	}
	if (green_button->update())
	{
		//Replace this with whatever the button should do.
		std::cout << "Green clicked" << std::endl;
	}
	if (yellow_button->update())
	{
		//Replace this with whatever the button should do.
		std::cout << "Yellow clicked" << std::endl;
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	
}

void simonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	// draw your stuff here!

	blue_button->draw_blue(m_2dRenderer);

	red_button->draw_red(m_2dRenderer);

	green_button->draw_green(m_2dRenderer);

	yellow_button->draw_yellow(m_2dRenderer);

	// conditional renders
	/*blue_button->selected_blue(m_2dRenderer);
	red_button->selected_red(m_2dRenderer);
	green_button->selected_green(m_2dRenderer);
	yellow_button->selected_yellow(m_2dRenderer);*/

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();

	
}