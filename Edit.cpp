#include "Common.h"

void editColour(std::vector<colour> &c)
{
	int i;
	int option;
	std::cout << "Please enter the ID of the colour you wish to edit:\n";
	std::cin >> i;

	if (i >= 0 && i < c.size())
	{
		std::cout << "Select what you would like to edit:\nThe name [1]\nThe hex code [2]\nThe name and hex code [3]\n";
		std::cin >> option;

		switch (option)
		{
		case 3:
			std::cout << "Please enter the name of the colour below:\n";
			std::cin >> c[i].Name; // Need to add a function to edit the values
		case 2:
			std::cout << "Please enter the hex code of the colour below:\n";
			std::cin >> c[i].Hex;
			break;
		case 1:
			std::cout << "Please enter the name of the colour below:\n";
			std::cin >> c[i].Name; // Need to add a function to edit the values
			break;
		default:
			std::cout << "Please enter a value option.\n";
			editColour(c);
		}
	}
	else
	{
		std::cout << "Please enter a valid ID.\n";
		editColour(c);
	}
}

void deleteColour(vector<colour> &v, int id)
{
	std::vector<colour> newColours;
	for (colour& c : v)
	{
		if (c.ID != id)
		{
			newColours.push_back(c);
		}
	}
	v = newColours;
}

void addColour(vector<colour> &c)
{
	string name;
	string hex;
	std::cout << "Please enter the name of the colour:\n";
	std::cin >> name;
	std::cout << "Please enter the hex code of the colour:\n";
	std::cin >> hex;

	storeColour(c, 0, name, hex);
}

void editColours(std::vector<colour> &colours)
{
	int option;

	std::cout << "Please select an option from below:\nBack: [0]\nShow [1]\nAdd [2]\nEdit [3]\nDelete [4]\n";
	std::cin >> option;

	switch (option)
	{
		case 0: // Back
			break;
		case 1: // Show
			storeColours(colours, false, true);
			editColours(colours);
			break;
		case 2: // Add
			storeColours(colours, true, true);
			addColour(colours);
			overwriteColours(colours);
			break;
		case 3: // Edit
			storeColours(colours, true, true);
			editColour(colours);
			overwriteColours(colours);
			break;
		case 4: // Delete
			int colourID;
			storeColours(colours, true, true);
			std::cout << "Please select a colour to delete by ID:\n";
			std::cin >> colourID;
			deleteColour(colours, colourID);
			overwriteColours(colours);
			break;

	}
	colours.clear();
}