#include "simonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "dynamicarray.h"
#include <iostream>
#include <random>
#include <time.h>

simonApp::simonApp() {

}

simonApp::~simonApp() {

}

bool simonApp::startup() {
	srand(time(NULL));
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
	delete red_button;
	delete green_button;
	delete yellow_button;

}

void simonApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	//Unsure if this should be in the update or in the draw section of the program.
	
	int gamesturns = 0;
	int simon = 0;

	for (int i = gamesturns; i < gamesturns; ++i)
	{
		if (i == gamesturns)
		{
			gamesturns++;
		}
		simon = rand() % 4 + 1;
		
		SimonGame->push(simon, i);
		/* if the player gets correct reset loop and add 1 to gameturns variable and then overwrite the arrays intital value and continue
		if the player fails the sequence break the loop and display a you lose screen with a replay and exit button.
		the loop should create values until the loop criteria is met.
		the loop criteria should be changed if the player is successful in recreating the pattern.
		*/
	}

}

void simonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();


	// conditional renders
	
	

	

	// draw your stuff here!

	blue_button->draw_blue(m_2dRenderer);

	red_button->draw_red(m_2dRenderer);

	green_button->draw_green(m_2dRenderer);

	yellow_button->draw_yellow(m_2dRenderer);

	// changing button if it is clicked
	if (blue_button->update())
	{
		//Replace this with whatever the button should do.
		blue_button->selected_blue(m_2dRenderer);
		std::cout << "Blue clicked" << std::endl;
	}
	if (red_button->update())
	{
		red_button->selected_red(m_2dRenderer);
		//Replace this with whatever the button should do.
		std::cout << "Red clicked" << std::endl;
	}
	if (green_button->update())
	{
		//Replace this with whatever the button should do.
		std::cout << "Green clicked" << std::endl;
		green_button->selected_green(m_2dRenderer);
	}
	if (yellow_button->update())
	{
		//Replace this with whatever the button should do.
		std::cout << "Yellow clicked" << std::endl;
		yellow_button->selected_yellow(m_2dRenderer);
	}

	

	

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();


}