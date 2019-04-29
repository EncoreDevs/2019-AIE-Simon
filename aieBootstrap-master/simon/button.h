#pragma once
#include "Renderer2d.h"
#include "Font.h"

class button
{
public:
	button(const char* buttonText, float x, float y, float width, float height);
	~button();

	void draw_blue(aie::Renderer2D* renderer);
	void draw_red(aie::Renderer2D* renderer);
	void draw_green(aie::Renderer2D* renderer);
	void draw_yellow(aie::Renderer2D* renderer);
	bool update();

private:
	//Font and text for the button
	aie::Font* m_font;
	char m_buttonText[80];

	//Button's position, width and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;

	//Calculating the centred text position is a bit fiddly.
	float textWidth; 
	float textHeight;
	float centredPosX;
	float centredPosY;
};