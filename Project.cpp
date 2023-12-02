#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

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
    foodgen = new Food();
    


    
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
    

    GM_PTR->clearInput();

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    objPos foodtest;
   
    foodgen->getFoodPos(foodtest);
    cout << foodtest.getSymbol() << endl;
    cout << "X: " << foodtest.x << ", Y: " << foodtest.y << endl;
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

