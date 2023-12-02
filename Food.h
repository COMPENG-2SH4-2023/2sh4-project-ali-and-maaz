#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"


using namespace std;


class Food
{


    private:
        objPos foodPos;
        objPosArrayList* foodbucket = new objPosArrayList;
        int X_range = 24;
        int Y_range= 11;
    public:
        Food();
        ~Food(
            
        );

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
        


};

#endif
