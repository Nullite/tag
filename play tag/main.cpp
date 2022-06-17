#include <iostream>
#include <string>
#include "variables.h"
#include "logic.h"
#include "bot.h"

int main()
{


    
    fillBoard();
    whosePlay = isUserPlay();
    setDifficulty(difficulty, minShuffle, maxShuffle);
    botShuffle();
    switch (whosePlay)
    {
    case true: 
        game();
        break;
    case false:
        botGame();
        break;
    }
    Sleep(1500);
    system("cls");
    congratulations(whosePlay);
}

