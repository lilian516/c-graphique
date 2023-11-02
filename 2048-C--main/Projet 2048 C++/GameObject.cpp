#include "GameObject.h"

#include <iostream>

using namespace std;

GameObject::GameObject(int positionX, int positionY, int width, int length, const char* image_path, SDL_Renderer* renderer)
{
	m_positionX = positionX;
	m_positionY = positionY;	
	m_width = width;
	m_length = length;
	SDL_Surface* image = IMG_Load(image_path);
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	
	
}
GameObject::~GameObject()
{

}

void GameObject::drawGameObject(SDL_Renderer* renderer)
{
	SDL_Rect oPosition;
	oPosition.x = m_positionX;
	oPosition.y = m_positionY;
	//On récupérer la taille de la Texture (SDL_Texture) 
	SDL_QueryTexture(texture, NULL, NULL, &oPosition.w, &oPosition.h);

	SDL_RenderCopy(renderer, texture, NULL, &oPosition);
}