#include "cave.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;




enum class Richtung
{
	left,
	right,
	up,
	down
};

	char Hashtag  = '#';
	char Punkt = '.';
	char Start = 'S';
	char Ziel = 'X';

	
	Richtung Nextdirection;
	Richtung currentDirection = Richtung::right;
	
class Manager
{
public: 
	void UpdateDirection(Richtung currentDirection, char view[3][3])
	{
		cout << string(view[0],3) << endl;
		cout << string(view[1], 3) << endl;
		cout << string(view[2], 3) << endl << endl << endl;
		
		
		
		
		
		

		
		switch (currentDirection)
		{
		case Richtung::left:
			if (view[1][0] == Hashtag)
			{
				Nextdirection = Richtung::down;
			}
			else
			{
				Nextdirection = currentDirection;
			}
			break;
		case Richtung::right:
			if (view[1][2] == Hashtag)
			{
				
				Nextdirection = Richtung::up;
				//cout << string(view[1], 3) << endl;

				
			}
			else
			{
				Nextdirection = currentDirection;
			}
			break;
		case Richtung::up:
			if (view[0][1] == Hashtag)
			{
				Nextdirection = Richtung::left;
			}
			else
			{
				Nextdirection = currentDirection;
			}
			break;
		case Richtung::down:
			if (view[2][1] == Hashtag)
			{
				Nextdirection = Richtung::right;
			}
			else
			{
				Nextdirection = currentDirection;
			}
			break;
		}
		return;
	}

};

	Manager manager;
void findExit(int subtask, char fieldOfView[3][3])
{
	
	
	

	// Implementiere deine Loesung hier
	
	// Du kannst mit left(), right(), up() und down() 
	// Dr. Rainer steuern. Das fieldOfView Array
	// aktualisiert sich dadurch automatisch
	while (true)
	{
		
		//cout << fieldOfView[2, 2] << endl;
			
		manager.UpdateDirection(currentDirection, fieldOfView);
		currentDirection = Nextdirection;
		switch (currentDirection)
		{
		case Richtung::left:
				left();
				break;
		case Richtung::right:
				right();
				break;
		case Richtung::up:
				up();
				break;
		case Richtung::down:
				down();
				break;
		}
		
		
	}

}



