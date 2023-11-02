#include "Window.h"
#include "GameObject.h"
#include "Case.h"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

Window::Window()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow("titre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    

    
    

        
       


}
void Window::display()
{
    
    SDL_RenderPresent(m_renderer);
   
    clear();
    
}


void Window::displayGrid(vector<int> arrayValue)
{
    int positionX = 0;
    int positionY = 0;
    const char* image = "img/0.png";
    GameObject* oGameObjectBack = new GameObject(0, 0, 200, 300, "img/F1.jpg", m_renderer);
    oGameObjectBack->drawGameObject(m_renderer);
    delete oGameObjectBack;
    for (int compteur = 0; compteur < 16; compteur++)
    {
        
        if (compteur < 4)
        {
            positionY = 340;
            
        }
        else if (compteur > 3 and compteur < 8)
        {
            positionY = 440;
            
        }
        else if (compteur > 7 and compteur < 12)
        {
            positionY = 540;
            
        }
        else if (compteur > 11)
        {
            positionY = 640;
            
        }

        if (compteur == 0 or compteur == 4 or compteur == 8 or compteur == 12)
        {
            positionX = 760;

        }
        else if (compteur == 1 or compteur == 5 or compteur == 9 or compteur == 13)
        {
            positionX = 860;

        }
        else if (compteur == 2 or compteur == 6 or compteur == 10 or compteur == 14)
        {
            positionX = 960;

        }
        else if (compteur == 3 or compteur == 7 or compteur == 11 or compteur == 15)
        {
            positionX = 1060;

        }
        if (arrayValue[compteur] == 0)
        {
            image = "img/0.png";
            
        }
        else if (arrayValue[compteur] == 2)
        {
            
            
            image = "img/2.png";
        }
        else if (arrayValue[compteur] == 4)
        {
            
            image = "img/4.png";
        }
        else if (arrayValue[compteur] == 8)
        {
            
            image = "img/8.png";
            
        }
        else if (arrayValue[compteur] == 16)
        {

            image = "img/16.png";

        }
        else if (arrayValue[compteur] == 32)
        {

            image = "img/32.png";

        }
        else if (arrayValue[compteur] == 64)
        {

            image = "img/64.png";

        }
        else if (arrayValue[compteur] == 128)
        {

            image = "img/128.png";

        }
        else if (arrayValue[compteur] == 256)
        {

            image = "img/256.png";

        }
        else if (arrayValue[compteur] == 512)
        {

            image = "img/512.png";

        }
        else if (arrayValue[compteur] == 1024)
        {

            image = "img/1024.png";

        }
        else if (arrayValue[compteur] == 2048)
        {

            image = "img/2048.png";

        }
        
        GameObject* oGameObject = new GameObject(positionX, positionY, 200, 300, image, m_renderer);
        oGameObject->drawGameObject(m_renderer);
        delete oGameObject;
        
        
        
    }
    
    display();
}

void Window::clear()
{
    SDL_RenderClear(m_renderer);
}







