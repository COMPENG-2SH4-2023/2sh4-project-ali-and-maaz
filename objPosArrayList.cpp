#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; //200 elements on the heap
    listSize = 0;  //no valid element in the list upon startup
    ArrayCapacity = ARRAY_MAX_CAP;  //array capacity should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;  // delete[] aList removes all the instances in the array
}                    // delete aList will only remove the first instance/element as it points to the first instance 

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // still need error check - what if listSize is at capacity?
    // - check if listSize is equal to arrayCapacity. If yes, add capacity, don't insert.

    for(int i = listSize; i > 0; i--) {
        aList[i].setObjPos(aList[i - 1]); //this will shuffle all the elements towards the tail
    }

    aList[0].setObjPos(thisPos);

    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{

    aList[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{
    if(listSize == 0) {
        return;
    }
    for(int i = 0; i < listSize - 1; i++) {
        aList[i].setObjPos(aList[i + 1]); //this will shuffle all the elements towards the tail
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize == 0) {
        return;
    }
    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize - 1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}