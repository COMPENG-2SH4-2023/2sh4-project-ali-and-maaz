#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

<<<<<<< HEAD
objPos myPos;

bool exitFlag;
=======
Food* foodgen;
GameMechs* GM_PTR;

>>>>>>> 3b6a4eab028c8402cdf900e2990b5a21a704e15e

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
    

<<<<<<< HEAD
    myPos.setObjPos(2 , 3, '@');

    exitFlag = false;
=======

    
>>>>>>> 3b6a4eab028c8402cdf900e2990b5a21a704e15e
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

<<<<<<< HEAD
    MacUILib_printf("Object: <%d, %d, with %c\n", myPos.x, myPos.y,myPos.symbol);
=======
    objPos foodtest;
   
    foodgen->getFoodPos(foodtest);
    cout << foodtest.getSymbol() << endl;
    cout << "X: " << foodtest.x << ", Y: " << foodtest.y << endl;
>>>>>>> 3b6a4eab028c8402cdf900e2990b5a21a704e15e
}
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

<<<<<<< HEAD
=======

void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
    delete GM_PTR;
    delete foodgen;
}

>>>>>>> 3b6a4eab028c8402cdf900e2990b5a21a704e15e
