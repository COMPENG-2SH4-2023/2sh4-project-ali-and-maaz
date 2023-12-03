#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

objPos myPos;

bool exitFlag;
Food* foodgen;
GameMechs* GM_PTR;


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

    GM_PTR = new GameMechs(26,13);
    foodgen = new Food(GM_PTR);

   myPlayer = new Player(GM_PTR, foodgen);
    
    // this a makeshift setup so I don't have to touch generateItem yet.
    // you ned to do this yourself : )
    objPos tempPos{-1, -1, o};
    GM_PTR->generateFood(temPos);


    
}

void GetInput(void)
{
   GM_PTR->getInput();

   if (GM_PTR->getInput() == 27)
            GM_PTR->setExitTrue();
            objPos playertest;
    if (GM_PTR->getInput() == '1'){
        foodgen->generateFood(playertest);

    }
   



}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer_>movePlayer();

    GM_PTR->clearInput();

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    getFoodPos(tempFoodPos);

    for(int i = 0; i < GM_PTR->getBoardSizeY(); i++)
    {
        for(int j = 0; j < GM_PTR->getBoardSizeX(); j++)
        {
            drawn = false;

            // iterate through every element in thelist
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

            if(drawn) continue; // if player body was drawn, don't draw anything below.

            if (i == 0 || i == myGM -> getBoardSizeY() - 1 || j == 0 || j == myGM -> getBoardSizeX() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if (i == foodItemPos.y && j == foodItemPos.x)
            {
                MacUILib_printf("%c", foodItemPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("\n");
    }
    // MacUILib_printf("Object: <%d, %d, with %c\n", myPos.x, myPos.y,myPos.symbol);
    // objPos foodtest;
   
    // foodgen->getFoodPos(foodtest);
    // cout << foodtest.getSymbol() << endl;
    // cout << "X: " << foodtest.x << ", Y: " << foodtest.y << endl;
}
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
    delete GM_PTR;
    delete foodgen;
}

