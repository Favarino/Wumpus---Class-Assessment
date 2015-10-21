#include "Gamestate.h"
#include <random>
#include <iostream>
#include <fstream>
#include "Global.h"
void GameState::play()
{
	player.currentRoom = 1;
	player.arrowsLeft = 4;
	player.turns = 0;
	player.isAlive = true;
	player.wumpusIsAlive = true;
	//
	
	//
	
	wumpus.currentRoom = rand() % 19 + 1;

	for (int i = 0; i < 4; ++i)
	{
		pitfall[i].currentRoom = rand() % 19 + 1;
	}

	for (int i = 0; i < 2; ++i)
	{
		bats[i].currentRoom = rand() % 19 + 1;
	}
	//
	cout << "at the begining the wumpus is in room " << wumpus.currentRoom << endl;
	cout << "the pit falls are at " << pitfall[0].currentRoom << ", " << pitfall[1].currentRoom << ", " << pitfall[2].currentRoom << ", " << pitfall[3].currentRoom << endl;
	cout << "the bats are in " << bats[0].currentRoom << ", " << bats[1].currentRoom << endl;
	cout << "you have " << player.arrowsLeft << " arrows left" << endl;
	cout << "input your name " << endl;
	cin >> player.name;
	
	
}

/*
A simple guessing game.
*/
STATE GameState::update(/*float dt*/)
{

	char input;
	cout << player.name << " you are in room " << player.currentRoom << endl;
	cout << "would you like to move or shoot? " << endl << "m to move, s to shoot" << endl;
	cin >> input;
	if (input == 's')
	{
		player.shootArrows();
		player.turns += 1;
	}
	if (input == 'm')
	{
		player.evalNeighbors();
		player.movePlayer();
		player.roomReaction();
		player.turns += 1;
	}

	if (player.isAlive == false)
	{
		cout << "you lose...." << endl;
		std::fstream fileStream;
		fileStream.open("file.txt", std::ios_base::app);
		fileStream << player.name << " took " << player.turns << " turns to complete the game" << endl;
		system("pause");
		return MAIN;
	}

	if (player.wumpusIsAlive == false)
	{
		cout << "YOU WIN!!!!" << endl;
		std::fstream fileStream;
		fileStream.open("file.txt", std::ios_base::app);
		fileStream << player.name << " took " << player.turns << " turns to complete the game" << endl;
		fileStream.close();
		system("pause");
		return MAIN;
	}

	else return GAME;
}
