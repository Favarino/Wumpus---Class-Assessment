#include "Consts.h"
#include <iostream>
#include <fstream>

// Simple selection menu with some security.
STATE mainMenu()
{
	system("cls");
	std::cout << "Welcome to the main menu!" << std::endl;
	std::cout << "1: Start new game" << std::endl;
	std::cout << "2: Splash Screen" << std::endl;
	std::cout << "3: Exit Game" << std::endl;
	std::cout << "4: Check last scores" << std::endl;

	switch (getNumValid(1, 4))
	{
	case 1: return PLAY; //return will break the state.
	case 2: return INIT;
	case 3: return EXIT;
	case 4: return SCORES;
	}
}

// Presents a welcome screen
void splash()
{
	system("cls");
	std::cout << "Get ready to HUNT SOME WUMPUS" << std::endl;
	system("pause");
	system("cls");
}

// presents a farewell screen
void byebye()
{
	system("cls");
	std::cout << "SHUTTING DOWN";
	system("pause");
}

void scores()
{
	system("cls");
	std::fstream fileStream;
	fileStream.open("file.txt", std::ios_base::in);
	char data[80];
	while (fileStream.getline(data, 80))
	{
		std::cout << data << std::endl;
	}
	system("pause");
}


int getNumValid(int min, int max)
{
	int select;

	do
	{
		std::cout << "Enter a valid number (" << min << "-" << max << "): ";
		std::cin >> select;

		if (std::cin.fail() || select < min || select > max)
		{
			std::cin.clear();			//clears the input buffer
			std::cin.ignore(80, '\n');	//resets the input buffer
			std::cout << "Invalid entry." << std::endl;
		}
		else break; //stop looping if the input was valid
	} while (true);

	return select;
}