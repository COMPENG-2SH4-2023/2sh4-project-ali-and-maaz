#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Food.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

// Declare pointers for game objects
Food* foodgen;
GameMechs* GM_PTR;
Player* myPlayer;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(GM_PTR->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // Create game objects
    GM_PTR = new GameMechs(26,13);
    foodgen = new Food(GM_PTR);
    myPlayer = new Player(GM_PTR, foodgen);
    
    // Initialize the player's initial position and making sure the food generated is not the same as the position of the snake
    objPosArrayList* playerPosList = myPlayer->getPlayerPos();
    foodgen->generateFood(playerPosList);


    
}

void GetInput(void)
{
   GM_PTR->getInput();
    
    // Check for the ESC key to exit the game
   if (GM_PTR->getInput() == 27)
        GM_PTR->setExitTrue();


}

void RunLogic(void)
{
    // Update player direction and move the player
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    // Clear input for the next frame so no double input
    GM_PTR->clearInput();

    

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    foodgen->getFoodPos(tempFoodPos);
    // Iterate through each position on the game board
    for(int i = 0; i < GM_PTR->getBoardSizeY(); i++)
    {
        for(int j = 0; j < GM_PTR->getBoardSizeX(); j++)
        {
            drawn = false;

            // Check if the current position is part of the player's body
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if(tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                
                }
            }

            // if player body was drawn, don't draw anything below.
            if(drawn) continue; 
            
            // Draw walls, food, or empty space
            if (i == 0 || i == GM_PTR -> getBoardSizeY() - 1 || j == 0 || j == GM_PTR -> getBoardSizeX() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if (i == tempFoodPos.y && j == tempFoodPos.x)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("\n");
    }
    // Display the player's score
    MacUILib_printf("Score: %d\n", GM_PTR->getScore());
    // Display "Game Over" if the player has lost
   
    }
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    if (GM_PTR->getLoseFlagStatus() == true){
        MacUILib_printf("Your Lose the Game, Total Points: %d \n\n", GM_PTR->getScore() );
    }

    MacUILib_uninit();
    
    // Delete dynamically allocated objects
    delete foodgen;
    delete GM_PTR;
    delete myPlayer;
}

