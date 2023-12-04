#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* foodREF)
{
    mainGameMechsRef = thisGMRef;
    refood = foodREF;
    myDir = STOP;


    // more actions to be included
    objPos temPos;
    temPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2,
                    mainGameMechsRef->getBoardSizeY() / 2,
                    '@');

    //no heap member yet - never used new keyboard
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(temPos);
}


Player::~Player()
{
    // delete any heap members here
    // We can leave it empty for now.
    delete playerPosList;
    delete mainGameMechsRef;
    delete refood;
}

objPosArrayList* Player::getPlayerPos()
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
            if (myDir != DOWN && myDir != UP)
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
    playerPosList->getHeadElement(currHead);




    switch(myDir)
    {
        case UP:
            currHead.y--;
            if(currHead.y <= 0)
                currHead.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;

        case DOWN:
            currHead.y++;
            if(currHead.y >= mainGameMechsRef->getBoardSizeY())
                currHead.y = 1;
            break;

        case LEFT:
            currHead.x--;
            if(currHead.x <= 0)
                currHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;

        case RIGHT:
            currHead.x++;
            if(currHead.x >= mainGameMechsRef->getBoardSizeX())
                currHead.x = 1;
            break;

        case STOP:
        default:
            break;
    }

    // new current head should be inserted to the head of the list 
    //collision aspect

    if (checkFoodConsumption() == true){
        increasePlayerLength();
        mainGameMechsRef->incrementScore();
    }
    else{
        playerPosList->insertHead(currHead);
        playerPosList->removeTail();

    }
    
    // if (checkSelfCollision() == true) {
    //     mainGameMechsRef->setExitTrue();
    //     mainGameMechsRef->setLoseFlag();          
    // }
    int i = 1;

    objPos check;
    
    while (i< playerPosList->getSize()){
        playerPosList->getElement(check, i);
        if ((currHead.x == check.x) && (currHead.y == check.y)) {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();            
        }
        i++;
    }


    // then, remove tail

}

bool Player::checkFoodConsumption(){
    objPos currentHead;  // holding the pos information of the current head
    playerPosList->getHeadElement(currentHead);

    objPos currfood;
    refood->getFoodPos(currfood);
    if (currentHead.x == currfood.x && currentHead.y == currfood.y){
        return true;
    }
    else{
        return false;
    }

}


void Player::increasePlayerLength(){
    objPos head;  // holding the pos information of the current head
    playerPosList->getHeadElement(head);
    playerPosList->insertHead(head);
    refood->generateFood(playerPosList);
}


