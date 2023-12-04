#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* foodREF);
        ~Player();
    
        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption();
        void increasePlayerLength();
        // after inserting the head but before removing the tail 
        //- check if it collides with food
        // if yes icrement the score, generate new food and do not remove tail
        // otherwise remove tail and move on (ignore)

        //Self collision check
        // if self collision set loseflag and exit to true (through GM)
        //
        //Lost = display lost message (self collision)
        // otherwise; display endgame message only

    private:
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        Food* refood;
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
}; 

#endif