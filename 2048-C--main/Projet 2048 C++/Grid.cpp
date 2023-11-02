#include "Grid.h"
#include "GameObject.h"
#include "Window.h"

#include <SDL.h>

#include <iostream>
#include <vector>


using namespace std;

Grid::Grid()
{
	m_nombreDeCase = 16;
	m_Tableau = new Case[16];
	

}


void Grid::createGridTest(int tab[16])
{
	
	for (int compteur = 0; compteur < 16; compteur++)
	{
		m_Tableau[compteur].m_nombre = tab[compteur];
	}
}

int Grid::compareGridTest(int tab[16])
{
	int resultat = 0;
	for (int compteur = 0; compteur < 16; compteur++)
	{
		if (m_Tableau[compteur].m_nombre == tab[compteur])
		{
			resultat++;
		}
	}
	return resultat;
}

void Grid::display()
{
	for (int compteur = 0; compteur < 16; compteur++)
	{
		if (compteur % 4 == 0)
		{
			std::cout << std::endl;
		}
		if (m_Tableau[compteur].m_nombre == 0)
		{
			std::cout << "[    ]";
		}
		else if (m_Tableau[compteur].m_nombre == 2)
		{
			std::cout <<"[ 2  ]";
			
			
		}		
		else if (m_Tableau[compteur].m_nombre == 4)
		{
			std::cout << "[ 4  ]";
		}
		else if (m_Tableau[compteur].m_nombre == 8)
		{
			std::cout << "[ 8  ]";
		}
		else if (m_Tableau[compteur].m_nombre == 16)
		{
			std::cout << "[ 16 ]";
		}
		else if (m_Tableau[compteur].m_nombre == 32)
		{
			std::cout << "[ 32 ]";
		}
		else if (m_Tableau[compteur].m_nombre == 64)
		{
			std::cout << "[ 64 ]";
		}
		else if (m_Tableau[compteur].m_nombre == 128)
		{
			std::cout << "[ 128]";
		}
		else if (m_Tableau[compteur].m_nombre == 256)
		{
			std::cout << "[ 256]";
		}
		else if (m_Tableau[compteur].m_nombre == 512)
		{
			std::cout << "[ 512]";
		}
		else if (m_Tableau[compteur].m_nombre == 1024)
		{
			std::cout << "[1024]";
		}
		else if (m_Tableau[compteur].m_nombre == 2048)
		{
			std::cout << "[2048]";
		}			
	}
	
	
}

vector<int> Grid::getCellEmptyList()
{
	vector<int> listeVide;

	for (int compteur = 0; compteur < 16; compteur++)
	{
		if (m_Tableau[compteur].m_nombre == 0)
		{
			listeVide.push_back(compteur);
			
		}
	}

	return listeVide;
}

void Grid::boxPosition()
{
	vector<int> list = getCellEmptyList();
	int const taille(list.size());
	int positionList = std::rand() % taille;
	int position = list[positionList];
	int nombreProvisoire = std::rand() % 2;
	if (nombreProvisoire == 0)
	{
		m_Tableau[position].m_nombre = 2;
	}
	else
	{
		m_Tableau[position].m_nombre = 4;
	}
}


void Grid::boxMove(int choix)
{
	int compteurInverse = 15;
	for (int compteur = 0; compteur < 16; compteur++)
	{
		int i = 1;
		int y = 0;
		int j = 4;
		int z = 0;
		
		if (m_Tableau[compteurInverse].m_nombre != 0)
		{
			if (choix == 2)
			{
				if (compteurInverse != 3 and compteurInverse != 7 and compteurInverse != 11 and compteurInverse != 15)
				{
					while (m_Tableau[compteurInverse + i].m_nombre == 0 and compteurInverse + i != 4 and compteurInverse + i != 8 and compteurInverse + i != 12 and compteurInverse + i != 16)
					{

						m_Tableau[compteurInverse + i].m_nombre = m_Tableau[compteurInverse + y].m_nombre;
						m_Tableau[compteurInverse + y].m_nombre = 0;
						i++;
						y++;

					}

				}


			}

			if (choix == 4)
			{
				if (compteurInverse != 12 and compteurInverse != 13 and compteurInverse != 14 and compteurInverse != 15)
				{
					while (m_Tableau[compteurInverse + j].m_nombre == 0 and compteurInverse + j != 16 and compteurInverse + j != 17 and compteurInverse + j != 18 and compteurInverse + j != 19)
					{

						m_Tableau[compteurInverse + j].m_nombre = m_Tableau[compteurInverse + z].m_nombre;
						m_Tableau[compteurInverse + z].m_nombre = 0;
						j = j + 4;
						z = z + 4;

					}
				}

			}

		}
		compteurInverse--;
		if (m_Tableau[compteur].m_nombre != 0)
		{
			if (choix == 1)
			{
				if (compteur != 0 and compteur != 4 and compteur != 8 and compteur != 12)
				{
					

					while (m_Tableau[compteur - i].m_nombre == 0 and compteur - i != -1 and compteur - i != 3 and compteur - i != 7 and compteur - i != 11)
					{

						m_Tableau[compteur - i].m_nombre = m_Tableau[compteur - y].m_nombre;
						m_Tableau[compteur - y].m_nombre = 0;
						i++;
						y++;

					}


				}
			}

			if (choix == 3)
			{
				if (compteur != 0 and compteur != 1 and compteur != 2 and compteur != 3)
				{
					while (m_Tableau[compteur - j].m_nombre == 0 and compteur - j != -4 and compteur - j != -3 and compteur - j != -2 and compteur - j != -1)
					{

						m_Tableau[compteur - j].m_nombre = m_Tableau[compteur - z].m_nombre;
						m_Tableau[compteur - z].m_nombre = 0;
						j = j + 4;
						z = z + 4 ;

					}
				}

			}
		
		}
	}
}

