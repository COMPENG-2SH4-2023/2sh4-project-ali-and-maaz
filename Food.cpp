#include "Food.h"
#include "MacUILib.h"


Food::Food(GameMechs* GMRef)
{
    gmref = GMRef;
    srand(static_cast<unsigned>(time(NULL)));
    foodPos.setObjPos(1,1, 'o');
}

Food::~Food()
{
    delete gmref;
}

// do you need a destructor?


void Food::generateFood(objPosArrayList* blockOff){
	int size = blockOff->getSize();
    int i;
    objPos face;  // holding the pos information of the current head
    for (i = 0; i < size; i++){
        blockOff->getElement(face, i);
        if (face.isPosEqual(&foodPos) == true){
            int x_cord = 1 + rand() % (gmref->getBoardSizeX() - 2);
            int y_cord = 1 + rand() % (gmref->getBoardSizeY() - 2);
            foodPos.setObjPos(x_cord, y_cord, 'o');
        }
    }
  

    //generate random x and y coord and make sure the are not baorder or blockoff position
    // check x and y against 0 and board size x/y
    //use posequal method to comapre
}

void Food::getFoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos);
}


