#pragma once

class Player
{
public:
	int arrowsLeft;
	int currentRoom;
	int turns;
	char name[20];

	bool isAlive;
	bool wumpusIsAlive;

	void evalNeighbors();
	void movePlayer();
	void roomReaction();
	void shootArrows();
};