void Grid::boxMerge(int choix)
{
	int compteurInverse = 15;
	for (int compteur = 0; compteur < 16; compteur++)
	{
		if (m_Tableau[compteur].m_nombre != 0)
		{
			if (choix == 1)
			{
				if (compteur != 0 and compteur != 4 and compteur != 8 and compteur != 12)
				{


					if (m_Tableau[compteur].m_nombre == m_Tableau[compteur - 1].m_nombre)
					{

						m_Tableau[compteur - 1].m_nombre = m_Tableau[compteur - 1].m_nombre * 2;
						m_Tableau[compteur].m_nombre = 0;



					}
				}

			}

			if (choix == 3)
			{
				if (compteur != 0 and compteur != 1 and compteur != 2 and compteur != 3)
				{

					if (m_Tableau[compteur].m_nombre == m_Tableau[compteur - 4].m_nombre)
					{

						m_Tableau[compteur - 4].m_nombre = m_Tableau[compteur - 4].m_nombre * 2;
						m_Tableau[compteur].m_nombre = 0;
						

					}
				}

			}

			

		}

		if (m_Tableau[compteurInverse].m_nombre != 0)
		{
			if (choix == 2)
			{
				if (compteurInverse != 3 and compteurInverse != 7 and compteurInverse != 11 and compteurInverse != 15)
				{
					if (m_Tableau[compteurInverse].m_nombre == m_Tableau[compteurInverse +1].m_nombre)
					{

						m_Tableau[compteurInverse + 1].m_nombre = m_Tableau[compteurInverse + 1].m_nombre * 2;
						m_Tableau[compteurInverse].m_nombre = 0;
					}

				}


			}

			if (choix == 4)
			{
				if (compteurInverse != 12 and compteurInverse != 13 and compteurInverse != 14 and compteurInverse != 15)
				{
					if (m_Tableau[compteurInverse + 4].m_nombre == m_Tableau[compteurInverse].m_nombre)
					{

						m_Tableau[compteurInverse + 4].m_nombre = m_Tableau[compteurInverse + 4].m_nombre * 2;
						m_Tableau[compteurInverse].m_nombre = 0;
						

					}
				}

			}

		}
		compteurInverse--;
	}
}

bool Grid::checkWin()
{
	for (int compteur = 0; compteur < 16; compteur++)
	{
		if (m_Tableau[compteur].m_nombre == 2048)
		{
			
			
			return true;
		}
	}
}


bool Grid::checkLoose()
{
	vector<int> list;
	for (int compteur = 0; compteur < 16; compteur++)
	{

		if (m_Tableau[compteur].m_nombre != 0)
		{
			list.push_back(1);
		}
	}
	int const taille(list.size());
	if (taille == 16)
	{
		vector<int> listPossible;
		for (int compteur = 0; compteur < 16; compteur++)
		{
			// On vérifie pour chaque case si les cases autour on la même valeur
			if (compteur == 5 or compteur == 6  or compteur == 9 or compteur == 10)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur + 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 4].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur + 4].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 0)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur + 1].m_nombre   and m_Tableau[compteur].m_nombre != m_Tableau[compteur + 4].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 1 or compteur == 2)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur + 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur + 4].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 1].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 3)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur - 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur + 4].m_nombre )
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 4 or compteur == 8)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur + 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur + 4].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 4].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 7 or compteur == 11)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur - 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur + 4].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 4].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 12)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur + 1].m_nombre  and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 4].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 15)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur - 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 4].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			if (compteur == 13 or compteur == 14)
			{
				if (m_Tableau[compteur].m_nombre != m_Tableau[compteur - 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur + 1].m_nombre and m_Tableau[compteur].m_nombre != m_Tableau[compteur - 4].m_nombre)
				{
					listPossible.push_back(1);
				}
			}
			
		}
		int const taille2(listPossible.size());
		if (taille2 == 16)
		{
			
			return true;
		}
		
	}
}


vector<int> Grid::arrayValue()
{
	
	
	vector<int> tableauValeur(16);

	for (int compteur = 0; compteur < 16; compteur++)
	{
		
		
		tableauValeur[compteur] = m_Tableau[compteur].m_nombre;
		
		
	}
	return tableauValeur;

}
Grid::~Grid()
{

}








	
	
	
	

	




