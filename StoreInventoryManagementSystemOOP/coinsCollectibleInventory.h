//---------------------------------------------------------------------------
// File: buyTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for inventory class
// The inventory class is responsible for storing all the details of the coins inventory 
//---------------------------------------------------------------------------

#ifndef COINS_COLLECTIBLE_INVENTORY_
#define COINS_COLLECTIBLE_INVENTORY_

#include "collectibleInventory.h"
#include <string>

using namespace std;

class CoinsCollectibleInventory : public CollectibleInventory {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new CoinsCollectibleInventory object 
   // @pre none
   // @post creates a Inventory object
   CoinsCollectibleInventory();

   //------------------------------------------------------------------------
   // The copy constructor that deep copies the provided Inventory object
   // @pre otherInventory should be a valid Inventory object
   // @post creates a deep copy of give Inventory object
   // @param otherInventory The Inventory object to be copied
   CoinsCollectibleInventory(const CoinsCollectibleInventory& otherInventory);

   //------------------------------------------------------------------------
   // Sets the sport card grade details
   // @pre valid input params
   // @post Sets the sport cards grade details
   // @param grade The grade details
   void setGrade(int grade);

   //------------------------------------------------------------------------
   // Sets the inventory type details
   // @pre valid input params
   // @post Sets the inventory type details
   // @param type The inventory type details
   void setType(string type);
   
   //------------------------------------------------------------------------
   // Returns a string of the current inventory details
   // @pre none
   // @post displays the current inventory details
   // @returns the current inventory details as string
   string toString() const;

   //------------------------------------------------------------------------
   // Displays the current inventory details
   // @pre none
   // @post displays the current inventory details
   void display();
   
   //------------------------------------------------------------------------
   // Overload == operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if both are inventory objects are equal
   // @param otherInventory The otherInventory to compare with
   bool operator==(Inventory& otherInventory);

   //------------------------------------------------------------------------
   // Overload < operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is less than input inventory
   // @param otherInventory The otherInventory to compare with
   bool operator<(Inventory& otherInventory);

   //------------------------------------------------------------------------
   // Overload > operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is greater than input inventory
   // @param otherInventory The otherInventory to compare with
   bool operator>(Inventory& otherInventory);

   //------------------------------------------------------------------------
   // The CoinsCollectibleInventory destructor 
   // virtual funtion to allow being overriden by the derived class
   // @pre none
   // @post the Inventory object is completely deleted 
   //    with corresponding memory deallocated
   ~CoinsCollectibleInventory();

private:
   //------------------------------------------------------------------------
   // The Inventory grade 
   int grade;

   //------------------------------------------------------------------------
   // The Inventory type 
   string type;
};

#endif