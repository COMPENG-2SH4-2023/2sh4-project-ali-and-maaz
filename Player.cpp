#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos temPos;
    temPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2,
                    mainGameMechsRef->getBoardSizeY() / 2,
                    '@');

    //no heap member yet - never used new keyboard
    playerPosList = new objPosArrayList();
    playerPosList.insertHead(temPos);
}


Player::~Player()
{
    // delete any heap members here
    // We can leave it empty for now.
    delete playerPosList;
}

void Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic       

    // Where do I get the input??  How do I check for inputs???
    // Hint1: definetly not be calling MacUILib_getChar()!!
    // Hint2: coordinate with your team member who's designing the game mechanism class 

    // IMPORTANT use -> for pointers and use dot operator for objects. 
    char input = mainGameMechsRef->getInput();

    switch(input) {
        case 'W':
        case 'w':
            if (myDir != DOWN)
                myDir = UP;
            break;

        case 'S':
        case 's':
            if (myDir != UP && myDir != UP)
                myDir = DOWN;
            break;

        case 'A':
        case 'a':
            if (myDir != RIGHT && myDir != LEFT)
                myDir = LEFT;
            break;

        case 'D':
        case 'd':
            if (myDir != LEFT && myDir != RIGHT)
                myDir = RIGHT;
            break;

        default:
            break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos currHead;  // holding the pos information of the current head
    playerPosList.getHeadElement(currHead);



    switch(myDir)
    {
        case UP:
            currentHead.y--;
            if(currentHead.y <= 0)
                currentHead.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;

        case DOWN:
            currentHead.y++;
            if(currentHead.y <= mainGameMechsRef->getBoardSizeY())
                currentHead.y = 1;
            break;

        case LEFT:
            currentHead.x--;
            if(currentHead.x <= 0)
                currentHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;

        case RIGHT:
            currentHead.x++;
            if(currentHead.x <= mainGameMechsRef->getBoardSizeX())
                currentHead.x = 1;
            break;

        case STOP:
        default:
            break;
    }

    // new current head should be inserted to the head of the list 
    playerPosList->insertHead(currHead);

    // then, remove tail
    playerPosList->removeTail();

}

