// Projet 2048 C++.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Case.h"
#include "Grid.h"
#include "test.h"
#include "Window.h"
#include "GameObject.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <conio.h>
#include <SDL.h>
#include <SDL_image.h>



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


int main(int argc, char* argv[])
{

    Test* oTest = new Test();
    oTest->left();
    oTest->right();
    oTest->up();
    oTest->down();
    oTest->merge();
    oTest->loose();
    oTest->win();
    delete oTest;

   

    

    

    
    
     Window* oWindow = new Window();
   
   
     Grid* oGrid = new Grid();

     srand((unsigned int)time(0));
     oGrid->boxPosition();
     oGrid->boxPosition();
        
     vector<int> valueArray(16);
        
     valueArray = oGrid->arrayValue();

        
        
        
      oWindow->displayGrid(valueArray);
        

        //EVENT
        SDL_Event event;
        bool quit = false;

        //GAMELOOP
        while (quit == false)
        {
            //EVENT
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    quit = true;

                }
                else
                {
                    if (event.type == SDL_KEYDOWN)
                    {
                        if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                        {
                            oGrid->boxMove(3);
                            oGrid->boxMerge(3);
                            oGrid->boxMove(3);
                            vector<int> listeVide = oGrid->getCellEmptyList();
                            int const taille(listeVide.size());
                            if (taille != 0)
                            {
                                oGrid->boxPosition();
                            }

                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                        {
                            oGrid->boxMove(4);
                            oGrid->boxMerge(4);
                            oGrid->boxMove(4);
                            vector<int> listeVide = oGrid->getCellEmptyList();
                            int const taille(listeVide.size());
                            if (taille != 0)
                            {
                                oGrid->boxPosition();
                            }

                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                        {
                            oGrid->boxMove(1);
                            oGrid->boxMerge(1);
                            oGrid->boxMove(1);
                            vector<int> listeVide = oGrid->getCellEmptyList();
                            int const taille(listeVide.size());
                            if (taille != 0)
                            {
                                oGrid->boxPosition();
                            }

                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                        {
                            oGrid->boxMove(2);
                            oGrid->boxMerge(2);
                            oGrid->boxMove(2);
                            vector<int> listeVide = oGrid->getCellEmptyList();
                            int const taille(listeVide.size());
                            if (taille != 0)
                            {
                                oGrid->boxPosition();

                            }

                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                        {
                            oWindow->~Window();
                            quit = SDL_TRUE;


                        }
                    }
                }


            }
            //UPDATE
            std::cout << std::endl;
            oGrid->display();
            std::cout << std::endl;
            if (oGrid->checkWin() == true)
            {
                system("cls");
                oGrid->display();
                std::cout << "You win !";
                while (event.key.keysym.scancode != SDL_SCANCODE_ESCAPE)
                {
                    GameObject* oGameObjectBack = new GameObject(0, 0, 200, 300, "img/F1.jpg", oWindow->m_renderer);
                    oGameObjectBack->drawGameObject(oWindow->m_renderer);
                    delete oGameObjectBack;
                    GameObject* oGameObject = new GameObject(250, 150, 200, 300, "img/win.png", oWindow->m_renderer);
                    oGameObject->drawGameObject(oWindow->m_renderer);
                    delete oGameObject;
                    oWindow->display();

                    while (SDL_PollEvent(&event))
                    {

                        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                        {

                            oWindow->~Window();

                            quit = SDL_TRUE;

                        }
                    }
                }
            }
            if (oGrid->checkLoose() == true)
            {
                std::cout << "You Loose !";
                while (event.key.keysym.scancode != SDL_SCANCODE_ESCAPE)
                {
                    GameObject* oGameObjectBack = new GameObject(0, 0, 200, 300, "img/F1.jpg", oWindow->m_renderer);
                    oGameObjectBack->drawGameObject(oWindow->m_renderer);
                    delete oGameObjectBack;
                    GameObject* oGameObject = new GameObject(560, 340, 200, 300, "img/fail.png", oWindow->m_renderer);
                    oGameObject->drawGameObject(oWindow->m_renderer);
                    delete oGameObject;
                    oWindow->display();

                    while (SDL_PollEvent(&event))
                    {

                        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                        {

                            oWindow->~Window();

                            quit = SDL_TRUE;

                        }
                    }
                }
            }
            valueArray = oGrid->arrayValue();
            oWindow->displayGrid(valueArray);


        }
    
    
    
    
    
        return 0;
    
}
