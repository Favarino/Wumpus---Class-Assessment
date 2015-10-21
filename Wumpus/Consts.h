#pragma once


enum STATE { INIT, MAIN, PLAY, GAME, EXIT, SCORES };


// Presents options to start or exit the game
STATE mainMenu();

// Presents a welcome screen
void splash();

// presents a farewell screen
void byebye();

void scores();

int getNumValid(int min, int max); 
