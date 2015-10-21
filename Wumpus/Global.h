#pragma once
#include "Bats.h"
#include "Pitfall.h"
#include "Player.h"
#include "Wumpus.h"
#include "Consts.h"
#include "Gamestate.h"
#include <cstring>
#include <fstream>
using namespace std;

extern void setGame();

extern Bats bats[2];
extern Player player;
extern Wumpus wumpus;
extern pitFall pitfall[4];
                            // 0         1          2           3         4         5          6          7         8           9           10           11          12           13          14          15          16           17          18           19        20
const int rooms[21][3] = { {0,0,0},  { 5,8,2 },{ 1,10,3 },{ 2,12,4 },{ 3,14,5 },{ 4,1,6 },{ 5,15,7 },{ 6,8,17 },{ 1,7,9 },{ 8,18,10 },{ 9,2,11 },{ 19,10,12 },{ 11,13,3 },{ 12,20,14 },{ 15,13,4 },{ 14,16,6 },{ 15,17,20 },{ 7,16,18 },{ 17,9,19 },{ 18,11,20 },{ 19,16,13 } };
