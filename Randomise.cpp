#include "Common.h"

void getRandomColoursFromList(std::vector<colour> c, int n) 
{
	storeColours(c, true, false);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		// Add error checking in case there are less then the requested number of colours available
		int max = c.size();
		int num = rand() % max;
		showColour(c[num].ID, c[num].Name, c[num].Hex);
		c.erase(c.begin() + num);
	}
}