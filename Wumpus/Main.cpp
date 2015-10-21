#include <iostream>
#include <string>
#include "Global.h"
#include <random>
#include <malloc.h>
#include <fstream>

using namespace std;

Player player;

Wumpus wumpus;

int playerPos;

Bats bats[2];
pitFall pitfall[4];

void setGame()
{
	player.currentRoom = 0;
	player.arrowsLeft = 4;
	player.isAlive = true;
	wumpus.currentRoom = rand() % 19 + 1;

	for (int i = 0; i < 4; ++i)
	{
		pitfall[i].currentRoom = rand() % 19 + 1;
	}

	for (int i = 0; i < 2; ++i)
	{
		bats[i].currentRoom = rand() % 19 + 1;
	}
	cout << "at the begining the wumpus is " << wumpus.currentRoom << endl;
	cout << "the pit falls are at " << pitfall[0].currentRoom << ", " << pitfall[1].currentRoom << ", " << pitfall[2].currentRoom << ", " << pitfall[3].currentRoom << endl;


}


int main()
{
	GameState g;
	STATE current = INIT;	// The start state

	while (true)
	{
		switch (current)
		{
		case INIT: splash();					// automatically moves to main menu, so it doesn't break!
		case MAIN: current = mainMenu(); break; // mainMenu returns which state we should move to.
		case PLAY: g.play();					// resets data to start a new game, doesn't need to break!
		case GAME: current = g.update(); break; // Update continuously until we return to main.
		case EXIT: byebye(); return 0;			// return breaks the while loop.
		case SCORES: scores();
		}
	}
}