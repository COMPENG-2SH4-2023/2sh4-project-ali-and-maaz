#include "Food.h"
#include "MacUILib.h"


Food::Food(GameMechs* GMRef)
{
    // Store a reference to the GameMechs object
    gmref = GMRef;
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(NULL)));
    // Set the initial position of the food to (1, 1) with the symbol 'o'
    foodPos.setObjPos(1,1, 'o');
}

Food::~Food()
{
    //no dynamic allocations to release
}



void Food::generateFood(objPosArrayList* blockOff){
	int size = blockOff->getSize();
    int i;
    
    // holding the pos information of the current head
    objPos face;  
    
    // The loop ensures that the generated food position is not in a blockOff position
    for (i = 0; i < size; i++){
        blockOff->getElement(face, i);
            
        // Check if the current blockOff position is the same as the foodPos
        if (face.isPosEqual(&foodPos) == true){
            
            // Generate random x and y coordinates within the board borders
            int x_cord = 1 + rand() % (gmref->getBoardSizeX() - 2);
            int y_cord = 1 + rand() % (gmref->getBoardSizeY() - 2);
            
            // Set the new position for the food
            foodPos.setObjPos(x_cord, y_cord, 'o');
        }
    }
  
}

void Food::getFoodPos(objPos &returnPos){
    returnPos.setObjPos(foodPos);
}


