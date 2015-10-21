#include "Player.h"
#include "Global.h"
#include <iostream>

char input;
int tempinput = tempinput - 1;
int roomAmount;
int a, b, c, d;


void Player::evalNeighbors()
{


	for (int i = 0; i < 3; ++i)
	{
		// wumpus check
		if (wumpus.currentRoom == rooms[currentRoom][i])
		{
			cout << "The Wumpus is near" << endl;
		}

		// pitfall check
		for (int k = 0; k < 4; ++k)
		{
			if (pitfall[k].currentRoom == rooms[currentRoom][i])
			{
				cout << "There is a pitfall near" << endl;
			}
		}

		// bat check
		for (int j = 0; j < 2; ++j)
		{
			if (bats[j].currentRoom == rooms[currentRoom][i])
			{
				cout << "There are bats near" << endl;
			}
		}
	}
}

void Player::roomReaction()
{
	// wumpus check
	if (wumpus.currentRoom == player.currentRoom)
	{
		player.isAlive = false;
		cout << "you have died from the wumpus" << endl;
	}

	// pitfall check
	for (int i = 0; i < 4; ++i)
	{
		if (pitfall[i].currentRoom == currentRoom)
		{
			player.isAlive = false;
			cout << "you have died from a pit" << endl;
		}
	}

	// bat check
	for (int i = 0; i < 2; ++i)
	{
		if (bats[i].currentRoom == currentRoom)
		{
			currentRoom = rand() % 20 + 1;
			{
				cout << "you have been moved to room" << currentRoom << endl;
			}
		}
	}

}

void Player::movePlayer()
{

		cout << "where would you like to move? " << rooms[currentRoom][0] << ", " << rooms[currentRoom][1] << " or " << rooms[currentRoom][2] << endl;
		cin >> tempinput;
		currentRoom = tempinput;
		cout << "you have moved to room " << tempinput << endl;
		
	
}

void Player::shootArrows()
{
	cout << "you have " << player.arrowsLeft << " arrows left" << endl;
	cout << "how many rooms would you like to shoot?" << endl;
	cin >> roomAmount;

	switch (roomAmount)
	{
	case 1:
		cout << "which room would you like to shoot? " << endl;
		cin >> a;
		cout << "you shoot room " << a << endl;
		if (wumpus.currentRoom == a)
		{
			cout << "you shot the wumpus!" << endl;
			player.wumpusIsAlive = false;
		}
		else if (player.currentRoom == a)
		{
			cout << "you shot yourself!" << endl;
			player.isAlive = false;
		}
		else
		{
			cout << "you didnt hit anything..." << endl;
		}
		arrowsLeft -= 1;
		break;
	case 2:
		cout << "which rooms would you like to shoot? " << endl;
		cin >> a >> b;
		cout << "you shoot rooms " << a << " and " << b << endl;
		if (wumpus.currentRoom == a || b)
		{
			cout << "you shot the wumpus!" << endl;
			player.wumpusIsAlive = false;
		}
		else if (player.currentRoom == a || b)
		{
			cout << "you shot yourself!" << endl;
			player.isAlive = false;
		}
		else
		{
			cout << "you didnt hit anything..." << endl;
		}
		arrowsLeft -= 2;
		break;
	case 3:
		cout << "which rooms would you like to shoot? " << endl;
		cin >> a >> b >> c;
		cout << "you shoot rooms " << a << ", " << b << " and " << c << endl;
		if (wumpus.currentRoom == a || b || c)
		{
			cout << "you shot the wumpus!" << endl;
			player.wumpusIsAlive = false;
		}
		else if (player.currentRoom == a || b || c)
		{
			cout << "you shot yourself!" << endl;
			player.isAlive = false;
		}
		else
		{
			cout << "you didnt hit anything..." << endl;
		}
		arrowsLeft -= 3;
		break;
	case 4:
		cout << "which rooms would you like to shoot? " << endl;
		cin >> a >> b >> c >> d;
		cout << "you shoot rooms " << a << ", " << b << ", " << c << " and " << d << endl;
		if (wumpus.currentRoom == a || b || c || d)
		{
			cout << "you shot the wumpus!" << endl;
			player.wumpusIsAlive = false;
		}
		else if (player.currentRoom == a || b || c || d)
		{
			cout << "you shot yourself!" << endl;
			player.isAlive = false;
		}
		else
		{
			cout << "you didnt hit anything..." << endl;
		}
		arrowsLeft -= 4;
		break;
	}
}
