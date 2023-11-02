#include "test.h"
#include "Grid.h"
#include "Window.h"
#include <iostream>

using namespace std;

Test::Test()
{
	
}

void Test::left()
{
	int resultat = 0;
	int tab[16] = 
	{
		2,0,0,2,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0
	};

	int endtab[16] = 
	{ 
		4,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0 
	};

	Grid* oGrid = new Grid();
	oGrid->createGridTest(tab);
	
	
	
	oGrid->boxMove(1);
	oGrid->boxMerge(1);
	resultat = oGrid->compareGridTest(endtab);
	



	if (resultat == 16)
	{
		std::cout <<"test 1 succes" << std::endl;
	}
	else
	{
		std::cout << "test 1 fail" << std::endl;
	}
}

void Test::right()
{

	int resultat = 0;
	int tab[16] = 
	{
		0,0,0,0,
		0,8,2,0,
		0,0,0,0,
		0,0,0,0 
	};

	int endtab[16] = { 0,0,0,0,
					   0,0,8,2,
					   0,0,0,0,
					   0,0,0,0 };

	Grid* oGrid = new Grid();
	oGrid->createGridTest(tab);

	oGrid->boxMove(2);
	oGrid->boxMerge(2);
	resultat = oGrid->compareGridTest(endtab);




	if (resultat == 16)
	{
		std::cout << "test 2 succes" << std::endl;
	}
	else
	{
		std::cout << "test 2 fail" << std::endl;
	}
	
}

void Test::up()
{
	Grid* oGrid = new Grid();
	int resultat = 0;
	int tab[16] = 
	{
		8,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,4 
	};

	int endtab[16] = 
	{ 
		8,0,0,4,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0 
	};

	oGrid->createGridTest(tab);

	oGrid->boxMove(3);
	oGrid->boxMerge(3);
	resultat = oGrid->compareGridTest(endtab);
	if (resultat == 16)
	{
		std::cout << "test 3 succes" << std::endl;
	}
	else
	{
		std::cout << "test 3 fail" << std::endl;
	}
	
}
void Test::down()
{
	Grid* oGrid = new Grid();
	int resultat = 0;
	int tab[16] = 
	{
		0,0,2,0,
		0,0,8,0,
		0,0,0,0,
		0,4,0,0 
	};

	int endtab[16] = 
	{ 
		0,0,0,0,
		0,0,0,0,
	    0,0,2,0,
		0,4,8,0 
	};
	
	
	oGrid->createGridTest(tab);
	oGrid->boxMove(4);
	oGrid->boxMerge(4);
	resultat = oGrid->compareGridTest(endtab);
	if (resultat == 16)
	{
		std::cout << "test 4 succes" << std::endl;
	}
	else
	{
		std::cout << "test 4 fail" << std::endl;
	}
	
}

void Test::merge()
{
	Grid* oGrid = new Grid();
	int resultat = 0;
	int tab[16] = 
	{
		4,4,4,4,
		4,4,4,4,
		4,4,4,4,
		4,4,4,4 
	};

	int endtab[16] = 
	{ 
		0,0,0,0,
		0,0,0,0,
		8,8,8,8,
		8,8,8,8 
	};

	Grid* oGrid1 = new Grid();

	oGrid->createGridTest(tab);
		
	
	

	oGrid->boxMove(4);
	oGrid->boxMerge(4);
	oGrid->boxMove(4);
	resultat = oGrid->compareGridTest(endtab);
	if (resultat == 16)
	{
		std::cout << "test 5 succes" << std::endl;
	}
	else
	{
		std::cout << "test 5 fail" << std::endl;
	}
	
	
	
}

void Test::loose()
{
	Grid* oGrid = new Grid();
	bool resultat;
	int tab[16] =
	{
		32,16,32,16,
		16,32,16,32,
		32,16,32,16,
		16,32,16,32
	};

	

	Grid* oGrid1 = new Grid();

	oGrid->createGridTest(tab);

	resultat = oGrid->checkLoose();


	
	
	if (resultat == true)
	{
		std::cout << "test 6 succes" << std::endl;
	}
	else
	{
		std::cout << "test 6 fail" << std::endl;
	}



}

void Test::win()
{
	Grid* oGrid = new Grid();
	bool resultat;
	int tab[16] =
	{
		0,2048,32,16,
		0,1024,16,32,
		0,1024,32,16,
		0,1024,16,32
	};



	Grid* oGrid1 = new Grid();

	oGrid->createGridTest(tab);

	resultat = oGrid->checkWin();




	if (resultat == true)
	{
		std::cout << "test 7 succes" << std::endl;
	}
	else
	{
		std::cout << "test 7 fail" << std::endl;
	}
}

Test::~Test()
{

}