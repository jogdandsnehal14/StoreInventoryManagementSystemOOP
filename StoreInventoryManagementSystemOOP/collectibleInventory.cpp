//---------------------------------------------------------------------------
// File: buyTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for inventory class
// The inventory class is responsible for storing all the details of the inventory 
// Is a base class for all collectible items (coins, comics and sportsCards)
//---------------------------------------------------------------------------
#include "collectibleInventory.h"

//------------------------------------------------------------------------
// The default constructor that creates a new CollectibleInventory object 
// @pre none
// @post creates a Inventory object
CollectibleInventory::CollectibleInventory() : year(0000) {
}

//------------------------------------------------------------------------
// Gets the inventory year details
// @pre valid input params
// @post Gets the inventory year details
// @returns The inventory year details
int CollectibleInventory::getYear() const {
   return year;
}

//------------------------------------------------------------------------
// Sets the inventory year details
// @pre valid input params
// @post Sets the inventory year details
// @param year The inventory year details
void CollectibleInventory::setYear(int year) {
   this->year = year;
}

//------------------------------------------------------------------------
// The Inventory destructor 
// virtual funtion to allow being overriden by the derived class
// @pre none
// @post the Inventory object is completely deleted 
//    with corresponding memory deallocated
CollectibleInventory::~CollectibleInventory() {
}