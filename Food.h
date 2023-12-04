#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


using namespace std;


class Food
{


    private:
        objPos foodPos;
        GameMechs* gmref;
        int X_range = 24;
        int Y_range= 11;
    public:
        Food(GameMechs* GMRef);
        ~Food();

        void generateFood(objPosArrayList* blockOff); //upgrade to something like this prolly Player(GameMechs* thisGMRef)
        // So it takes in every body part location as a block off  
        void getFoodPos(objPos &returnPos);
        


};

#endif
