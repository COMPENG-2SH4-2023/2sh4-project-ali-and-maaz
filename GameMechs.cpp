#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;


}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;

}




bool GameMechs::getExitFlagStatus()
{
    return exitFlag;

}

char GameMechs::getInput()
{
     if(MacUILib_hasChar()){
         input = MacUILib_getChar();
     }

     return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;

}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;

}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}

void GameMechs::setLoseFlag(){
    loseFlag = true;
}
        

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()

{
    input = 0;

}

int GameMechs::getScore(){
    return score;
}


void GameMechs::incrementScore(){
    score += 1;
}
