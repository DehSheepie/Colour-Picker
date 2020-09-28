#include "Common.h"

bool checkStringIsInt(string s) // Will probably get deleted once I create checkValidOption
{
	if (s == "")
	{
		return false;
	}

	for (char& c : s)
	{
		if (isdigit(c) == false)
		{
			return false;
		}
	}

	return true;
}

void overwriteColours(vector<colour> &v)
{
	std::ofstream input;
	int count = 0;

	input.open(filename, std::ostream::trunc);

	if (!input.is_open())
	{
		return;
	}

	for (colour& c : v)
	{
		input << count << ":" << c.Name << "|" << c.Hex << endl;
		count++;
	}
}

void storeColour(vector<colour> &v, int ID, string Name, string Hex)
{
	// Adds all the attributes to the colour struct (from Common.h)
	colour c
	{
		ID,
		Name,
		Hex
	};

	v.push_back(c);
}

// The store bool is used to tell the function whether it should store the colours or not
// bool-store, bool-show
void storeColours(std::vector<colour> &c, bool store, bool show)
{
	std::ifstream input;

	input.open(filename);

	if (!input.is_open())
	{
		return;
	}

	while (input)
	{
		string idStr;
		string colourName;
		string hex;

		std::getline(input, idStr, ':');
		std::getline(input, colourName, '|');
		std::getline(input, hex);

		if (checkStringIsInt(idStr)) // This probably needs to be redone
		{
			int id = std::stoi(idStr); // function that takes a string and returns an int

			if (!input)
			{
				break;
			}
			if (show)
			{
				showColour(id, colourName, hex);
			}
			if (store)
			{
				storeColour(c, id, colourName, hex);
			}
		}
	}
	input.close();
}

void showColour(int id, string cName, string hex)
{
	cout << "ID: " << id << " | Colour: " << cName << " | Hex code: " << hex << endl;
}