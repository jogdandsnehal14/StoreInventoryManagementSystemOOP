//---------------------------------------------------------------------------
// File: buyTransaction.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for inventory class
// The inventory class is responsible for storing all the details of the inventory 
// Is a base class for all collectible items (coins, comics and sportsCards)
//---------------------------------------------------------------------------

#ifndef COLLECTIBLE_INVENTORY_
#define COLLECTIBLE_INVENTORY_

#include "inventory.h"

using namespace std;

class CollectibleInventory : public Inventory {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new CollectibleInventory object 
   // @pre none
   // @post creates a Inventory object
   CollectibleInventory();

   //------------------------------------------------------------------------
   // Gets the inventory year details
   // @pre valid input params
   // @post Gets the inventory year details
   // @returns The inventory year details
   int getYear() const;

   //------------------------------------------------------------------------
   // Sets the inventory year details
   // @pre valid input params
   // @post Sets the inventory year details
   // @param year The inventory year details
   void setYear(int year);

   //------------------------------------------------------------------------
   // Returns a string of the current inventory details
   // @pre none
   // @post displays the current inventory details
   // @returns the current inventory details as string
   virtual string toString() const = 0;

   //------------------------------------------------------------------------
   // Displays the current inventory details
   // @pre none
   // @post displays the current inventory details
   virtual void display() = 0;

   //------------------------------------------------------------------------
   // Overload == operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if both are inventory objects are equal
   // @param otherInventory The otherInventory to compare with
   virtual bool operator==(Inventory& otherInventory) = 0;

   //------------------------------------------------------------------------
   // Overload < operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is less than input inventory
   // @param otherInventory The otherInventory to compare with
   virtual bool operator<(Inventory& otherInventory) = 0;

   //------------------------------------------------------------------------
   // Overload > operator to check object comparison.
   // @pre The otherInventory is a valid inventory object
   // @post returns true if inventory is greater than input inventory
   // @param otherInventory The otherInventory to compare with
   virtual bool operator>(Inventory& otherInventory) = 0;

   //------------------------------------------------------------------------
   // The Inventory destructor 
   // virtual funtion to allow being overriden by the derived class
   // @pre none
   // @post the Inventory object is completely deleted 
   //    with corresponding memory deallocated
   virtual ~CollectibleInventory();

private:
   //------------------------------------------------------------------------
   // The Inventory year 
   int year;
};

#endif