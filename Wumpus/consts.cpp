#pragma once

/*
State-less application states- they don't need to store data,
so they could just be functions.

the Enum here is an enumeration of constants.
Under the hood, they are numbered: 0, 1, 2, 3...
They are useful for organizing switches. While they are
considered a type, mathematically they behave like unsigned
integers.
*/

enum STATE { INIT, MAIN, PLAY, GAME, EXIT };


// Presents options to start or exit the game
STATE mainMenu();

// Presents a welcome screen
void splash();

// presents a farewell screen
void byebye();

int getNumValid(int min, int max);