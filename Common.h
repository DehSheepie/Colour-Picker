#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <time.h>

using namespace std;

extern std::string filename;

struct colour
{
	int ID;
	string Name;
	string Hex;
};


//Edit
void editColours(std::vector<colour> &colours);
void editColour(std::vector<colour> &c);
void addColour(vector<colour> &c);
void deleteColour(vector<colour> &v, int id);

// General Functions
void overwriteColours(std::vector<colour> &v);
void storeColour(std::vector<colour> &v, int ID, string Name, string Hex);
void showColour(int id, string cName, string hex);
void storeColours(std::vector<colour> &c, bool store, bool show); // bool-store, bool-show
//bool checkValidOption(string s, int min, int max); // Come back and complete this

// Randomiser
void getRandomColoursFromList(std::vector<colour> c, int i);
