#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* foodREF)
{
    // Store references to GameMechs and Food objects
    mainGameMechsRef = thisGMRef;
    refood = foodREF;
    
    // Set the initial direction to STOP
    myDir = STOP;


    // Set the initial position of the player's head
    objPos temPos;
    temPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2,
                    mainGameMechsRef->getBoardSizeY() / 2,
                    '@');

    // Initialize the player's position list with the head position
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(temPos);
}


Player::~Player()
{
    // Delete dynamically allocated object
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    // Update player direction based on user input

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
    // holding the postion information of the current head
    objPos currHead;  
    playerPosList->getHeadElement(currHead);

    // Move the head, wrapping around if it reaches the border
    switch(myDir)
    {
        case UP:
            currHead.y--;
            if(currHead.y <= 0)
                currHead.y = mainGameMechsRef->getBoardSizeY() - 2;
            break;

        case DOWN:
            currHead.y++;
            if(currHead.y >= mainGameMechsRef->getBoardSizeY() - 1)
                currHead.y = 1;
            break;

        case LEFT:
            currHead.x--;
            if(currHead.x <= 0)
                currHead.x = mainGameMechsRef->getBoardSizeX() - 2;
            break;

        case RIGHT:
            currHead.x++;
            if(currHead.x >= mainGameMechsRef->getBoardSizeX() - 1)
                currHead.x = 1;
            break;

        case STOP:
        default:
            break;
    }

    // Check for food consumption, increase length, and update the score
    if (checkFoodConsumption() == true){
        increasePlayerLength();
        mainGameMechsRef->incrementScore();
    }
    else{
        playerPosList->insertHead(currHead);
        playerPosList->removeTail();

    }
    
    // Check for self-collision
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
}

bool Player::checkFoodConsumption(){
    objPos currentHead;  // holding the pos information of the current head
    playerPosList->getHeadElement(currentHead);

    objPos currfood; //position of the food
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


