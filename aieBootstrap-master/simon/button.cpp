#include "Input.h"
#include "button.h"
#include <iostream>
button::button(const char* buttonText, float x, float y, float width, float height)
{
	//Store the text that will appear on the button
	strcpy_s(m_buttonText, 80, buttonText);

	//Loada font use to display the text
	m_font = new aie::Font("../bin/font/consolas.ttf", 24);

	//Store the button's positon, width, height.
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;

	textWidth = m_font->getStringWidth(m_buttonText);
	textHeight = m_font->getStringHeight(m_buttonText);
	centredPosX = m_posX - (textWidth * 0.5f) + 2;
	centredPosY = m_posY - (textHeight * 0.5f) + 5;
}

button::~button()
{
	delete m_font;
}


//This Will Be Drawn Always
void button::draw_blue(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(0.0f, 0.0f, 0.7f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}
void button::draw_red(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(0.7f, 0.0f, 0.0f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}
void button::draw_green(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(0.0f, 0.7f, 0.0f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}
void button::draw_yellow(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(0.7f, 0.7f, 0.0f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}
//When The Number is Selected this will be drawn
void button::selected_blue(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(0.0f, 201.0f, 255.0f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}
void button::selected_red(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(255.0f, 0.0f, 0.7f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}
void button::selected_green(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(0.0f, 255.0f, 0.7f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}
void button::selected_yellow(aie::Renderer2D* renderer)
{
	//Draw a coloured box for the button background.
	renderer->setRenderColour(255.0f, 239.0f, 0.0f, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//Draw text on the button.
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);

}


bool button::update()
{
	aie::Input* input = aie::Input::getInstance();
	//Get mouse position
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();

	//Calculate the 4 sides of the button
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	float bottom = m_posY - (m_height * 0.5f);
	float top = m_posY + (m_height * 0.5f);
	//Check if the mouse is inside the box made by the 4 sides.
	if (mouseX > left && mouseX < right &&
		mouseY > bottom && mouseY < top)
	{
		//Return whether the mouse button is clicked while colliding
		return input->wasMouseButtonReleased(aie::INPUT_MOUSE_BUTTON_LEFT);
	}
	return false;

}