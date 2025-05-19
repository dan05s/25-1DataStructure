#include "DList.h"

int main() {
    DList myList;

    myList.Insert("apple");
    myList.Insert("banana");
    myList.Insert("cherry");

    myList.Print();

    myList.Invert();
    myList.Print();

    myList.Delete("banana");
    myList.Print();

    return 0;
}