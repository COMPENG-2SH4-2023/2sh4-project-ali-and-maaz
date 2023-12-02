#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"

Food::Food()
{
    srand(static_cast<unsigned>(time(NULL)));
    foodPos.setObjPos(-1,-1, 'o');
}

Food::~Food()
{

}

// do you need a destructor?


void Food::generateFood(objPos blockOff){
	do {
        int x_cord = 1 + (rand() % X_range);
        int y_cord = 1 + (rand() % Y_range);
        foodPos.setObjPos(x_cord, y_cord, 'o');
    } while (blockOff.isPosEqual(&foodPos) == true);
  

    //generate random x and y coord and make sure the are not baorder or blockoff position
    // check x and y against 0 and board size x/y
    //use posequal method to comapre

}

void Food::getFoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos);
}


