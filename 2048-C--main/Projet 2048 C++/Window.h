#pragma once
#include "Grid.h";
#include <SDL.h>
class Window {
public:

    SDL_Renderer* m_renderer;
    SDL_Window* m_window;
    

    Window();
       
    

    void display();
    void displayGrid(vector<int> arrayValue);
    void clear();



        
        


};



