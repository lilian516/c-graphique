#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"

using namespace std;

class GameObject
{
public:

	int m_positionX;
	int m_positionY;
	int m_width;
	int m_length;
	

	
	SDL_Texture* texture;

	GameObject(int positionX, int positionY, int width, int length, const char* image_path, SDL_Renderer* renderer);

	void drawGameObject(SDL_Renderer* renderer);




	
	~GameObject();
};