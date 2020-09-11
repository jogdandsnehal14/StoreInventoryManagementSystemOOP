//---------------------------------------------------------------------------
// File: inventory.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The class file for inventory class
// The inventory class is responsible for storing all the details of the inventory 
// Is a base class for all inventory items (collectible -> coins, comics and sportsCards)
//---------------------------------------------------------------------------

#include "inventory.h"

//------------------------------------------------------------------------
// The default constructor that creates a new Inventory object 
// @pre none
// @post creates a Inventory object
Inventory::Inventory() : inventoryId("invalid"), inventorySize(-1) {
}

//------------------------------------------------------------------------
// Gets the inventory id details
// @pre valid input params
// @post Gets the inventory id details
// @returns The inventory id details
string Inventory::getId() const {
   return inventoryId;
}

//------------------------------------------------------------------------
// Sets the inventory id details
// @pre valid input params
// @post Sets the inventory id details
// @param inventoryId The inventory id details
void Inventory::setId(string inventoryId) {
   this->inventoryId = inventoryId;
}

//------------------------------------------------------------------------
 // Gets the inventory size details
 // @pre valid input params
 // @post Gets the inventory size details
 // @returns The inventory size details
int Inventory::getSize() const {
   return inventorySize;
}

//------------------------------------------------------------------------
// Sets the inventory size details
// @pre valid input params
// @post Sets the inventory size details
// @param inventorySize The inventory size details
void Inventory::setSize(int inventorySize) {
   this->inventorySize = inventorySize;
}

//------------------------------------------------------------------------
// The Inventory destructor 
// virtual funtion to allow being overriden by the derived class
// @pre none
// @post the Inventory object is completely deleted 
//    with corresponding memory deallocated
Inventory::~Inventory() {
}