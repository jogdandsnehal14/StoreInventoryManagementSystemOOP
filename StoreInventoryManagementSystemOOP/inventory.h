//---------------------------------------------------------------------------
// File: inventory.h
// Author: Snehal Jogdand
// Program 4: Object-oriented design
//
// DESCRIPTION:
// The header file for inventory class
// The inventory class is responsible for storing all the details of the inventory 
// Is a base class for all inventory items (collectible -> coins, comics and sportsCards)
//---------------------------------------------------------------------------

#ifndef INVENTORY_
#define INVENTORY_

#include <string>
#include <iostream>

using namespace std;

class Inventory {
public:
   //------------------------------------------------------------------------
   // The default constructor that creates a new Inventory object 
   // @pre none
   // @post creates a Inventory object
   Inventory();

   //------------------------------------------------------------------------
   // Gets the inventory id details
   // @pre valid input params
   // @post Gets the inventory id details
   // @returns The inventory id details
   string getId() const;

   //------------------------------------------------------------------------
   // Sets the inventory id details
   // @pre valid input params
   // @post Sets the inventory id details
   // @param inventoryId The inventory id details
   void setId(string inventoryId);

   //------------------------------------------------------------------------
   // Gets the inventory size details
   // @pre valid input params
   // @post Gets the inventory size details
   // @returns The inventory size details
   int getSize() const;

   //------------------------------------------------------------------------
   // Sets the inventory size details
   // @pre valid input params
   // @post Sets the inventory size details
   // @param inventorySize The inventory size details
   void setSize(int inventorySize);

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
   virtual ~Inventory();
private:
   //------------------------------------------------------------------------
   // The Inventory id 
   string inventoryId;

   //------------------------------------------------------------------------
   // The Inventory size - number of items of current inventory in store
   int inventorySize;
};

#endif