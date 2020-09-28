#include "Common.h"

std::string filename = "colours.txt";

std::vector<colour> _colours;

int main()
{
	int option;
	bool finished = false;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

	while (!finished)
	{
		std::cout << "----------\nHow many colours would you like? \nPlease enter [1] [2] or [3] below.\nEnter [4] to open the colour list\nEnter [0] below to exit the program. \n(Without the brackets)\n";
		std::cin >> option;

		switch(option)
		{
			case 0:
				finished = true;
				std::cout << "Ok bye";
				break;
			case 1:
				getRandomColoursFromList(_colours, 1);
				break;
			case 2:
				getRandomColoursFromList(_colours, 2);
				break;
			case 3:
				getRandomColoursFromList(_colours, 3);
				break;
			case 4:
				editColours(_colours);
				break;
			default:
				std::cout << "Please enter an integer from 1 to 3 or enter 0 to exit the program.\n";
				break;
		}
	}
}