#pragma once

#include "Case.h";
#include "Window.h";
#include <SDL.h>

#include <vector> 

using namespace std;

class Grid
{
public:
	int m_nombreDeCase;
	
	Case* m_Tableau;

	
	
	

	Grid();
	~Grid();

	
	void display();
	
	
	void boxMove(int choix);
	vector<int> getCellEmptyList();
	void boxPosition();
	void boxMerge(int choix);
	bool checkWin();
	bool checkLoose();
	void createGridTest(int tab[16]);
	int compareGridTest(int tab[16]);
	vector<int>arrayValue();

	





};
